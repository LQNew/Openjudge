//WA...尚未想清楚为什么会出错..
#include<iostream>
using namespace std;
int t;
int N,X,Y,MAX;
int x1,x2,h;
const int INF=0X7FFFFFFF;
struct Node{
    int x1; //板的左侧横坐标
    int x2; //板的右侧横坐标
    int h;  //板的高度
};
Node node[1001];
int dp[1001][2];
int compare(const void* a, const void* b){
    Node* p1;
    Node* p2;
    p1=(Node*)a;
    p2=(Node*)b;
    return ((*p2).h)-((*p1).h);
}
int main(){
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>N>>X>>Y>>MAX;
        node[0].x1=X;
        node[0].x2=X;
        node[0].h=Y;
        for(int i=1;i<=N;i++) cin>>node[i].x1>>node[i].x2>>node[i].h;
        qsort(node,N+1,sizeof(Node),compare);//将平板高度按照从大到小的顺序排序
        for(int i=1;i<=N;i++) dp[i][0]=dp[i][1]=INF; //初始化
        dp[0][0]=dp[0][1]=0;
        for(int i=0;i<N;i++){ //获取如降至某个平台所对应的最短时间
            if(dp[i][0]!=INF){
                for(int j=i+1;j<=N;j++){
                    if(node[i].h==node[j].h) continue;
                    if(node[i].h-node[j].h>MAX) continue;
                    if(node[i].x1>node[j].x1&&node[i].x1<node[j].x2){ //平台i的左端点落在平台j上
                        dp[j][0]=min(dp[j][0],dp[i][0]+node[i].h-node[j].h+node[i].x1-node[j].x1);
                        dp[j][1]=min(dp[j][1],dp[i][0]+node[i].h-node[j].h+node[j].x2-node[j].x1);
                        break;
                    }
                }
            }
            if(dp[i][1]!=INF){
                for(int j=i+1;j<=N;j++){
                    if(node[i].h==node[j].h) continue;
                    if(node[i].h-node[j].h>MAX) continue;
                    if(node[i].x2>node[j].x1&&node[i].x2<node[j].x2){ //平台i的右端点落在平台j上
                        dp[j][0]=min(dp[j][0],dp[i][1]+node[i].h-node[j].h+node[i].x2-node[j].x1);
                        dp[j][1]=min(dp[j][1],dp[i][1]+node[i].h-node[j].h+node[j].x2-node[i].x2);
                        break;
                    }
                }
            }
        }
        /*
        for(int i=0;i<=N;i++){
            cout<<i<<' '<<dp[i][0]<<' '<<dp[i][1]<<endl;
        }
        */
        //cout<<dp[3][0]<<' '<<dp[3][1]<<endl;
        int min1=INF;
        for(int i=0;i<N;i++){
            if(node[i].h>MAX) continue;
            if(dp[i][1]!=INF){
                int j=i+1;
                for(j;j<=N;j++){
                    if(node[i].x2>=node[j].x2||node[i].x2<=node[j].x1) continue;
                    else break;
                }
                if(j>N) min1=min(dp[i][1]+node[i].h,min1);
            }
            if(dp[i][0]!=INF){
                int j=i+1;
                for(j;j<=N;j++){
                    if(node[i].x1<=node[j].x1||node[i].x1>=node[j].x2) continue;
                    else break;
                }
                if(j>N) min1=min(dp[i][0]+node[i].h,min1);
            }
        }
        if(dp[N][1]!=INF) min1=min(dp[N][1]+node[N].h,min1);
        if(dp[N][0]!=INF) min1=min(dp[N][0]+node[N].h,min1);
        cout<<min1<<endl;
    }
    return 0;
}
