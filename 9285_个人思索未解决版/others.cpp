#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
#define Mod 1000007
#define N 5005

int n,m,k;
int f[N][N];

int main()
{
    scanf("%d%d%d",&m,&n,&k);

    f[0][0]=1;
    for (int i=1;i<=n;++i)
    {
        f[i][0]=1;
        for (int j=1;j<=m;++j)
        {
            for (int p=0;p<=min(j,k);++p)
                f[i][j]=(f[i][j]+f[i-1][j-p])%Mod;
        }
    }
    printf("%d\n",f[n][m]);
}
