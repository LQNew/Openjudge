//Ë®Ìâ
#include<iostream>
using namespace std;
long long a[13];
int n;
int main(){
    long long b=1;
    for(long long i=1;i<=12;i++){
        b*=i;
        a[i]=b;
    }
    cin>>n;
    long long ans=0;
    for(int i=1;i<=n;i++) ans+=a[i];
    cout<<ans<<endl;
    return 0;
}
