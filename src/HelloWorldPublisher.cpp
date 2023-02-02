// Copyright 2016 Proyectos y Sistemas de Mantenimiento SL (eProsima).
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

/**
 * @file HelloWorldPublisher.cpp
 *
 */

#include "HelloWorldPubSubTypes.h"

#include <fastdds/dds/domain/DomainParticipantFactory.hpp>
#include <fastdds/dds/domain/DomainParticipant.hpp>
#include <fastdds/dds/topic/TypeSupport.hpp>
#include <fastdds/dds/publisher/Publisher.hpp>
#include <fastdds/dds/publisher/DataWriter.hpp>
#include <fastdds/dds/publisher/DataWriterListener.hpp>

// send video begin
#include <unistd.h>//Linux系统下网络通讯的头文件集合
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <malloc.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/ioctl.h>
#include <stdarg.h>
#include <fcntl.h>
#include <fcntl.h>
#include <iostream>
#include <opencv2/opencv.hpp>  
#include <opencv2/imgproc/imgproc.hpp> 
using namespace cv;
using namespace std;

enum
{
	PORT_in = 8888,
	PORT_out = 8889
};
//send video end

using namespace eprosima::fastdds::dds;

class HelloWorldPublisher
{
private:

    HelloWorld hello_;

    DomainParticipant* participant_;

    Publisher* publisher_;

    Topic* topic_;

    DataWriter* writer_;

    TypeSupport type_;

    class PubListener : public DataWriterListener
    {
    public:

        PubListener()
            : matched_(0)
        {
        }

        ~PubListener() override
        {
        }

        void on_publication_matched(
                DataWriter*,
                const PublicationMatchedStatus& info) override
        {
            if (info.current_count_change == 1)
            {
                matched_ = info.total_count;
                std::cout << "Publisher matched." << std::endl;
            }
            else if (info.current_count_change == -1)
            {
                matched_ = info.total_count;
                std::cout << "Publisher unmatched." << std::endl;
            }
            else
            {
                std::cout << info.current_count_change
                        << " is not a valid value for PublicationMatchedStatus current count change." << std::endl;
            }
        }

        std::atomic_int matched_;

    } listener_;

public:

    HelloWorldPublisher()
        : participant_(nullptr)
        , publisher_(nullptr)
        , topic_(nullptr)
        , writer_(nullptr)
        , type_(new HelloWorldPubSubType())
    {
    }

    virtual ~HelloWorldPublisher()
    {
        if (writer_ != nullptr)
        {
            publisher_->delete_datawriter(writer_);
        }
        if (publisher_ != nullptr)
        {
            participant_->delete_publisher(publisher_);
        }
        if (topic_ != nullptr)
        {
            participant_->delete_topic(topic_);
        }
        DomainParticipantFactory::get_instance()->delete_participant(participant_);
    }

    //!Initialize the publisher
    bool init()
    {
        hello_.index(0);
        hello_.message("HelloWorld");
        
        hello_.file_path().fill('A');
        // std::array<char, 100> h{ "mmmmmmmmm" };
        // std::array<char, 100> a{ "apple" };
        // a = h;
        // hello_.file_path()=h;

        DomainParticipantQos participantQos;
        participantQos.name("Participant_publisher");
        // add for video begin
        // Increase the sending buffer size
        participantQos.transport().send_socket_buffer_size = 12582912;
        // add for video end
        participant_ = DomainParticipantFactory::get_instance()->create_participant(0, participantQos);

        if (participant_ == nullptr)
        {
            return false;
        }

        // Register the Type
        type_.register_type(participant_);

        // Create the publications Topic
        topic_ = participant_->create_topic("HelloWorldTopic", "HelloWorld", TOPIC_QOS_DEFAULT);

        if (topic_ == nullptr)
        {
            return false;
        }

        // Create the Publisher
        publisher_ = participant_->create_publisher(PUBLISHER_QOS_DEFAULT, nullptr);

        if (publisher_ == nullptr)
        {
            return false;
        }

        // Create the DataWriter
        //add for video begin

        // - Multimedia feed
        // Audio and Video transmission have a common characteristic: Having a stable, high datarate feed is more important than having a 100% lossless transmission.
        // Reliability: Best-Effort. We want to have a fast transmission. If a sample is lost, it can be recovered via error-correcting algorithms.
        // Durability: Volatile. We do not mind data from the past, we want to stream what is happening in the present.
        // History: Keep-Last with Low Depth. Once displayed or recorded on the receiving application, they are not needed in the History.
        // note: In the case of video, depth can be as low as 1. A missing sample of a 50 frames per second stream represents virtually no information loss. 

        DataWriterQos wqos;
        wqos.history().kind = KEEP_LAST_HISTORY_QOS;
        wqos.durability().kind = VOLATILE_DURABILITY_QOS;
        wqos.reliability().kind = BEST_EFFORT_RELIABILITY_QOS;
        wqos.history().depth =  1;
        writer_ = publisher_->create_datawriter(topic_, wqos, &listener_);
        //add for video end
        // writer_ = publisher_->create_datawriter(topic_, DATAWRITER_QOS_DEFAULT, &listener_);
        


        if (writer_ == nullptr)
        {
            return false;
        }
        return true;
    }

