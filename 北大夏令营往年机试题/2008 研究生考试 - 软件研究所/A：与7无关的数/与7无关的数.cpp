//Ë®Ìâ
#include<iostream>
#include<cstring>
using namespace std;
int n;
bool a[101];
bool related_to_seven(int x){
    if(x%7==0) return true;
    else{
        if(x<=10) return false;
        else if(x>10){
            int a=x/10;
            int b=x%10;
            if(a==7||b==7) return true;
            else return false;
        }
    }
}
int main(){
    memset(a,0,sizeof(a));
    for(int i=1;i<=100;i++){
        if(related_to_seven(i)) a[i]=true;
    }
    cin>>n;
    int ans=0;
    for(int i=1;i<=n;i++){
        if(!a[i]) ans+=(i*i);
    }
    cout<<ans<<endl;
    return 0;
}
