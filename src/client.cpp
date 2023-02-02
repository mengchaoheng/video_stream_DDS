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
int main(int argc, char** argv)
{

	int m_sockClient;
	if ((m_sockClient = socket(AF_INET, SOCK_DGRAM, 0)) < 0)    //创建socket句柄，采用UDP协议
	{
		printf("create socket error: %s(errno: %d)\n", strerror(errno), errno);
		return -1;
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
	while (true)
	{
		capture >> image;//读入图片
		if (image.empty())    //如果照片为空则退出
		{
			printf("empty image\n\n");
			return -1;
		}
		
		std::vector<uchar> data_encode;
		std::vector<int> quality;
		quality.push_back(IMWRITE_JPEG_QUALITY);
		quality.push_back(30);//进行50%的压缩
		imencode(".jpg", image, data_encode,quality);//将图像编码

		//char encodeImg[426672];

		int nSize = data_encode.size();
                
        unsigned char *encodeImg = new unsigned char[nSize];

        // printf("%d\n", nSize);

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
	}
	return 0;
}


