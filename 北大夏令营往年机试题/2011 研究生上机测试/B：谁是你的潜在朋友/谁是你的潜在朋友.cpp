//Ë®Ìâ
#include<iostream>
#include<cstring>
using namespace std;
int M,N;
int books[201];
int readers[201];
int main(){
    cin>>N>>M;
    memset(readers,0,sizeof(readers));
    for(int i=1;i<=N;i++) cin>>books[i];
    for(int i=1;i<=N;i++) readers[books[i]]++;
    for(int i=1;i<=N;i++){
        if(readers[books[i]]==1) cout<<"BeiJu"<<endl;
        else cout<<readers[books[i]]-1<<endl;
    }
    return 0;
}
