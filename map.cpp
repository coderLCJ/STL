#include<bits/stdc++.h>
using namespace std;
int main(){
    int a[100]={0,2},n,m;
    for(int i=2;i<=100;i++){
        a[i]=a[i-1]+2;
    }
    while(cin>>n>>m){
        int b[n],t=0,s=0;
        for(int i=1;i<=n;i++){
            s+=a[i];
            if(i%m==0){
               b[t]=s/m;
               t++;
               s=0;

            }
        }
        if(n%m!=0){
           b[t++]=s/(n%m);
        }

        for(int i=0;i<t;i++)
            cout<<b[i]<<' ';
        cout<<endl;
    }

}
