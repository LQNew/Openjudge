//处理好进位借位的关系
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int a[201];
int b[201];
char str1[201];
char str2[201];
int main(){
    cin>>str1>>str2;
    reverse(&str1[0],&str1[strlen(str1)]);
    reverse(&str2[0],&str2[strlen(str2)]);
    for(int i=0;i<strlen(str1);i++) a[i]=str1[i]-'0';
    for(int i=0;i<strlen(str2);i++) b[i]=str2[i]-'0';
    for(int i=0;i<strlen(str1);i++){
        if(a[i]<b[i]){
            a[i]=a[i]+10-b[i];
            a[i+1]-=1;
        }
        else a[i]-=b[i];
    }
    bool flag=false;
    for(int j=strlen(str1)-1;j>=0;j--){
        if(a[j]==0&&!flag) continue;
        else{
            cout<<a[j];
            flag=true;
        }
    }
    cout<<endl;
    return 0;
}
