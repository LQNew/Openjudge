/*
    N阶楼梯上楼问题：一次可以走两阶或一阶，问有多少种上楼方式。
*/
//分析：简单的递归问题，就是n阶楼梯的上楼方式个数=F[n-1]+F[n-2]，这在高中也有考查过此类问题，就是整理出逻辑~
#include<iostream>
using namespace std;
int N;
long long steps[91];
int main(){
    steps[1]=1;
    steps[2]=2;
    for(int i=3;i<=90;i++){
        steps[i]=steps[i-1]+steps[i-2];
    }
    while(cin>>N){
        cout<<steps[N]<<endl;
    }
    return 0;
}
