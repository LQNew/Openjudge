/*
    帮助网线主管确定一个最长的网线长度，并且按此长度对库存中的网线进行切割，能够得到指定数量的网线。
*/
//给了一堆线，每个线的长度也给了，需要确定一个最长的切割网线长度，按此长度切割后能达到指定数量网线。
//本题乍一看毫无思路，后来有人提到了二分法，就是先假定最长的网线长度是一堆网线中最短的网线长度+1，接下来用二分法去不断逼近，如果到最后精度小于0.01的话仍然没有可行解
//那么程序会退出返回0。关于二分法的使用是本题的一个特色之处，同时利用程序输入均为小数点后两位的特点，先进行乘100处理，之后二分法遍历得出最优解！！
//本道题很有思维性，是二分法的一个很好的应用，要多多了解！
#include<iostream>
#include<iomanip>
using namespace std;
int N,K;
int a[10000];
int low,high,mid;
int num;
double b;
int main(){
    cin>>N>>K;
    high=0;
    for(int i=0;i<N;i++){
        cin>>b;
        a[i]=b*100;
        if(high<a[i]) high=a[i];
    }
    high+=1;
    low=0;
    while(low<high-1){
        num=0;
        mid=(low+high)/2;
        if(mid==0) break;
        for(int i=0;i<N;i++){
            num+=a[i]/mid;
        }
        if(num>=K)  low=mid;
        else high=mid;
    }
    if(mid==0) cout<<fixed<<setprecision(2)<<0<<endl;
    else cout<<fixed<<setprecision(2)<<double(low)/100.0<<endl;
    return 0;
}
