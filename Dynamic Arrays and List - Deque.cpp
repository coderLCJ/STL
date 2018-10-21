#include<iostream>
#include<deque>
using namespace std;
int main()
{
    deque<int> a;
    int n,t,d,_;
    cin>>n;
    while(n--){
        cin>>t;
        if(t==0){
           cin>>d>>_;
           if(d==0)
              a.push_front(_);
           else
              a.push_back(_);
        }
        else if(t==1){
           cin>>d;
           cout<<a[d]<<endl;
        }
        else{
           cin>>d;
           if(d==0){
              a.pop_front();
           }
           else
              a.pop_back();
        }
    }
}
