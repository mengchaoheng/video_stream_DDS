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

	while (true)
	{
		std::vector<uchar> decode;

		int n = recvfrom(m_sockClient, buf, imgSize, 0,(struct sockaddr *)&addr_client, (socklen_t *)&len);//接受缓存
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
	return 0;
}


