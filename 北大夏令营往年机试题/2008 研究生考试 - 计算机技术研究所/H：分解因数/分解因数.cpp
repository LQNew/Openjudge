//本道题难度不大，但是一定要想清楚因子的运算相除这些流程！！同时本道题的两点之处在于运用了 递归思路
#include<iostream>
using namespace std;
int a;
int n;

int split(int x,int n){
    int ans=1;
    for(int i=x;i*i<=n;i++){ //每次从当前计算出的因子开始运算，为了防止重复计数~
        if(n%i==0){
            ans+=split(i,n/i);
        }
    }
    return ans;
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a;
        int ans=split(2,a);
        cout<<ans<<endl;
    }
    return 0;
}
