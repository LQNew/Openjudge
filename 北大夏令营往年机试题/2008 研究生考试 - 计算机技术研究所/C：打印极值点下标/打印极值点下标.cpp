//Ë®Ìâ
#include<iostream>
using namespace std;
int n;
int k;
int a[90];
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>k;
        for(int j=0;j<k;j++) cin>>a[j];
        if(k==1) cout<<a[0]<<endl;
        else{
            if(a[0]!=a[1]) cout<<0<<' ';
            for(int i=1;i<k-1;i++){
                if((a[i]>a[i-1]&&a[i]>a[i+1])||(a[i]<a[i-1]&&a[i]<a[i+1])) cout<<i<<' ';
            }
            if(a[k-1]!=a[k-2]) cout<<k-1<<endl;
            else cout<<endl;
        }
    }
    return 0;
}
