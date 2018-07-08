//本是送分题，但是还挺卡人的，要有那个思维!!
#include<iostream>
using namespace std;
int n;
int main(){
    int cnt,tmp;
    while(cin>>n)
    {
        tmp=1;
        cnt=1;
        while(tmp) //模拟每次的除法运算，因为关心的是余数，所以其他并不关心，要有数学结合程序的思维!!
        {
            tmp=tmp*10+1;
            cnt++;
            tmp%=n;
        }
        cout<<cnt<<endl;
    }
    return 0;
}
