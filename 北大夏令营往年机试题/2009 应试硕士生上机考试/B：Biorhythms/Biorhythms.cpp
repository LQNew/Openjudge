//Ë®Ìâ
#include<iostream>
#include<cmath>
using namespace std;
int p,e,l,d;
int main(){
    int cnt=0;
    while(1){
        cin>>p>>e>>l>>d;
        if(p==-1&&e==-1&&l==-1&&d==-1) break;
        cnt++;
        int t=d;
        while(1){
            t++;
            if((abs(t-p)%23==0)&&(abs(t-e)%28==0)&&(abs(t-l)%33==0)) break;
        }
        cout<<"Case "<<cnt<<": the next triple peak occurs in "<<t-d<<" days."<<endl;
    }
    return 0;
}
