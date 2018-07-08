//Ë®Ìâ
#include<iostream>
using namespace std;
int a[21];
int N;
int main(){
    a[0]=1;
    a[1]=1;
    for(int i=2;i<21;i++){
        a[i]=a[i-1]+a[i-2];
    }
    cin>>N;
    cout<<a[N]<<endl;
    return 0;
}
