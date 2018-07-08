//水题
#include<iostream>
#include<cstring>
using namespace std;
char decoding[26]={'V','W','X','Y','Z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U'};
char str1[210];
int main(){
    gets(str1);
    for(int i=0;i<strlen(str1);i++){
        if(str1[i]>='A'&&str1[i]<='Z'){
            str1[i]=decoding[str1[i]-'A'];
        }
    }
    cout<<str1<<endl;
    return 0;
}
