//字符串题，使用cmath库的atoi 获取字符串的整数数字
//水题
#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
char str1[100];
int main(){
    gets(str1);
    int n=atoi(str1);
    for(int i=0;i<n-1;i++){
        gets(str1);
        for(int i=0;i<strlen(str1);i++){
            if(str1[i]>='a'&&str1[i]<='z'){
                if(str1[i]=='z') str1[i]='a';
                else str1[i]=str1[i]+1;
            }
            else if(str1[i]>='A'&&str1[i]<='Z'){
                if(str1[i]=='Z') str1[i]='A';
                else str1[i]=str1[i]+1;
            }
        }
        cout<<str1<<endl;
    }
    gets(str1);
    for(int i=0;i<strlen(str1);i++){
        if(str1[i]>='a'&&str1[i]<='z'){
            if(str1[i]=='z') str1[i]='a';
            else str1[i]=str1[i]+1;
        }
        else if(str1[i]>='A'&&str1[i]<='Z'){
            if(str1[i]=='Z') str1[i]='A';
            else str1[i]=str1[i]+1;
        }
    }
    cout<<str1;
    return 0;
}
