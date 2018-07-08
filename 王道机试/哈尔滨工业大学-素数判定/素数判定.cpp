#include<iostream>
#include<cmath>
using namespace std;
int n;
int main()
{
    while(cin>>n)
    {
        if(n<=1)
        {
            cout<<"no"<<endl;
            continue;
        }
        else
        {
            int i;
            for(i=2;i<=sqrt(n);i++)
            {
                if(n%i==0)
                {
                    cout<<"no"<<endl;
                    break;
                }
            }
            if(i>sqrt(n)) cout<<"yes"<<endl;
        }
    }
    return 0;
}
