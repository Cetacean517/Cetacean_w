/*
struct WSAData {
	WORD wVersion;									// 将使用的Winsock 版本号
	WORD wHighVersion;								// 载入的Winsock动态库支持的最高版本，高字节代表次版本，低字节代表主版本
	char szDescription[WSADESCRIPTION_LEN + 1];		// 特定版本的Winsock设置
	char szSystemStatus[WSASYSSTATUS_LEN + 1];		// 特定版本的Winsock设置
	unsigned short iMaxSockets;						// 最大数量的并分Sockets,其值依赖于可使用的硬件资源
	unsigned short iMaxUdpDg;						// 数据报的最大长度
	char FAR* lpVendorInfo;							// 为Winsock实现而保留的制造商信息
};
*/

#include<WINSOCK2.H> //socket头文件 
#include<STDIO.H>  
#include<iostream>  
#include<cstring>  
#include <string>
#include<WS2tcpip.h>
using namespace std;
#pragma comment(lib, "ws2_32.lib")//加载socket 
int main()
{
	//初始化WSA windows自带的socket，使用2.2版本
	WORD sockVersion = MAKEWORD(2, 2);
	WSADATA data;			// 存放windows socket初始化信息
	if (WSAStartup(sockVersion, &data) != 0)
	{
		return 0;
	}

	//创建客户端套接字
	while (true)
	{
		// 1. 创建Socket()
		SOCKET sclient = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); 
			// AF_INET :ipv4, SOCK_STREAM: socket类型, IPPROTO_TCP: TCP协议
		if (sclient == INVALID_SOCKET)
		{
			printf("invalid socket!");
			return 0;
		}

		sockaddr_in serAddr;
		serAddr.sin_family = AF_INET;		// 地址族
		serAddr.sin_port = htons(8888);		// 端口号，高低次序转换
		inet_pton(AF_INET, "127.0.0.1", (void*)&serAddr.sin_addr.S_un.S_addr);
			// 将点分十进制的ip地址转化为用于网络传输的数值格式
			// 返回值：若成功则为1，若输入不是有效的表达式则为0，若出错则为 - 1


		// 2. 建立连接
		if (connect(sclient, (sockaddr*)&serAddr, sizeof(serAddr)) == SOCKET_ERROR) //与指定IP地址和端口的服务端连接
		{
			printf("connect error !");
			closesocket(sclient);
			return 0;
		}

		// 3. 发送数据
		printf("\n");
		printf("输入你想传输的数据： \n");
		string data;
		cin >> data;
		const char* sendData2;
		sendData2 = data.c_str(); //string转const char*
		send(sclient, sendData2, strlen(sendData2), 0);

		// 4. 接受数据
		char recData[255];
		int ret = recv(sclient, recData, 255, 0);
		if (ret > 0) {
			recData[ret] = 0x00;
			printf(recData);
		}
		closesocket(sclient);

	}

	// 5. 结束调用
	WSACleanup();
	return 0;

}

//Client_demo_TCP