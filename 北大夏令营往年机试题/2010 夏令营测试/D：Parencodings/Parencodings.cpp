//利用了栈对字符串进行处理
#include<iostream>
#include<cstring>
#include<stack>
using namespace std;
char str[100];
int cnt[100];
int t;
int n;
int a;
stack<int>S;
int main(){
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n;
        int cnt1=0;//记录字符串的字符个数
        int k=0;
        //构造字符串
        for(int j=0;j<n;j++){
            cin>>a;
            for(k;k<a;k++){
                str[cnt1]='(';
                cnt1++;
            }
            str[cnt1]=')';
            cnt1++;
        }
        str[cnt1]='\0';
        //记录每个下标对应的字符前又多少个'('
        int cnt2=0;
        for(int i=0;i<strlen(str);i++){
            if(str[i]=='('){
                cnt2++;
                cnt[i]=cnt2;
            }
            else cnt[i]=cnt2;
        }
        //栈操作
        for(int i=0;i<strlen(str);i++){
            if(str[i]=='(') S.push(i);
            else if(str[i]==')') {
                int num=S.top();
                S.pop();
                cout<<cnt[i]-cnt[num]+1<<' ';
            }
        }
        cout<<endl;
    }
    return 0;
}
