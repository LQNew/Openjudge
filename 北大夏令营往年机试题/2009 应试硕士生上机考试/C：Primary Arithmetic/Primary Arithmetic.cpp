//水题，高精度大数运算加法，此题比较恶心之处是它的输出竟然还根据carry数目分单复数！！
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
char str1[12],str2[12];
int a[12];
int b[12];
int c[12];
int main(){
    while(cin>>str1>>str2){
        if(strlen(str1)==1&&strlen(str2)==1&&str1[0]=='0'&&str2[0]=='0') break;
        int cnt=0;
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        memset(c,0,sizeof(c));
        reverse(&str1[0],&str1[strlen(str1)]);
        reverse(&str2[0],&str2[strlen(str2)]);
        for(int i=0;i<strlen(str1);i++) a[i]=str1[i]-'0';
        for(int i=0;i<strlen(str2);i++) b[i]=str2[i]-'0';
        for(int i=0;i<max(strlen(str1),strlen(str2));i++) c[i]=a[i]+b[i];
        for(int i=0;i<max(strlen(str1),strlen(str2));i++){
            if(c[i]>=10){
                cnt++;
                c[i+1]+=c[i]/10;
                c[i]=c[i]%10;
            }
        }
        if(cnt==0) cout<<"No carry operation."<<endl;
        else if(cnt==1) cout<<cnt<<" carry operation."<<endl;
        else cout<<cnt<<" carry operations."<<endl;
    }

    return 0;
}
