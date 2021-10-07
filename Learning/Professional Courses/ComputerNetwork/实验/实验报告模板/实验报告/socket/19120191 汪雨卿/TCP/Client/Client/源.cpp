/*
struct WSAData {
	WORD wVersion;									// ��ʹ�õ�Winsock �汾��
	WORD wHighVersion;								// �����Winsock��̬��֧�ֵ���߰汾�����ֽڴ���ΰ汾�����ֽڴ������汾
	char szDescription[WSADESCRIPTION_LEN + 1];		// �ض��汾��Winsock����
	char szSystemStatus[WSASYSSTATUS_LEN + 1];		// �ض��汾��Winsock����
	unsigned short iMaxSockets;						// ��������Ĳ���Sockets,��ֵ�����ڿ�ʹ�õ�Ӳ����Դ
	unsigned short iMaxUdpDg;						// ���ݱ�����󳤶�
	char FAR* lpVendorInfo;							// ΪWinsockʵ�ֶ���������������Ϣ
};
*/

#include<WINSOCK2.H> //socketͷ�ļ� 
#include<STDIO.H>  
#include<iostream>  
#include<cstring>  
#include <string>
#include<WS2tcpip.h>
using namespace std;
#pragma comment(lib, "ws2_32.lib")//����socket 
int main()
{
	//��ʼ��WSA windows�Դ���socket��ʹ��2.2�汾
	WORD sockVersion = MAKEWORD(2, 2);
	WSADATA data;			// ���windows socket��ʼ����Ϣ
	if (WSAStartup(sockVersion, &data) != 0)
	{
		return 0;
	}

	//�����ͻ����׽���
	while (true)
	{
		// 1. ����Socket()
		SOCKET sclient = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); 
			// AF_INET :ipv4, SOCK_STREAM: socket����, IPPROTO_TCP: TCPЭ��
		if (sclient == INVALID_SOCKET)
		{
			printf("invalid socket!");
			return 0;
		}

		sockaddr_in serAddr;
		serAddr.sin_family = AF_INET;		// ��ַ��
		serAddr.sin_port = htons(8888);		// �˿ںţ��ߵʹ���ת��
		inet_pton(AF_INET, "127.0.0.1", (void*)&serAddr.sin_addr.S_un.S_addr);
			// �����ʮ���Ƶ�ip��ַת��Ϊ�������紫�����ֵ��ʽ
			// ����ֵ�����ɹ���Ϊ1�������벻����Ч�ı��ʽ��Ϊ0����������Ϊ - 1


		// 2. ��������
		if (connect(sclient, (sockaddr*)&serAddr, sizeof(serAddr)) == SOCKET_ERROR) //��ָ��IP��ַ�Ͷ˿ڵķ��������
		{
			printf("connect error !");
			closesocket(sclient);
			return 0;
		}

		// 3. ��������
		printf("\n");
		printf("�������봫������ݣ� \n");
		string data;
		cin >> data;
		const char* sendData2;
		sendData2 = data.c_str(); //stringתconst char*
		send(sclient, sendData2, strlen(sendData2), 0);

		// 4. ��������
		char recData[255];
		int ret = recv(sclient, recData, 255, 0);
		if (ret > 0) {
			recData[ret] = 0x00;
			printf(recData);
		}
		closesocket(sclient);

	}

	// 5. ��������
	WSACleanup();
	return 0;

}

//Client_demo_TCP