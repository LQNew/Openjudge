//首字母大写，思路很水
//但是用到了两个函数可以了解，一个是gets()函数，用于接收一行一行的输入的字符串，对于空白符不会结束
//另一个是将字符大小写转换的函数 toupper()以及tolower()函数~
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
