//0-1背包问题，这类模板题要多想~要保证一气呵成
#include<iostream>
#include<cstring>
using namespace std;
int dp[1001];
int C,N;
struct Node{
    int Vi;
    int Pi;
};
Node node[101];
int main(){
    while(cin>>C>>N){
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=N;i++) cin>>node[i].Pi>>node[i].Vi;
        for(int j=1;j<=N;j++){
            for(int i=C;i>=node[j].Pi;i--){
                dp[i]=max(dp[i],dp[i-node[j].Pi]+node[j].Vi);
            }
        }
        int max1=0;
        for(int i=0;i<=C;i++){
            max1=max(max1,dp[i]);
        }
        cout<<max1<<endl;

    }
    return 0;
}
