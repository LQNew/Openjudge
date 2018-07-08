//模拟问题，难度不大
#include<iostream>
using namespace std;
int N;
int a[1000];
int tmp[1000];
int main(){
    while(cin>>N){
        if(N==0) break;
        for(int i=0;i<N;i++) cin>>a[i];
        int round=0;
        while(1){
            round++;
            for(int i=0;i<N;i++){
                a[i]/=2;
                tmp[i+1]=a[i];
            }
            a[0]+=tmp[N];
            if(a[0]%2) a[0]++;
            for(int j=1;j<N;j++){
                a[j]+=tmp[j];
                if(a[j]%2) a[j]++;
            }
            int k;
            for(k=1;k<N;k++){
                if(a[k]!=a[k-1]) break;
            }
            if(k==N){
                cout<<round<<' '<<a[0]<<endl;
                break;
            }
        }
    }
    return 0;
}
