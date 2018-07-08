//逻辑题，抓住了，离去的人一定在没有空床位之前这一点做的，本道题感觉做的很有灵性,em...
#include<iostream>
#include<cstring>
using namespace std;
int n;
char str1[1000];
char flag[30];
int main(){
    while(cin>>n){
        if(n==0) break;
        int ans=0;
        cin>>str1;
        memset(&flag[1],'#',sizeof(char)*n);
        for(int i=0;i<strlen(str1);i++){
            bool containing=false;
            bool inserting=false;
            for(int j=1;j<=n;j++){
                if(flag[j]==str1[i]){
                    flag[j]='#';
                    containing=true;
                    break;
                }
            }
            if(!containing){
                for(int j=1;j<=n;j++){
                    if(flag[j]=='#'){
                        flag[j]=str1[i];
                        inserting=true;
                        break;
                    }
                }
                if(!inserting) ans++;
            }
        }
        if(ans/2==0) cout<<"All customers tanned successfully."<<endl;
        else cout<<ans/2<<" customer(s) walked away."<<endl;
    }
    return 0;
}
