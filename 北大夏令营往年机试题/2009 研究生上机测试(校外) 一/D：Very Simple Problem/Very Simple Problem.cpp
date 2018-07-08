//题目难度不大，主要需要用数组标识~逻辑性不错的题
#include<iostream>
#include<cstring>
using namespace std;
int N,P;
int a;
struct Node{
    int id;
    int weight;
};
Node node[100][100];
int record[101];
bool judge[101];
int compare(const void* a,const void* b){
    Node* p1;
    Node* p2;
    p1=(Node*)a;
    p2=(Node*)b;
    if((*p1).weight>(*p2).weight) return 1;
    else if((*p1).weight==(*p2).weight) return (*p1).id-(*p2).id;
    else return -1;
}

int main(){
    cin>>N>>P;
    for(int i=0;i<N;i++){
        for(int j=0;j<P;j++){
            cin>>a;
            node[i][j].id=j+1;
            node[i][j].weight=a;
        }
    }
    for(int i=0;i<N;i++) qsort(&node[i][0],P,sizeof(Node),compare); //对于每个评委的打分排序
    memset(judge,0,sizeof(judge));
    memset(record,0,sizeof(record));
    for(int i=0;i<N;i++){
        for(int j=0;j<P;j++){
            if(judge[node[i][j].id]) continue; //判断该id号是否已经被标识过为 hardest
            if(node[i][j].weight==node[i][P-1].weight){ //判别该id号对应的problem是否为hardest
                judge[node[i][j].id]=true;
                record[node[i][j].id]=0;
                continue;
            }
            if(node[i][j].weight==node[i][0].weight) record[node[i][j].id]++; //判别该id号对应的problem是否为simplest
        }
    }
    int ans=0;
    for(int i=1;i<=P;i++){
        if(record[i]>N/2) cout<<i<<' ';
        else ans++;
    }
    if(ans==P) cout<<0<<endl;
    return 0;
}
