//网上他人的解法，可以全部样例 AC
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;
#define N 5010
#define mod 1000007
int f[N][N];
int main()
{
    int n,m,kk;
    scanf("%d%d%d",&n,&m,&kk);
    for (int j=0;j<=kk&&j<=n;j++)
      f[1][j]=1;
    for (int i=2;i<=m;i++)
    {
     f[i][0]=1;
     for (int j=1;j<=n;j++)
     {
      f[i][j]=(f[i-1][j]+f[i][j-1])%mod;//f[i-1][j]
      if (j>kk) f[i][j]=(f[i][j]+mod-f[i-1][j-kk-1])%mod;
     }
    }
    printf("%d\n",f[m][n]);
    return 0;
}
