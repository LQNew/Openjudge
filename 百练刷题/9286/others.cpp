#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
#define LL long long

int n,m,p;
LL c[20][20],f[20][20];

void clear()
{
    memset(f,0,sizeof(f));
}
int main()
{
    for (int i=0;i<=15;++i) c[i][0]=1;
    for (int i=1;i<=15;++i)
        for (int j=1;j<=15;++j)
            c[i][j]=c[i-1][j]+c[i-1][j-1];

    while (~scanf("%d%d%d",&n,&m,&p))
    {
        if (!n&&!m&&!p) break;
        clear();

        for (int i=p;i<=n;++i) f[i][1]=c[n][i];
        for (int i=p;i<=n;++i)
            for (int j=2;j<=m;++j)
            {
                for (int k=p;k<=i;++k)
                    if (i-k>=0)
                       f[i][j]+=f[i-k][j-1]*c[n-i+k][k];
            }
        printf("%lld\n",f[n][m]);
    }
}
