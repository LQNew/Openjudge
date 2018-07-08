//Ë®Ìâ
#include<iostream>
using namespace std;
int a[100];
int m;
int main(){
    int i=0;
    int cnt=0;
    while(cin>>a[i++]){};
    m=a[i-2];
    for(int j=0;j<=i-3;j++){
        if(a[j]<=m+30) cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}
