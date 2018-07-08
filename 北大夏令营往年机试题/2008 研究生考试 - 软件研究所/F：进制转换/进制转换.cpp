//进制转换，涉及到大数运算，主要是大数运算中的除法运算~~
//本道题主要是考察逻辑的分析能力，题目出得难易适中，不错~
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int a[30];
int b[1000];
char str1[31];
int main(){
    while(cin>>str1){
        int t=0;
        reverse(&str1[0],&str1[strlen(str1)]);
        for(int i=0;i<strlen(str1);i++) a[i]=str1[i]-'0';
        while(1){
            int i;
            for(i=strlen(str1)-1;i>0;i--){
                if(a[i]%2){
                    a[i-1]+=10;
                    a[i]=a[i]/2;
                }
                else a[i]=a[i]/2;
            }
            b[t]=a[i]%2;
            a[i]=a[i]/2;
            t++;
            int ans=0;
            for(int j=0;j<strlen(str1);j++) ans+=a[j];
            if(ans>0) continue; //判别辗转相除是否结束
            else break;
        }
        for(int i=t-1;i>=0;i--) cout<<b[i];
        cout<<endl;
    }
    return 0;
}
