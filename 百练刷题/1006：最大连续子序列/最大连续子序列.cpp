/*
    给出一段序列，选出其中连续且非空的一段使得这段和最大。
*/
//分析：令b[j]表示以位置 j 为终点的所有子区间中和最大的一个。　　　　
//如j为终点的最大子区间包含了位置j-1,则以j-1为终点的最大子区间必然包括在其中。
//如果b[j-1] >0, 那么显然b[j] = b[j-1] + a[j]，用之前最大的一个加上a[j]即可，因为a[j]必须包含。
//如果b[j-1]<=0,那么b[j] = a[j] ,因为既然最大，前面的负数必然不能使你更大。
#include<iostream>
using namespace std;
int a[100001];
int n;
int maxsum(){ //求最大连续子序列的标准dp算法，就是每次算出当前觉得比较大的值，比如如果之前的b<=0,那么算到a[i]时，肯定是b直接赋值为a[i]更直接
    int local_sum=a[1];
    int b=0;
    for(int i=1;i<=n;i++){
        if(b>0) b+=a[i];
        else b=a[i];
        if(b>local_sum) local_sum=b;
    }
    return local_sum;
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    cout<<maxsum()<<endl;
    return 0;
}
