#include<iostream>
#include<iomanip>
using namespace std;
double num; //每月的结余
double total; //总结余
int main()
{
    total=0;
    for(int i=0;i<12;i++)
    {
        cin>>num;
        total+=num;
    }
    cout<<'$'<<fixed<<setprecision(2)<<total/12<<endl;
}
