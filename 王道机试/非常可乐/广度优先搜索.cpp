//给出三个杯子容量，和可乐的容量，要求平分可乐
//使用四元组（x，y，z，t）来表示一个状态，其中 x、y、z 分别表示三个瓶子中的可乐体积，t 表示从初始状态到该状态所需的杯子间互
//相倾倒的次数。状态间的相互扩展，就是任意四元组经过瓶子间的相互倾倒而得到若干组新的四元组的过程。这样，当平分的状态第一次被搜索出来以后，其状
//态中表示的杯子倾倒次数即是所求。
//本道题实际上还是脑海中有搜索树的概念，然后利用BFS求解状态，难度不大，注意倾倒必须每次倒满这个前提的调节~
#include<iostream>
#include<queue>
using namespace std;
struct Node{
    int a,b,c;
    int t;
};
int S,M,N;
bool mark[101][101][101];
queue<Node>Q;
void exchange(int &a,int sa,int &b,int sb){ //杯子是没有刻度的，每次只能整杯整杯地倒入~
    if(sb-b>=a){
        b+=a;
        a=0;
    }
    else{
        a-=(sb-b);
        b=sb;
    }
}
int BFS(){
    while(!Q.empty()){
        Node new_1=Q.front();
        Q.pop();
        //six branches taken in count
        int na=new_1.a;
        int nb=new_1.b;
        int nc=new_1.c;
        exchange(na,S,nb,M);
        if(mark[na][nb][nc]==false){
            mark[na][nb][nc]=true;
            Node tmp;
            tmp.a=na;
            tmp.b=nb;
            tmp.c=nc;
            tmp.t=new_1.t+1;
            if(na==S/2&&nb==S/2) return tmp.t;
            if(na==S/2&&nc==S/2) return tmp.t;
            if(nc==S/2&&nb==S/2) return tmp.t;
            Q.push(tmp);
        }
        na=new_1.a;
        nb=new_1.b;
        nc=new_1.c;
        exchange(na,S,nc,N);
        if(mark[na][nb][nc]==false){
            mark[na][nb][nc]=true;
            Node tmp;
            tmp.a=na;
            tmp.b=nb;
            tmp.c=nc;
            tmp.t=new_1.t+1;
            if(na==S/2&&nb==S/2) return tmp.t;
            if(na==S/2&&nc==S/2) return tmp.t;
            if(nc==S/2&&nb==S/2) return tmp.t;
            Q.push(tmp);
        }
        na=new_1.a;
        nb=new_1.b;
        nc=new_1.c;
        exchange(nb,M,na,S);
        if(mark[na][nb][nc]==false){
            mark[na][nb][nc]=true;
            Node tmp;
            tmp.a=na;
            tmp.b=nb;
            tmp.c=nc;
            tmp.t=new_1.t+1;
            if(na==S/2&&nb==S/2) return tmp.t;
            if(na==S/2&&nc==S/2) return tmp.t;
            if(nc==S/2&&nb==S/2) return tmp.t;
            Q.push(tmp);
        }
        na=new_1.a;
        nb=new_1.b;
        nc=new_1.c;
        exchange(nc,N,na,S);
        if(mark[na][nb][nc]==false){
            mark[na][nb][nc]=true;
            Node tmp;
            tmp.a=na;
            tmp.b=nb;
            tmp.c=nc;
            tmp.t=new_1.t+1;
            if(na==S/2&&nb==S/2) return tmp.t;
            if(na==S/2&&nc==S/2) return tmp.t;
            if(nc==S/2&&nb==S/2) return tmp.t;
            Q.push(tmp);
        }
        na=new_1.a;
        nb=new_1.b;
        nc=new_1.c;
        exchange(nb,M,nc,N);
        if(mark[na][nb][nc]==false){
            mark[na][nb][nc]=true;
            Node tmp;
            tmp.a=na;
            tmp.b=nb;
            tmp.c=nc;
            tmp.t=new_1.t+1;
            if(na==S/2&&nb==S/2) return tmp.t;
            if(na==S/2&&nc==S/2) return tmp.t;
            if(nc==S/2&&nb==S/2) return tmp.t;
            Q.push(tmp);
        }
        na=new_1.a;
        nb=new_1.b;
        nc=new_1.c;
        exchange(nc,N,nb,M);
        if(mark[na][nb][nc]==false){
            mark[na][nb][nc]=true;
            Node tmp;
            tmp.a=na;
            tmp.b=nb;
            tmp.c=nc;
            tmp.t=new_1.t+1;
            if(na==S/2&&nb==S/2) return tmp.t;
            if(na==S/2&&nc==S/2) return tmp.t;
            if(nc==S/2&&nb==S/2) return tmp.t;
            Q.push(tmp);
        }
    }
    return -1;
}
int main(){
    while(cin>>S>>M>>N){
        if(S==0&&M==0&N==0) break;
        if(S%2!=0) cout<<"NO"<<endl;
        else{
            for(int i=0;i<=S;i++){
                for(int j=0;j<=M;j++){
                    for(int k=0;k<=N;k++)
                        mark[i][j][k]=false;
                }
            }
            Node tmp;
            tmp.a=S;
            tmp.b=0;
            tmp.c=0;
            tmp.t=0;
            while(!Q.empty()) Q.pop();
            Q.push(tmp);
            int time=BFS();
            if(time==-1) cout<<"NO"<<endl;
            else cout<<time<<endl;
        }
    }
    return 0;
}
