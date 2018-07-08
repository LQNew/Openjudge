//Ë®Ìâ
#include<iostream>
using namespace std;
int a[16];
int main(){
    int i=0;
    int cnt=0;
    while(cin>>a[i]){
        if(a[i]==0) break;
        i++;
    }
    for(int j=0;j<=i-1;j++){
        for(int k=j+1;k<=i;k++){
            if(a[j]==2*a[k]||a[k]==2*a[j]) cnt++;
        }
    }
    cout<<cnt<<endl;
    return 0;
}
