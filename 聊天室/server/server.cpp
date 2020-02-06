#include "stdafx.h"


#include<Winsock2.h>
#include<stdio.h>
#include<stdlib.h>
#include "string.h"
#define PORT 5000
#define BUFFER 1024
#pragma comment(lib,"WSOCK32.lib")   //必须的
int           port=PORT;
WSADATA       wsaData;
SOCKET        sListen,sAccept;
//客户地址长度
int           iLen;    
//发送数据长度
int           iSend;               
//需要发送的信息   
char          buf[BUFFER]; 
//服务器、客户的地址
struct sockaddr_in  serv,cliet;



DWORD WINAPI RecvThread(LPVOID lpParam)
{
 //static int i=0;
 //printf("%d",i++);
 while(1)
 {
 
  //从服务器接收数据
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
 //创建套接字
 sListen=socket(AF_INET,SOCK_STREAM,0);  
 if(sListen==INVALID_SOCKET)
 {
  printf("socket failed:%d\n",WSAGetLastError());
  return;
 }
 //建立服务器地址
 serv.sin_family=AF_INET;  
 //把一个双字节主机字节顺序的数据转换为网络字节顺序
 serv.sin_port=htons(port);   
 //把四字节主机字节顺序转换为网络字节顺序，INADDR_ANY为系统指定的IP地址
 serv.sin_addr.s_addr=htonl(INADDR_ANY);
 if(bind(sListen,(LPSOCKADDR)&serv,sizeof(serv))==SOCKET_ERROR)
 {
  printf("bind()failed:%d\n",WSAGetLastError());
  return;
 }
 //进入监听状态
 if(listen(sListen,5)==SOCKET_ERROR) 
 {
  printf("listen()failed:%d\n",WSAGetLastError());
  return;
 }
 //初始化客户地址长度
 iLen=sizeof(cliet);  
 //进入循环，等待客户连接请求
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
  //给连接的客户发送信息
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