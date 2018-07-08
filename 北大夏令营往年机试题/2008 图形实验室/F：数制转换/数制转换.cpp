//字符串的处理，主要需要倒置字符串，其中用到了 algorithm 库的reverse函数，reverse函数的起始位置是要倒置的位置，结束位置确实要倒置的位置+1！
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int a,b;
char n[100];
int a1[100];
int transfer[100];
long num1;
long mul1;
int main(){
    cin>>a>>n>>b;
    reverse(&n[0],&n[strlen(n)]); //表示从第一位开始到最后一位全部倒置
    for(int i=0;i<strlen(n);i++){
        if(n[i]>='0'&&n[i]<='9') a1[i]=n[i]-'0';
        else a1[i]=toupper(n[i])-'A'+10;
    }
    mul1=1;
    num1=0;
    num1+=a1[0];
    for(int i=1;i<strlen(n);i++){
        mul1*=a;
        num1+=mul1*a1[i];
    }
    //cout<<num1<<endl;
    int t=0;
    while(num1/b!=0){ //迭代取余数
        transfer[t]=num1%b;
        num1=num1/b;
        t++;
    }
    transfer[t]=num1%b;
    for(t;t>=0;t--){
        if(transfer[t]>9) cout<<char(transfer[t]-10+'A');
        else cout<<transfer[t];
    }
    cout<<endl;
    return 0;
}
