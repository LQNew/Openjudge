//Ë®Ìâ
#include<iostream>
using namespace std;
int n;
int angle;
int main(){
    cin>>n;
    int ans=0;
    for(int i=0;i<n-1;i++){
        cin>>angle;
        ans+=angle;
    }
    int total=(n-2)*180;
    cout<<total-ans<<endl;
    return 0;
}
