#include "stdafx.h"


#include<Winsock2.h>
#include<stdio.h>
#include<stdlib.h>
#include "string.h"
#define PORT 5000
#define BUFFER 1024
#pragma comment(lib,"WSOCK32.lib")   //�����
int           port=PORT;
WSADATA       wsaData;
SOCKET        sListen,sAccept;
//�ͻ���ַ����
int           iLen;    
//�������ݳ���
int           iSend;               
//��Ҫ���͵���Ϣ   
char          buf[BUFFER]; 
//���������ͻ��ĵ�ַ
struct sockaddr_in  serv,cliet;



DWORD WINAPI RecvThread(LPVOID lpParam)
{
 //static int i=0;
 //printf("%d",i++);
 while(1)
 {
 
  //�ӷ�������������
  iLen=recv(sAccept,buf,sizeof(buf),0); 
  if(iLen==0)
   return 0;
  else if(iLen==SOCKET_ERROR)
  {
   printf("recv()failed:%d\n",WSAGetLastError());
   return 0;
  }
  else
  { 
   //printf("Client Send The Sum Back is:");
    printf("%s",buf);
  }
 }  
 
  return 0;
} 



int main(int argc, char* argv[])
{
 if(WSAStartup(MAKEWORD(2,2),&wsaData)!=0)
 {
  printf("Winsock load failed\n");
  //return;
 }
 //�����׽���
 sListen=socket(AF_INET,SOCK_STREAM,0);  
 if(sListen==INVALID_SOCKET)
 {
  printf("socket failed:%d\n",WSAGetLastError());
  return;
 }
 //������������ַ
 serv.sin_family=AF_INET;  
 //��һ��˫�ֽ������ֽ�˳�������ת��Ϊ�����ֽ�˳��
 serv.sin_port=htons(port);   
 //�����ֽ������ֽ�˳��ת��Ϊ�����ֽ�˳��INADDR_ANYΪϵͳָ����IP��ַ
 serv.sin_addr.s_addr=htonl(INADDR_ANY);
 if(bind(sListen,(LPSOCKADDR)&serv,sizeof(serv))==SOCKET_ERROR)
 {
  printf("bind()failed:%d\n",WSAGetLastError());
  return;
 }
 //�������״̬
 if(listen(sListen,5)==SOCKET_ERROR) 
 {
  printf("listen()failed:%d\n",WSAGetLastError());
  return;
 }
 //��ʼ���ͻ���ַ����
 iLen=sizeof(cliet);  
 //����ѭ�����ȴ��ͻ���������
 sAccept=accept(sListen,(struct sockaddr*)&cliet,&iLen);


 HANDLE hThread;
  hThread=CreateThread(NULL,NULL,RecvThread,0,0,0);
 printf("InPut Data:");
 while(1)      
 {
  if(sAccept==INVALID_SOCKET)
  {
   printf("accept()failed:%d\n",WSAGetLastError());
   break;
  }
 
  //printf("accepted client IP:[%s],port:[%d]\n",inet_ntoa(cliet.sin_addr),ntohs(cliet.sin_port));
  gets(buf);
  //�����ӵĿͻ�������Ϣ
  iSend=send(sAccept,buf,sizeof(buf),0); 
  if(iSend==SOCKET_ERROR)
  {
   printf("send()failed:%d\n",WSAGetLastError());
   break;
  }
  printf("Client Send The Sum Back is:");
 }
  closesocket(sAccept);
 closesocket(sListen);
 WSACleanup();
}