//Ë®Ìâ
#include<iostream>
using namespace std;
int a,b;
char symbol;
int computer_layer(int a){
    if(a==0||a==1) return 1;
    else{
        int ans=1;
        for(int i=2;i<=a;i++) ans*=i;
        return ans;
    }
}
int main(){
    while(cin>>a){
        cin>>symbol;
        if(symbol=='!') cout<<computer_layer(a)<<endl;
        else{
            cin>>b;
            if(symbol=='*') cout<<a*b<<endl;
            else if(symbol=='/'){
                if(b==0) cout<<"error"<<endl;
                else cout<<a/b<<endl;
            }
            else if(symbol=='%'){
                if(b==0) cout<<"error"<<endl;
                else cout<<a%b<<endl;
            }
            else if(symbol=='+'){
                cout<<a+b<<endl;
            }
            else cout<<a-b<<endl;
        }
    }
    return 0;
}
