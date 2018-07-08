//水题，一开始怀疑会不会tl，结果数据量不大，没有tl。。
#include<iostream>
using namespace std;
int N;
int a[101];
int main(){
    for(int i=1;i<=100;i++) a[i]=i*i*i;
    cin>>N;
    if(N<6) cout<<endl;
    for(int i=6;i<=N;i++){
        for(int j=2;j<i;j++){
            for(int k=j;k<i;k++){
                for(int t=k;t<i;t++)
                    if(a[j]+a[k]+a[t]==a[i]) cout<<"Cube = "<<i<<", Triple = ("<<j<<','<<k<<','<<t<<')'<<endl;
            }
        }
    }
    return 0;
}
