//Ë®Ìâ
#include<iostream>
#include<cmath>
using namespace std;
int p,e,l,d;
int main(){
    cin>>p>>e>>l>>d;
    int t=d;
    while(1){
        t++;
        if((abs(t-p)%23==0)&&(abs(t-e)%28==0)&&(abs(t-l)%33==0)) break;
    }
    cout<<t-d<<endl;
    return 0;
}
