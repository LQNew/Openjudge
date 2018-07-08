//水题，此处用string stl库输出定长子串很舒服！！
#include<iostream>
#include<cstring>
#include<string>
using namespace std;
char a[3000];
int main(){
    while(gets(a)){
        //gets(a);
        string str1=a;
        int end=strlen(a)-1;
        int i;
        while(1){
            int cnt=0;
            for(i=end;i>=0;i--){
                if(str1[i]!=' ') cnt++;
                else break;
            }
            if(i<0){
                cout<<str1.substr(0,cnt)<<endl;
                break;
            }
            else cout<<str1.substr(i+1,cnt)<<' ';
            end=i-1;
        }
    }
    return 0;
}
