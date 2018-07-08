//生成表
#include<iostream>
using namespace std;
long long b[1510];
int multi_factor[30];
int cnt;
int main(){
    b[0]=1;
    cnt=1;
    for(long long i=2;;i++){
        long long a=i;
        while(a%2==0) a/=2;
        while(a%5==0) a/=5;
        while(a%3==0) a/=3;
        if(a==1){
            b[cnt]=i;
            cnt++;
        }
        if(cnt>1500) break;
    }
    cout<<cnt<<endl;
    for(int i=0;i<cnt-1;i++){
        cout<<b[i]<<',';
    }
    cout<<b[cnt-1]<<endl;
    return 0;
}
