//Ë®Ìâ
#include<iostream>
using namespace std;
int a;
int b;
int ans;
int main(){
    cin>>a;
    ans=0;
    for(int i=0;i<5;i++){
        cin>>b;
        if(b<a) ans+=b;
    }
    cout<<ans<<endl;
    return 0;
}
