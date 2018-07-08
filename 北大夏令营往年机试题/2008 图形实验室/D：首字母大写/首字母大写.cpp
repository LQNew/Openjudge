//题目难度不大，不过关于换行符如何读入我很奇怪，感觉换行符就是按回车键终止orz..
//本道题主要是用到了gets()函数获取一行字符串以及 toupper()函数将字母大写~
#include<iostream>
#include<cstring>
using namespace std;
char str1[80];
int main(){
    gets(str1);
    //cout<<str1<<endl;
    str1[0]=toupper(str1[0]);
    for(int i=1;i<strlen(str1)-1;i++){
        if(str1[i]==' '||str1[i]=='\t'||str1[i]=='\n'||str1[i]=='\r') str1[i+1]=toupper(str1[i+1]);
    }
    cout<<str1<<endl;
    return 0;
}
