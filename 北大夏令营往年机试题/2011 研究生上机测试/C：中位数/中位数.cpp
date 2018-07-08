//数据量较小，简单快排就AC了，水题
#include<iostream>
#include<cmath>
using namespace std;
int N;
int a[15000];
int compare(const void* a, const void* b){
    int* p1;
    int* p2;
    p1=(int*)a;
    p2=(int*)b;
    return *p1-*p2;
}
int main(){
    while(cin>>N){
        if(N==0) break;
        for(int i=0;i<N;i++) cin>>a[i];
        qsort(&a[0],N,sizeof(int),compare);
        if(N%2) cout<<a[(N+1)/2-1]<<endl;
        else cout<<floor(float(a[N/2]+a[N/2-1])/2.0)<<endl;
    }
    return 0;
}
