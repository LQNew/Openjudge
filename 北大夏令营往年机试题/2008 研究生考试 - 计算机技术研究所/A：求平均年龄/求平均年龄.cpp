//Ë®Ìâ
#include<iostream>
#include<iomanip>
using namespace std;
int n;
int a[100];
double ans;
int main(){
    ans=0;
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) ans+=a[i];
    cout<<fixed<<setprecision(2)<<ans/n<<endl;
    return 0;
}
