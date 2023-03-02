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

#include <iostream>
#include <opencv2/opencv.hpp>  
#include <opencv2/imgproc/imgproc.hpp> 
using namespace cv;
using namespace std;


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

            std::vector<unsigned char> buffer;
            if(!cv::imencode(".jpg", image, buffer)){
                printf("Image encoding failed");
            }
            hello_.size(buffer.size());
            hello_.picture(buffer);

            imshow("image_sento", image);
            if(cv::waitKey(100) == 'q') {
                break;
            }

            if (publish())
            {
                samples_sent++;
                // std::cout << "Message: " << hello_.message() << " with index: " << hello_.index()
                //             << " SENT" << std::endl;
                std::cout << "Message " << hello_.message() << " " << hello_.index() << " RECEIVED" << "Size " << hello_.picture().size()<< std::endl;
            }
            // std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            // std::this_thread::sleep_for(std::chrono::milliseconds(100));
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
