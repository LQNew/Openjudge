#include<iostream>
using namespace std;
int n;
int k;
int a[80];

void search_1(int k){
    if(a[0]!=a[1]) cout<<0<<' ';
    for(int i=1;i<k-1;i++){
        if(a[i]>a[i-1]&&a[i]>a[i+1]) cout<<i<<' ';
        else if(a[i]<a[i-1]&&a[i]<a[i+1]) cout<<i<<' ';
    }
    if(a[k-2]!=a[k-1]) cout<<k-1<<' ';
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>k;
        for(int i=0;i<k;i++) cin>>a[i];
        search_1(k);
        cout<<endl;
    }

    return 0;
}
