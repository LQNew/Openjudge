//Ë®Ìâ
#include<iostream>
#include<iomanip>
using namespace std;
int n;
double a;
double ans;
int main(){
    cin>>n;
    ans=0;
    for(int i=0;i<n;i++){
        cin>>a;
        ans+=a;
    }
    cout<<fixed<<setprecision(2)<<double(ans/n)<<endl;
    return 0;
}
