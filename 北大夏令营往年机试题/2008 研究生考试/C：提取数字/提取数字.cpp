//水题，但是思路我始终打不开，不想做了orz...
#include<iostream>
#include<cstring>
using namespace std;
char str[101];
int a[100];
int main(){
    bool flag=false;
    cin>>str;
    memset(a,-1,sizeof(a)); //用于存储字符串中包含数字字符的数字及对应的位置
    for(int i=0;i<strlen(str);i++){
        if(str[i]>='0'&&str[i]<='9'){
            a[i]=str[i]-'0';
        }
    }
    int cnt=0;
    int t=0;
    for(int i=0;i<strlen(str);i++){
        if(a[i]!=-1){
            if(!flag&&a[i]==0) continue;
            else{
                cout<<a[i];
                flag=true;
            }
        }
        else flag=false;
        if(!flag){
            if(i-1<0) continue;
            else if(a[i-1]!=-1) cout<<endl;
        }
    }
    //if(a[strlen(str)-1]!=-1) cout<<endl;
    return 0;
}
