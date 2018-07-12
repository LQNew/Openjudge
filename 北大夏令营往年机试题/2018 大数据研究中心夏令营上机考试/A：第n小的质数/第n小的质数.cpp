#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int cnt=0;
    for(int i=2;;i++){
        int j;
        for(j=2;j<=sqrt(i);j++){
            if(i%j==0) break;
        }
        if(j>sqrt(i)){
            cnt++;
            cout<<i<<',';
        }
        if(cnt>=10000) break;
    }
    return 0;

}
