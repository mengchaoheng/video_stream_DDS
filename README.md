# video_stream_DDS
This is a demo of real-time video transmission through Fast DDS, which have been test on ubuntu20.04. The effect of this demo is to acquire the image from the camera and transmit it through dds, and then display it.

This demo is modified based on 
server/client of [opencv_tcp_udp_video_test](https://github.com/mengchaoheng/opencv_tcp_udp_video_test.git) and [publish/subscribe](https://fast-dds.docs.eprosima.com/en/latest/fastddsgen/pubsub_app/pubsub_app.html#) 
of docs of Fast DDS-Gen, and the configuration of DDS also refers to [SampleConfig_Multimedia](https://github.com/eProsima/Fast-DDS/tree/master/examples/cpp/dds/SampleConfig_Multimedia), which is the examples of Fast-DDS.

```
Note:
As a DDS application examples, Audio and Video transmission have a common characteristic: Having a stable, high datarate feed is more important than 
having a 100% lossless transmission:

- Reliability: Best-Effort. We want to have a fast transmission. If a sample is lost, it can be recovered via error-correcting algorithms.

- Durability: Volatile. We do not mind data from the past, we want to stream what is happening in the present.

- History: Keep-Last with Low Depth. Once displayed or recorded on the receiving application, they are not needed in the History.

- note: In the case of video, depth can be as low as 1. A missing sample of a 50 frames per second stream represents virtually no information loss. 
```

#  Prerequisites
- install [opencv4.7.0](https://docs.opencv.org/4.7.0/d7/d9f/tutorial_linux_install.html)

- install [fast DDS and Fast DDS-Gen](https://fast-dds.docs.eprosima.com/en/latest/installation/sources/sources_linux.html#cmake-installation), note that CMake installation locally is good. 

# build
cd to `workspace_DDSHelloWorld/build` path and:
```
$ cmake .. && cmake --build . -j8
```
If need to update idl file, cd to `workspace_DDSHelloWorld/src` and run:
```
fastddsgen -replace HelloWorld.idl
```
# run 
In build path, run
```
./DDSHelloWorldSubscriber
```
Open another terminal, which can be another computer in the same LAN, run cd to `workspace_DDSHelloWorld/build` and then run:
```
./DDSHelloWorldPublisher
```
