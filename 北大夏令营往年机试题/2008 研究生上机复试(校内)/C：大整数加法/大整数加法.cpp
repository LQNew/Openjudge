//模板题，大整数加法
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
char str1[201];
char str2[201];
int a[201];
int b[201];
int add[201];
int main(){
    cin>>str1>>str2;
    reverse(&str1[0],&str1[strlen(str1)]);
    reverse(&str2[0],&str2[strlen(str2)]);
    for(int i=strlen(str1)-1;i>0;i--){ //去除前导0操作
        if(str1[i]=='0'){
            str1[i]='a';
            continue;
        }
        else break;
    }
    for(int i=strlen(str2)-1;i>0;i--){
        if(str2[i]=='0'){
            str2[i]='a';
            continue;
        }
        else break;
    }
    int i;
    memset(a,0,sizeof(a));
    for(i=0;i<strlen(str1);i++){ //将字符串转化为数组
        if(str1[i]=='a') break;
        else a[i]=str1[i]-'0';
    }
    int cnt=i;//cnt记录下第一个输入的纯输入个数
    memset(b,0,sizeof(b));
    for(i=0;i<strlen(str2);i++){
        if(str2[i]=='a') break;
        else b[i]=str2[i]-'0';
    }
    int cnt1=i;//cnt记录下第二个输入的纯输入个数
    memset(add,0,sizeof(add));
    int cnt_all=max(cnt,cnt1);
    for(int i=0;i<cnt_all;i++) add[i]=a[i]+b[i];
    for(int i=0;i<cnt_all;i++){
        add[i+1]+=add[i]/10;
        add[i]=add[i]%10;
    }
    if(add[cnt_all]) cnt_all++;
    for(int i=cnt_all-1;i>=0;i--) cout<<add[i];
    cout<<endl;
    return 0;
}
