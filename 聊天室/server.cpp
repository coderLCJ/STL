// client.cpp : Defines the entry point for the console application.
//

#include<Winsock2.h>
#include<stdio.h>
#include "string.h"
#pragma comment(lib,"WSOCK32.lib")   //???
#define PORT 5000
 #define BUFFER 5000
 WSADATA          wsaData;
 SOCKET           client;
 int              port=PORT;
 //???????????
 int              iLen;
 //???????
 char             buf[BUFFER];
 //??????
 struct sockaddr_in     serv;
DWORD WINAPI RecvThread(LPVOID lpParam)
{
  //????????
 while(1)
 {
  iLen=recv(client,buf,sizeof(buf),0);
  if(iLen==0)
   return 0;
  else if(iLen==SOCKET_ERROR)
  {
   printf("recv()failed:%d\n",WSAGetLastError());
   return 0;
  }
  else
  {
   printf("Server send :%s\n",buf);
   ///////////////////////////////
   int num=0;
   int sum=0;
   int i;
   for(i=0;i<=strlen(buf);i++)
   {
    if(buf[i]<='9'&&buf[i]>='0')
    {
     num=num*10+buf[i]-'0';
     continue;
    }
     sum+=num;
     num=0;
   }
   printf("The Sum is: %d .....Now Send To Server....\n",sum);
   sprintf(buf,"%d\nInput Data:",sum);
   int iSend=send(client,buf,sizeof(buf),0);      //????
   if(iSend==SOCKET_ERROR)
   {
    printf("send()failed:%d\n",WSAGetLastError());
    break;
   }
   else
   {
    printf("Send Ok\n");
   }
   ////////////////////////////////
  }
 }
  return 0;
}


void main(int argc,char *argv[])
{

 //???????????
 /*if(argc<2)         //??????????
 {
  //???????IP??
  printf("Input the server IP address:\n");

  return ;
 }
 */


 //??????????
 memset(buf,0,sizeof(buf));
 if(WSAStartup(MAKEWORD(2,2),&wsaData)!=0)
 {
  printf("Winsock load failed\n");
  return;
 }
 //????????????
 serv.sin_family=AF_INET;
 //????????????
 serv.sin_port=htons(port);
 //?????IP?????????????????IP??
 serv.sin_addr.s_addr=inet_addr("127.0.0.1");
 //?????????
 client=socket(AF_INET,SOCK_STREAM,0);
 if(client==INVALID_SOCKET)
 {
  printf("socket()failed:%d\n",WSAGetLastError());
  return;
 }
 //????????TCP??



 if(connect(client,(struct sockaddr*)&serv,sizeof(serv))==INVALID_SOCKET)
 {
  printf("connet()failed:%d\n",WSAGetLastError());
  return;
 }
 else
 {
  HANDLE hThread;
  hThread=CreateThread(NULL,NULL,RecvThread,0,0,0);    //????????
  printf("Wait Server Send Data...\n");
   while(1)
  {
   ///////////////////////send data

     gets(buf);
     int iSend=send(client,buf,sizeof(buf),0);      //????
     if(iSend==SOCKET_ERROR)
     {
      printf("send()failed:%d\n",WSAGetLastError());
     break;
    }
    //////////////
  }

 }
 closesocket(client);
 WSACleanup();
 printf("press any key to continue"); //?????,??????
}
