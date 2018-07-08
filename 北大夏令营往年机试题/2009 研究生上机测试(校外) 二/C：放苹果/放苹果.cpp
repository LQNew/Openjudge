//递归问题，要能细心推导出来！
//算是8种球盒问题 000型
#include<iostream>
using namespace std;
int t;
int M,N;

int f(int M,int N){
    if(M==0||N==1||M==1) return 1;
    else if(M<N) return f(M,M); //当M<N时，本质上就是将M个球投入M个盒子，允许有空
    else return f(M,N-1)+f(M-N,N); //最核心的思路，就是从递归出发，要么N-1个盒子放M个球，允许有空，有么一定在N个盒子里面都有球
}

int main(){
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>M>>N;
        cout<<f(M,N)<<endl;
    }
    return 0;
}
