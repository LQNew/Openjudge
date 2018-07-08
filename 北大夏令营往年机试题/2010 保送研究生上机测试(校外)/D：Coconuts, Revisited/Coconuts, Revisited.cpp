//本道题需要注意的是因子的分配！我一直以为因子应小于sqrt(n),陷入了思维误区，那是判断是否为素数的方法，用错了地方！！本道题算是模拟+暴力ac，难度一般
//但是可能脑子需要清醒下！有点瓦特了！..
#include<iostream>
#include<cmath>
using namespace std;
int n;
int main(){
    while(cin>>n){
        if(n==-1) return 0;
        n-=1;
        int i;
        for(i=n;i>=2;i--){
            if(n%i!=0) continue;
            int num=((i-1)*n)/i;
            int j=0;
            for(j;j<i-1;j++){
                num-=1;
                if(num%i!=0) break;
                else num=((i-1)*num)/i;
            }
            if(j==i-1){
                if(num%i==0){
                    cout<<n+1<<" coconuts, "<<i<<" people and 1 monkey"<<endl;
                    break;
                }
                else continue;
            }
        }
        if(i<2) cout<<n+1<<" coconuts, no solution"<<endl;
    }
    return 0;
}
