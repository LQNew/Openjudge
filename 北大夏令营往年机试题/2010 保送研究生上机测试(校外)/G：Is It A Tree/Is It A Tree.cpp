//水题，但是题目样例给的不好感觉...
#include<iostream>
#include<cstring>
using namespace std;
int max1;
int in[10000];
int out[10000];
int a,b;
int cnt;
int num;
int main(){
    memset(in,0,sizeof(in));
    memset(out,0,sizeof(out));
    num=0;
    max1=0;
    while(cin>>a>>b){
        if(a==-1&&b==-1) break;
        if(a==0&&b==0){
            bool flag=true;
            num++;
            if(max1==0){
                cout<<"Case "<<num<<" is a tree."<<endl;
                continue;
            }
            else{
                cnt=0;
                int i;
                for(i=1;i<=max1;i++){
                    if(in[i]==0&&out[i]!=0) cnt++;
                    if(in[i]>1){
                        flag=false;
                        break;
                    }
                }
                if(flag&&cnt==1) cout<<"Case "<<num<<" is a tree."<<endl;
                else cout<<"Case "<<num<<" is not a tree."<<endl;
                memset(in,0,sizeof(in));
                memset(out,0,sizeof(out));
                max1=0;
                continue;
            }
        }
        max1=max(max1,a);
        max1=max(max1,b);
        in[b]++;
        out[a]++;
    }
    return 0;
}
