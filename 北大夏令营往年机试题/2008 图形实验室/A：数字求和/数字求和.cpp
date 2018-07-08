//Ë®Ìâ
#include<iostream>
using namespace std;
int a[6];
int main(){
    int ans=0;
    for(int i=0;i<6;i++) cin>>a[i];
    for(int i=1;i<6;i++){
        if(a[i]<a[0]) ans+=a[i];
    }
    cout<<ans<<endl;
    return 0;
}
