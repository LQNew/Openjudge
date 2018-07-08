//Ë®Ìâ
#include<iostream>
using namespace std;
int a,b;
int main(){
    cin>>a;
    if(a%2) cout<<0<<' '<<0<<endl;
    else{
        b=a%4;
        cout<<b/2+a/4<<' '<<a/2<<endl;
    }
    return 0;
}
