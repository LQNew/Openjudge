//看网上题解感觉是指每个盒子最多放两颗球:A和B；或者可以仅某种球一颗，或者不放球~
//就是简单的组合问题，将A个相同的球放入N个不同的盒子中，每个盒子可以放一颗A球或者不放，其实就相当于 将A个球补上N个空球，然后选出N个球与盒子匹配上
//本道题 主要注意阶层计算时数值会溢出的问题，如果图方便的话可以直接写一个大数乘法，此处是用long long 型长类型数据存储解决~
#include<iostream>
using namespace std;
int N,A,B;

long long computer_hierarchy_up(int n,int a){
    long long  total=1;
    for(int i=n-a+1;i<=n;i++) total*=i;
    return total;
}
long long computer_hierarchy_down(int n){
    long long  total=1;
    for(int i=2;i<=n;i++) total*=i;
    return total;
}
int main(){
    while(cin>>N>>A>>B){
        long long a=computer_hierarchy_up(N+A,A)/computer_hierarchy_down(A);
        long long b=computer_hierarchy_up(N+B,B)/computer_hierarchy_down(B);
        cout<<a*b<<endl;
    }
    return 0;
}
