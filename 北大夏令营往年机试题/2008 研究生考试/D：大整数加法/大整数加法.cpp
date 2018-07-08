//大整数加法，题目不难，主要有一个坑逼的地方就是 0+0=0 要打印出来！！
#include<iostream>
#include<cstring>
using namespace std;
char str1[300];
int add1[300];
char str2[300];
int add2[300];
int result[310];
int main(){
    bool flag=true;
    cin>>str1;
    cin>>str2;
    memset(add1,0,sizeof(add1));
    memset(add2,0,sizeof(add2));
    for(int i=strlen(str1)-1;i>=0;i--) add1[strlen(str1)-1-i]=str1[i]-'0';
    for(int i=strlen(str2)-1;i>=0;i--) add2[strlen(str2)-1-i]=str2[i]-'0';
    int max_len=max(strlen(str1),strlen(str2));
    for(int i=0;i<max_len;i++) result[i]=add1[i]+add2[i];
    for(int i=0;i<max_len;i++){
        result[i+1]+=result[i]/10;
        result[i]=result[i]%10;
    }
    if(max_len==1&&result[max_len]==0) cout<<0;
    else if(result[max_len]!=0){
        cout<<result[max_len];
        for(int i=max_len-1;i>=0;i--) cout<<result[i];
    }
    else{
        for(int i=max_len-1;i>=0;i--){
            if(result[i]==0&&flag) continue;
            else if(result[i]!=0){
                cout<<result[i];
                flag=false;
            }
            else{
                cout<<result[i];
                flag=false;
            }
        }
    }
    cout<<endl;
    return 0;
}
