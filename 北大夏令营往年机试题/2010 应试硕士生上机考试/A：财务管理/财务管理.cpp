//Ë®Ìâ
#include<iostream>
#include<iomanip>
using namespace std;
double ans;
double a;
int main(){
    ans=0.0;
    for(int i=0;i<12;i++){
        cin>>a;
        ans+=a;
    }
    cout<<'$'<<fixed<<setprecision(2)<<ans/12.0<<endl;
    return 0;
}
