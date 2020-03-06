#include<stdio.h>
struct ss{
     int a;
     char b[20];
}s[3];
int main(){
    int i;

    s[0].a=1;
    strcpy(s[0].b,"Hello");
    s[1].a=2;
    strcpy(s[1].b,"World");
    s[2].a=3;
    strcpy(s[2].b,"Bye");

    FILE *w=fopen("data.txt","wb");
    fwrite(s,sizeof(struct ss),3,w);
    fclose(w);

    FILE *r=fopen("data.txt","rb");
    fread(s,sizeof(struct ss),3,r);
    fclose(r);

    for(i=0;i<=2;i++)
        printf("%d %s\n",s[i].a,s[i].b);

}
