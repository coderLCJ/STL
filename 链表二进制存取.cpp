#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
typedef struct node
{
    char num[20];
    char name[20];
    char college[20];
    char Class[20];
    double math;
    double english;
    double c;
    struct node *next;
} NODE;


NODE* Add(NODE* R)
{
    int k;
    do
    {
        NODE *n=(NODE*)malloc(sizeof(NODE));
        printf("请输入添加学生的信息:");
        scanf("%s %s %s %s %lf %lf %lf",n->num,n->name,n->college,n->Class,&n->math,&n->english,&n->c);
        n->next=NULL;
        R->next=n;
        R=n;
        printf("是否继续录入?(y/n)\n");
        scanf("%d",&k);
        if(k==2)
        {
            return R;
        }
    }
    while(k!=2);
}

void show(NODE *head)
{
    head=head->next;
    FILE *r=fopen("score.txt","rb");
    while(head)
    {

        // printf("%s %s %s %s %f %f %f\n",head->num,head->name,head->college,head->Class,head->math,head->english,head->c);

        NODE *n=(NODE*)malloc(sizeof(NODE));

        fread(n,sizeof(NODE),1,r);

        printf("%s %s %s %s %f %f %f\n",n->num,n->name,n->college,n->Class,n->math,n->english,n->c);

        head=head->next;
    }
    fclose(r);
}

void save(NODE *head)
{
    head=head->next;
    FILE *w=fopen("score.txt","wb");        //新建二进制文件
    while(head)
    {
        fwrite(head,sizeof(NODE),1,w);      ///*此处为指针 无需加取地址符 若为结构体数组元素则要加*
        //printf("%s %s %s %s %f %f %f\n",head->num,head->name,head->college,head->Class,head->math,head->english,head->c);
        head=head->next;
    }
    fclose(w);
}

int main()
{
    NODE *head=(NODE*)malloc(sizeof(NODE)),*tail;
    head->next=NULL;
    tail=head;
    Add(tail);
    save(head);
    show(head);
}

