#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int n;
    FILE* p=fopen("input.txt","r");
    while(fscanf(p,"%d",&n)!=EOF);
    printf("%d\n",n);
    fclose(p);
    int a;
    scanf("%d",&a);
    printf("%d\n",a);
    FILE *o=fopen("output.txt","w");
    fprintf(o,"%d",a);
    if(fclose(o)==0)
        puts("Yes");
}
