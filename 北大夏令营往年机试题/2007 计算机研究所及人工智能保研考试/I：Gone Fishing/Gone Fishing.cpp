//贪心法，我嫌代码码的太烦，放弃orz..
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
int n;
int h;
int fi,di,ti;
int time_1[26];
int time_node[26];
int time_node1[26];
struct Node{
    int id;
    int fi;
    int di;
    //运算符重载，有点技巧...
    friend bool operator <(Node a, Node b){   //注意从大到小排，要重载 '<'
        if(a.fi == b.fi) return a.id > b.id;   //若鱼数相等，则选择id较小的
        return a.fi < b.fi;
    }
};
Node node[26];
Node node1[26];
Node node2[26];
priority_queue<Node>Q;
int main(){
    while(cin>>n){
        if(n==0) break;
        cin>>h;
        h*=60;
        int t1;
        int ans;
        int max1=0;
        for(int i=1;i<=n;i++){
            node[i].id=i;
            //time_node[i]=0;
            cin>>node[i].fi;
        }
        for(int i=1;i<=n;i++) cin>>node[i].di;
        for(int i=1;i<n;i++) cin>>time_1[i];
        for(int i=2;i<=n;i++){
            memset(time_node1,0,sizeof(time_node1));
            memcpy(node1,node,sizeof(node));
            while(!Q.empty()) Q.pop();
            for(int i=1;i<=n;i++) Q.push(node1[i]);
            int h1=h;
            t1=0;
            ans=0;
            for(int j=1;j<i;j++) t1+=time_1[j];
            if(h1-t1<0) break;
            h1-=t1;
            while(1){
                Node tmp=Q.top();
                Q.pop();
                h1-=5;
                if(h1<=0) break;
                ans+=tmp.fi;
                tmp.fi=max(0,tmp.fi-tmp.di);
                time_node1[tmp.id]+=5;
                Q.push(tmp);
            }
            if(ans>max1) memcpy(time_node,time_node1,sizeof(time_node1));
        }
        for(int i=1;i<n;i++) cout<<time_node[i]<<', ';
        cout<<time_node[n]<<endl;
        cout<<"Number of fish expected: "<<ans<<endl;
    }
    return 0;
}
