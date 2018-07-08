//本道题算是典型的贪心问题，但是对我而言，题目的意思很难解析出思路，所以我做的很勉强，最后还是看网上题解AC orz...
//本道题就是将当前最大的数值塞入空的时间段内，遍历所有结点，直到结束，这样的话在时间段内塞入的一定是最大的profit!!
#include<iostream>
#include<cstring>
using namespace std;
int n;
bool visit[10001];
struct Node{
    int profit;
    int deadline;
};
Node node[10000];
int compare(const void* a, const void* b){
    Node* p1;
    Node* p2;
    p1=(Node*)a;
    p2=(Node*)b;
    return (*p2).profit-(*p1).profit;
}
int main(){
    while(cin>>n){
        memset(visit,0,sizeof(visit));
        for(int i=0;i<n;i++) cin>>node[i].profit>>node[i].deadline;
        int ans=0;
        qsort(&node[0],n,sizeof(Node),compare);
        for(int i=0;i<n;i++){
            for(int j=node[i].deadline;j>0;j--){ //在规定的时间段内允许的状态下塞入最大的profit!!
                if(!visit[j]){
                    visit[j]=true;
                    ans+=node[i].profit;
                    break;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
