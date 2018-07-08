/*
    其实只需算出出发时间>=0的陪伴人到达终点的时间就可以了，因为如果陪伴人出发时间>=0并且最先到达的话那么他肯定是追上来的，也就是说维维会跟上他，
    并且到达时间最短。而出发时间<0的陪伴人如果先到达，那么维维肯定追不上。如果后到达，维维不会跟着他。所以只用考虑>=0的就行了~
*/
//本道题用到了cmath库的ceil()函数用于上取整，此函数的使用可以了解下~
#include<iostream>
#include<cmath>
using namespace std;
const int INF=0X7FFFFFFF;
int N;
double vi;
int ti;
int min1;
int main(){
    while(cin>>N){
        if(N==0) break;
        min1=INF;
        for(int i=0;i<N;i++){
            cin>>vi>>ti;
            if(ti<0) continue;
            int t=ti+ceil((4.5/vi)*3600);
            min1=min(min1,t);
        }
        cout<<min1<<endl;
    }
    return 0;
}
