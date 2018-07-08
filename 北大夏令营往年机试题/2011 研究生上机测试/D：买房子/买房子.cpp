//Ë®Ìâ
#include<iostream>
using namespace std;
double N,K;
double a;
double rate;
double bonus;
int main(){
    a=200;
    cin>>N>>K;
    rate=K/100.0+1.0;
    bonus=N;
    int i;
    for(i=1;i<=20;i++){
        if(bonus>a){
            cout<<i<<endl;
            break;
        }
        bonus+=N;
        a*=rate;
    }
    if(i==21) cout<<"Impossible"<<endl;
    return 0;
}
