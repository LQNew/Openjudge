//非高精度运算，水题
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int a[32];
char str1[32];
int b1[32];
int main(){
    int b=1;
    for(int i=1;i<32;i++){
        b*=2;
        a[i]=b-1;
    }
    while(cin>>str1){
        int ans=0;
        if(strlen(str1)==1&&str1[0]=='0') break;
        reverse(&str1[0],&str1[strlen(str1)]);
        for(int i=0;i<strlen(str1);i++) b1[i+1]=str1[i]-'0';
        for(int j=1;j<=strlen(str1);j++) ans+=b1[j]*a[j];
        cout<<ans<<endl;
    }
    return 0;
}
