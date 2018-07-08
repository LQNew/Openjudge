//水题，不过题目表述得感觉有点差劲
#include<iostream>
#include<cstring>
using namespace std;
int cnt;
char str1[90];
int main(){
    cin>>cnt;
    getchar();
    for(int i=0;i<cnt;i++){
        gets(str1);
        if(str1[0]=='_'||(str1[0]>='a'&&str1[0]<='z')||(str1[0]>='A'&&str1[0]<='Z')){
            int i;
            for(i=1;i<strlen(str1);i++){
                if(str1[i]=='_'||(str1[i]>='a'&&str1[0]<='z')||(str1[i]>='A'&&str1[i]<='Z'||str1[i]>='0'&&str1[i]<='9')) continue;
                else break;
            }
            if(i==strlen(str1)) cout<<1<<endl;
            else cout<<0<<endl;
        }
        else cout<<0<<endl;
    }
    return 0;
}
