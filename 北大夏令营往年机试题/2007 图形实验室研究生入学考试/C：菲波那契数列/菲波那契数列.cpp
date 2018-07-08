//Ë®Ìâ
#include<iostream>
using namespace std;
int n;
int m;
int a[21];
int main(){
    a[0]=a[1]=1;
    for(int i=2;i<=20;i++){
        a[i]=a[i-1]+a[i-2];
    }
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>m;
        cout<<a[m-1]<<endl;
    }
    return 0;
}
