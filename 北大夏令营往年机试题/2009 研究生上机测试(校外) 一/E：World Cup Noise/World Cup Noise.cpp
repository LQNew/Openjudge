//Éú³É±í
#include<iostream>
using namespace std;
int cnt;
long long ans;
int x;

void sequence(int x,int j){
    if(x==1) ans++;
    else {
        if(j==1) sequence(x-1,0);
        else{
            sequence(x-1,0);
            sequence(x-1,1);
        }
    }
}
int main(){
    /*
    cin>>cnt;
    for(int i=0;i<cnt;i++){
        ans=0;
        cin>>x;
        sequence(x,1);
        sequence(x,0);
        cout<<ans<<endl;
    }
    */
    for(int i=1;i<45;i++){
        ans=0;
        sequence(i,0);
        sequence(i,1);
        cout<<ans<<',';
    }
    ans=0;
    sequence(45,0);
    sequence(45,1);
    cout<<ans<<endl;


}
