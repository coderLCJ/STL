#include <stdio.h>
int  main()
{
    int a=10,b=20,c;
    int  *pa=&a;
    int *pb = &b,*pc;
    printf("pa=%p *pa=%d pb=%p *pb=%d  a=%p b=%p a=%d b=%d\n",pa,*pa,pb,*pb,&a,&b,a,b);
    pc = pa  ;
    pa = pb ;
    pb = pc ;
    printf("pa=%p *pa=%d pb=%p *pb=%d  a=%p b=%p a=%d b=%d\n",pa,*pa,pb,*pb,&a,&b,a,b);

    pa=&a;
    pb=&b;
    c = *pa;
    *pa = *pb ;
    *pb = c ;
    printf("pa=%p *pa=%d pb=%p *pb=%d  a=%p b=%p a=%d b=%d\n",pa,*pa,pb,*pb,&a,&b,a,b);

}


