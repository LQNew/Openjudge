//因为右括号肯定与最近的左括号匹配，所以只压左括号
//本道题思路一直没打开，以后要多想多写！！
#include<iostream>
#include<cstring>
#include<stack>
using namespace std;
char str[101];
stack<int>S;
int main(){
    while(cin>>str){
        cout<<str<<endl;
        while(!S.empty()) S.pop();
        for(int i=0;i<strlen(str);i++){
            if(str[i]=='('){
                S.push(i);
            }
            if(str[i]==')'){
                if(!S.empty()){
                    S.pop();
                    str[i]=' ';
                }
                else{
                    str[i]='?';
                }
            }
            else str[i]=' ';
        }
        while(!S.empty()){
            str[S.top()]='$';
            S.pop();
        }
        cout<<str<<endl;
    }

    return 0;
}
