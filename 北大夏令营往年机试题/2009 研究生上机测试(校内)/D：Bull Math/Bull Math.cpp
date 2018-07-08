//大整数乘法，高精度运算，水题
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
char str1[100];
char str2[100];
int a[100];
int b[100];
int ans[100];
int main(){
    cin>>str1>>str2;
    memset(ans,0,sizeof(ans));
    reverse(&str1[0],&str1[strlen(str1)]);
    reverse(&str2[0],&str2[strlen(str2)]);
    for(int i=0;i<strlen(str1);i++) a[i]=str1[i]-'0';
    for(int i=0;i<strlen(str2);i++) b[i]=str2[i]-'0';
    for(int i=0;i<strlen(str1);i++){
        for(int j=0;j<strlen(str2);j++) ans[i+j]+=(a[i]*b[j]);
    }
    int len=strlen(str1)+strlen(str2)-1;
    for(int i=0;i<len-1;i++){
        ans[i+1]+=ans[i]/10;
        ans[i]=ans[i]%10;
    }
    if(len==1&&ans[len-1]==0) cout<<ans[len-1]<<endl;
    else{
        if(ans[len-1]!=0) cout<<ans[len-1];
        for(int j=len-2;j>=0;j--) cout<<ans[j];
        cout<<endl;
    }
    return 0;
}
