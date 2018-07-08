#include<iostream>
#include<cstring>
using namespace std;
char num[20];
char num1[20];

int calculate_1()
{
    int sum=0;
    for(int i=0;i<strlen(num);i++)
    {
        for(int j=0;j<strlen(num1);j++)
        {
            sum+=(num[i]-'0')*(num1[j]-'0');
        }
    }
    return sum;
}
int main()
{
    while(cin>>num>>num1)
    {
        cout<<calculate_1()<<endl;
    }
    return 0;
}
