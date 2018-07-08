//水题，简单的栈应用
#include<iostream>
#include<string>
#include<stack>
#include<cstring>
using namespace std;
char str1[100];
char str2[100];
string current;
stack<string>B;
stack<string>F;
int main(){
    current="http://www.acm.org/";
    while(cin>>str1){
        if(strlen(str1)==4&&strcmp(str1,"QUIT")==0) break;
        else if(strlen(str1)==5){
            cin>>str2;
            B.push(current);
            while(!F.empty()) F.pop();
            current=str2;
            cout<<current<<endl;
        }
        else if(strlen(str1)==4&&strcmp(str1,"BACK")==0){
            if(!B.empty()){
                F.push(current);
                current=B.top();
                B.pop();
                cout<<current<<endl;
            }
            else cout<<"Ignored"<<endl;
        }
        else if(strlen(str1)==7){
            if(!F.empty()){
                B.push(current);
                current=F.top();
                F.pop();
                cout<<current<<endl;
            }
            else cout<<"Ignored"<<endl;
        }
    }
    return 0;
}
