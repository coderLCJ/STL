#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int main()
{
   char c;
   puts("按任意键点名 Q键退出点名");
   while(scanf("%c",&c)&&c!='Q'){
       getchar();
       srand((int)time(0));
       printf("%d\n",rand()%59);
   }
}
