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
 * @file HelloWorldSubscriber.cpp
 *
 */

#include "HelloWorldPubSubTypes.h"

#include <fastdds/dds/domain/DomainParticipantFactory.hpp>
#include <fastdds/dds/domain/DomainParticipant.hpp>
#include <fastdds/dds/topic/TypeSupport.hpp>
#include <fastdds/dds/subscriber/Subscriber.hpp>
#include <fastdds/dds/subscriber/DataReader.hpp>
#include <fastdds/dds/subscriber/DataReaderListener.hpp>
#include <fastdds/dds/subscriber/qos/DataReaderQos.hpp>
#include <fastdds/dds/subscriber/SampleInfo.hpp>

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

class HelloWorldSubscriber
{
private:

    DomainParticipant* participant_;

    Subscriber* subscriber_;

    DataReader* reader_;

    Topic* topic_;

    TypeSupport type_;

    class SubListener : public DataReaderListener
    {
    public:

        SubListener()
            : samples_(0)
        {
        }

        ~SubListener() override
        {
        }

        void on_subscription_matched(
                DataReader*,
                const SubscriptionMatchedStatus& info) override
        {
            if (info.current_count_change == 1)
            {
                std::cout << "Subscriber matched." << std::endl;
            }
            else if (info.current_count_change == -1)
            {
                std::cout << "Subscriber unmatched." << std::endl;
            }
            else
            {
                std::cout << info.current_count_change
                        << " is not a valid value for SubscriptionMatchedStatus current count change" << std::endl;
            }
        }

        void on_data_available(
                DataReader* reader) override
        {
            SampleInfo info;
            if (reader->take_next_sample(&hello_, &info) == ReturnCode_t::RETCODE_OK)
            {
                if (info.valid_data)
                {
                    samples_++;
                    std::cout << "Message: " << hello_.message() << " with index: " << hello_.index()
                                << " RECEIVED." << std::endl;
                    // for (auto e : hello_.file_path()) {//helloworld
                    //     std::cout << e;
                    // }
                    // std::cout << '\n';

                    for (int i = 0; i < 10; i++) 
                        std::cout << hello_.image_data().at(i) << ' ';
                    std::cout<<std::endl;
                }
            }
        }

        HelloWorld hello_;

        std::atomic_int samples_;

    } listener_;

public:

    HelloWorldSubscriber()
        : participant_(nullptr)
        , subscriber_(nullptr)
        , topic_(nullptr)
        , reader_(nullptr)
        , type_(new HelloWorldPubSubType())
    {
    }

    virtual ~HelloWorldSubscriber()
    {
        if (reader_ != nullptr)
        {
            subscriber_->delete_datareader(reader_);
        }
        if (topic_ != nullptr)
        {
            participant_->delete_topic(topic_);
        }
        if (subscriber_ != nullptr)
        {
            participant_->delete_subscriber(subscriber_);
        }
        DomainParticipantFactory::get_instance()->delete_participant(participant_);
    }

    //!Initialize the subscriber
    bool init()
    {
        DomainParticipantQos participantQos;
        // add for video begin
        // Increase the receiving buffer size
        participantQos.transport().listen_socket_buffer_size = 12582912;
        participantQos.wire_protocol().builtin.discovery_config.leaseDuration = eprosima::fastrtps::c_TimeInfinite;
        // add for video end
        participantQos.name("Participant_subscriber");
        participant_ = DomainParticipantFactory::get_instance()->create_participant(0, participantQos);

        if (participant_ == nullptr)
        {
            return false;
        }

        // Register the Type
        type_.register_type(participant_);

        // Create the subscriptions Topic
        topic_ = participant_->create_topic("HelloWorldTopic", "HelloWorld", TOPIC_QOS_DEFAULT);

        if (topic_ == nullptr)
        {
            return false;
        }

        // Create the Subscriber
        subscriber_ = participant_->create_subscriber(SUBSCRIBER_QOS_DEFAULT, nullptr);

        if (subscriber_ == nullptr)
        {
            return false;
        }

        // Create the DataReader
        // add for video begin

        // - Multimedia feed
        // Audio and Video transmission have a common characteristic: Having a stable, high datarate feed is more important than having a 100% lossless transmission.
        // Reliability: Best-Effort. We want to have a fast transmission. If a sample is lost, it can be recovered via error-correcting algorithms.
        // Durability: Volatile. We do not mind data from the past, we want to stream what is happening in the present.
        // History: Keep-Last with Low Depth. Once displayed or recorded on the receiving application, they are not needed in the History.
        // note: In the case of video, depth can be as low as 1. A missing sample of a 50 frames per second stream represents virtually no information loss. 

        DataReaderQos rqos;
        rqos.history().kind = KEEP_LAST_HISTORY_QOS;
        rqos.durability().kind = VOLATILE_DURABILITY_QOS;
        rqos.reliability().kind = BEST_EFFORT_RELIABILITY_QOS;
        rqos.history().depth =  1;
        // add for video end
        reader_ = subscriber_->create_datareader(topic_, rqos, &listener_);

        if (reader_ == nullptr)
        {
            return false;
        }

        return true;
    }

    //!Run the Subscriber
    void run(
        uint32_t samples)
    {
        while(1)//(listener_.samples_ < samples)
        {
            // std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        }
    }
};

int main(
        int argc,
        char** argv)
{
    std::cout << "Starting subscriber." << std::endl;
    int samples = 10;

    HelloWorldSubscriber* mysub = new HelloWorldSubscriber();

    // send video begin
    int m_sockClient;
	if ((m_sockClient = socket(AF_INET, SOCK_DGRAM, 0)) < 0)    //创建socket句柄，采用UDP协议
	{
		printf("create socket error: %s(errno: %d)\n", strerror(errno), errno);
		return -1;
	}
	sockaddr_in m_servaddr;
	memset(&m_servaddr, 0, sizeof(m_servaddr));  //初始化结构体
	m_servaddr.sin_family = AF_INET;           //设置通信方式
	m_servaddr.sin_port = htons(PORT_out);         //设置端口号
    m_servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    // int len = sizeof(m_servaddr);

	bind(m_sockClient, (sockaddr*)&m_servaddr, sizeof(m_servaddr));//绑定套接字
	// Mat image;

	int imgSize = 480*640*3;
    Mat image = Mat::zeros(480, 640, CV_8UC3);
    // uchar *iptr = image.data;


	unsigned char buf[imgSize+1];

	struct sockaddr_in addr_client;
	socklen_t len = sizeof(addr_client);
	memset(&addr_client, 0, sizeof(addr_client));
	int key;
    //send video end

    if(mysub->init())
    {
        // mysub->run(static_cast<uint32_t>(samples));

        // send video begin
        while (true)
        {
            std::vector<uchar> decode;

            int n = recvfrom(m_sockClient, buf, imgSize, 0,(struct sockaddr *)&addr_client, (socklen_t *)&len);//接受缓存
            std::cout << n << std::endl;
            int pos = 0;
            while (pos < n)
            {
                decode.push_back(buf[pos++]);//存入vector
            }
            buf[n] = 0;
            image = imdecode(decode, IMREAD_COLOR);//图像解码
            imshow("image_recvfrom", image);
            if (key = waitKey(100) >= 0) break;
            // waitKey(5);
        }
        //send video end

    }

    delete mysub;
    return 0;
}
