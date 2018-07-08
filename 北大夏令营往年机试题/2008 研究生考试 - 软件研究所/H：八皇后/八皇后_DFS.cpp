//深搜的一个很好的思路~，多多把玩！！
#include<iostream>
#include<cmath>
using namespace std;
int place[9];
int strategies[93][9];
int sum;
int n;
int b;

bool check(int k)
{
    for(int i=1;i<k;i++)
    {
        if(abs(i-k)==abs(place[i]-place[k])||place[i]==place[k])
            return false;
    }
    return true;
}

void Dfs(int level)
{
    if(level>8)
    {
        sum++;
        for(int i=1;i<=8;i++)
        {
            strategies[sum][i]=place[i];
        }
    }
    else
    {
        for(int col=1;col<=8;col++)
        {
            place[level]=col;
            if(check(level))
                Dfs(level+1);
        }
    }
}

int main()
{
    sum=0;
    Dfs(1);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>b;
        for(int j=1;j<=8;j++)
            cout<<strategies[b][j];
        cout<<endl;
    }
    return 0;
}
