//Ë®Ìâ
#include<iostream>
#include<cstring>
using namespace std;
bool del[300];
int n,m;
int main(){
    while(cin>>n>>m){
        if(n==0&&m==0) break;
        memset(del,0,sizeof(del));
        int cnt=0;
        int ans=0;
        for(int i=0;;i++){
            i=i%n;
            if(ans==n-1) break;
            if(!del[i]){
                cnt++;
                if(cnt==m){
                    ans++;
                    cnt=0;
                    del[i]=true;
                    continue;
                }
            }
        }
        for(int i=0;i<n;i++){
            if(!del[i]){
                cout<<i+1<<endl;
                break;
            }
        }
    }
    return 0;
}
