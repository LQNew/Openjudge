//水题
#include<iostream>
#include<iomanip>
using namespace std;
char str1[20];
double ans;
int main(){
    gets(str1);
    double a;
    ans=0;
    cout<<"n e"<<endl;
    cout<<"- -----------"<<endl;
    for(int i=0;i<=9;i++){
        if(i==0) a=1;
        else a*=i;
        ans+=1.0/a;
        cout<<i<<' '<<setprecision(10)<<ans<<endl; //不加fixed 的setprecision是设置输出的最大位数
    }
    return 0;
}
