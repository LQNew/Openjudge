#include<iostream>
using namespace std;
int N;
long long steps[21];
int main(){
    steps[1]=0;
    steps[2]=1;
    for(int i=3;i<=20;i++){
        steps[i]=(i-1)*steps[i-1]+(i-1)*steps[i-2];
    }
    while(cin>>N){
        cout<<steps[N]<<endl;
    }
    return 0;
}
