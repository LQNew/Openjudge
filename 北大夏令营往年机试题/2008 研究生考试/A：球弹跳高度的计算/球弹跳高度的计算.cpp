//Ë®Ìâ
#include<iostream>
using namespace std;
double h;
double dist;
int main(){
    cin>>h;
    dist=0;
    for(int i=1;i<=10;i++){
        dist+=h;
        h/=2.0;
        dist+=h;
    }
    cout<<dist-h<<endl;
    cout<<h<<endl;
    return 0;
}
