//并查集题目中的难题级别了，很好的题目，难度较大，主要思路只有多做才能知道从何处下手！！
//利用了并查集的性质判断是否存在错误，以及附加了一个数组用于判别 节点相对根节点的等级
#include<iostream>
#include<cstring>
using namespace std;
int N,K;
int D,X,Y;
int cnt;
int Tree[50001];
int rank1[50001]; //记录节点相对其根节点的偏移量，有三个值表征：0表示节点和根节点同类；1表示根节点吃节点；2表示节点吃根节点
int find_root(int x){
    if(Tree[x]==-1) return x;
    else{
        int tmp=find_root(Tree[x]);
        rank1[x]+=rank1[Tree[x]]; //更新 x的偏移量从相对Tree[x]的偏移到相对整个树的根节点的偏移
        rank1[x]%=3;
        Tree[x]=tmp;
        return tmp;
    }
}
int main(){
    cin>>N>>K;
    memset(Tree,-1,sizeof(Tree));
    memset(rank1,0,sizeof(rank1));
    cnt=0;
    for(int i=0;i<K;i++){
        cin>>D>>X>>Y;
        if(X>N||Y>N){
            cnt++;
            continue;
        }
        int root1=find_root(X);
        int root2=find_root(Y);
        if(root1==root2){
            if(D==1 && rank1[X]!=rank1[Y]) cnt++;
            if(D==2 && (rank1[X]+1)%3!=rank1[Y]) cnt++;
        }
        else{ //X与Y根节点不一样，说明二者之前并无联系，那么关系无论如何肯定是成立的
            if(D==1){
                Tree[root2]=root1;
                rank1[root2]=rank1[X]-rank1[Y]; //可以自己画图去理解这个思路，因为X与Y等级一致，而X相对root1的等级为rank1[X]，
                //Y相对root2的等级为rank1[Y]，因为root2的根节点变为了root1，那么root2相对root1的等级应为 rank1[X]-rank1[Y] 才能使得之后Y相对root1的等级也为rank1[X]！
                rank1[root2]+=3;
                rank1[root2]%=3;
            }
            else{
                Tree[root2]=root1;
                rank1[root2]=rank1[X]-rank1[Y]+1; //同上面的分析~
                rank1[root2]+=3;
                rank1[root2]%=3;
            }
        }
    }
    cout<<cnt<<endl;
    return 0;
}
