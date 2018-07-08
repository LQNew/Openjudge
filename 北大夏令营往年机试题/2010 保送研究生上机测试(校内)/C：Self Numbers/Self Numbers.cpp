//Ë®Ìâ
#include<iostream>
#include<cstring>
using namespace std;
bool mark[10000];
int main(){
    int cnt=1;
    memset(mark,0,sizeof(mark));
    while(cnt<10000){
        int ans=0;
        int num=cnt;
        while(num!=0){
            ans+=num%10;
            num/=10;
        }
        mark[cnt+ans]=true;
        cnt++;
    }
    for(int i=1;i<10000;i++){
        if(!mark[i]) cout<<i<<endl;
    }
    return 0;
}
