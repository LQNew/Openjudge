//正统解法，其实我的打表做法已经很接近最真实的做法，就是比如n位数时，第一位为0，接下来数就是找(n-1)位的数值；如果第一位为1，那么第二位一定为0，不过接下来
//就可以是(n-2)位的数值！
#include<iostream>
using namespace std;
long long a[46];
int cnt;
int x;
int main(){
    a[1]=2;
    a[2]=3;
    for(int i=3;i<46;i++){
        a[i]=a[i-1]+a[i-2];
    }
    cin>>cnt;
    for(int i=0;i<cnt;i++){
        cin>>x;
        cout<<"Scenario #"<<i+1<<":"<<endl;
        cout<<a[x]<<endl;
        cout<<endl;
    }
    return 0;
}