    //!Send a publication
    bool publish()
    {
        if (listener_.matched_ > 0)
        {
            hello_.index(hello_.index() + 1);
            writer_->write(&hello_);
            return true;
        }
        return false;
    }

    //!Run the Publisher
    void run(
            uint32_t samples)
    {
        // send video begin
        int m_sockClient;
        if ((m_sockClient = socket(AF_INET, SOCK_DGRAM, 0)) < 0)    //创建socket句柄，采用UDP协议
        {
            printf("create socket error: %s(errno: %d)\n", strerror(errno), errno);
            return;
        }
        sockaddr_in m_servaddr;
        memset(&m_servaddr, 0, sizeof(m_servaddr));  //初始化结构体
        m_servaddr.sin_family = AF_INET;           //设置通信方式
        // m_servaddr.sin_port = htons(PORT_in);         //设置端口号
        m_servaddr.sin_port   = htons(PORT_out);
        m_servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
        //m_servaddr.sin_port = htons(8888);//设置需要发送的IP和端口号

        // bind(m_sockClient, (sockaddr*)&m_servaddr, sizeof(m_servaddr));//绑定端口号
        // VideoCapture capture;//(cv::String("/home/parallels/Downloads/icra.mp4"));//打开摄像头    
        // capture.open(0); //打开相机，电脑自带摄像头一般编号为0，外接摄像头编号为1，主要是在设备管理器中查看自己摄像头的编号。
        // capture.set(CAP_PROP_FRAME_WIDTH, 1920);
        // capture.set(CAP_PROP_FRAME_HEIGHT, 1080);
        // capture.set(CAP_PROP_FOURCC, VideoWriter::fourcc('M', 'J', 'P', 'G'));
        VideoCapture capture(0);
        capture.set(CAP_PROP_FRAME_WIDTH, 640);
        capture.set(CAP_PROP_FRAME_HEIGHT, 480);
        // Mat image;

        Mat image;
        image = Mat::zeros(640, 480, CV_8UC3);
        int imgSize = image.cols*image.rows*3;
        //send video end

        
        uint32_t samples_sent = 0;
        while (1)//(samples_sent < samples)
        {
            // sned video begin
            capture >> image;//读入图片
            if (image.empty())    //如果照片为空则退出
            {
                printf("empty image\n\n");
                return;
            }
            
            std::vector<uchar> data_encode;
            std::vector<int> quality;
            quality.push_back(IMWRITE_JPEG_QUALITY);
            quality.push_back(30);//进行50%的压缩
            imencode(".jpg", image, data_encode,quality);//将图像编码

            //char encodeImg[426672];

            int nSize = data_encode.size();

            for (int i = 0; i < nSize; ++i) {
                hello_.image_data().push_back(data_encode[i]);
            }
            // for (vector<int>::iterator iterator = hello_.image_data().begin(); iterator != hello_.image_data().end(); iterator++) {
            //     cout << *iterator << endl;
            // }
            // for (std::vector<char>::const_iterator i = hello_.image_data().begin(); i != hello_.image_data().end(); ++i) {
            //     std::cout << *i << ' ';
            // }
            // << endl;
            // for (auto i = hello_.image_data().begin(); i != hello_.image_data().end(); i++) {
            //     std::cout << *i << ' ';
            // }
            for (int i = 0; i < 10; i++) 
                std::cout << hello_.image_data().at(i) << ' ';
            std::cout<<std::endl;
                    
            unsigned char *encodeImg = new unsigned char[nSize];

            printf("%d\n", nSize);

            for (int i = 0; i < nSize; i++)
            {
                encodeImg[i] = data_encode[i];
                // std::cout << data_encode[i] << std::endl;
            }
            // m_servaddr.sin_family = AF_INET;
            // m_servaddr.sin_port   = htons(PORT_out);
            // m_servaddr.sin_addr.s_addr = htonl(INADDR_ANY);        
            // printf("%d\n", encodeImg[100]);
            // char *str = "0123456789"; printf("%.6s\n", str + 1); 
            // printf("%10.10d\n", encodeImg); 
            // cout << encodeImg<<endl;
            unsigned char file_path[1024]="Do not go gentle into that good night";
            // 会将字符数组当作字符串来输出
            // Notice: 不是输出数组的首地址
            
            // file_path 是一个 char 的地址 即 char* , 所以打印整个 字符串
            // std::cout << file_path << std::endl;

            sendto(m_sockClient, encodeImg, nSize, 0, (const sockaddr*)& m_servaddr, sizeof(m_servaddr));
            memset(&encodeImg, 0, sizeof(encodeImg));  //初始化结构体
            imshow("image_sento", image);
            if(cv::waitKey(100) == 'q') {
                break;
            }

            // send video begin


            if (publish())
            {
                samples_sent++;
                std::cout << "Message: " << hello_.message() << " with index: " << hello_.index()
                            << " SENT" << std::endl;
                // for (auto e : hello_.file_path()) {//helloworld
                //     std::cout << e;
                // }
                // std::cout << '\n';
            }
            // std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        }
    }
};

int main(
        int argc,
        char** argv)
{
    std::cout << "Starting publisher." << std::endl;
    int samples = 10;

    HelloWorldPublisher* mypub = new HelloWorldPublisher();
    if(mypub->init())
    {
        
        mypub->run(static_cast<uint32_t>(samples));
    }

    delete mypub;
    return 0;
}
