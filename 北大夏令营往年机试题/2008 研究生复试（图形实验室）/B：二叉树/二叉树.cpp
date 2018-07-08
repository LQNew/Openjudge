//Ë®Ìâ
#include<iostream>
using namespace std;
int x,y;
int main(){
    cin>>x>>y;
    while(x!=y){
        if(x>y) x=x/2;
        else y=y/2;
    }
    cout<<x<<endl;
    return 0;
}
