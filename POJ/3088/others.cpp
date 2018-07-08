#include<cstdio>
#include<cstring>
using namespace std;
typedef long long LL;
LL s[12][12],c[12][12],f[12];
int main()
{
    s[0][0]=1;
    c[0][0]=1;
    f[0]=1;
    for(int i=1; i<=11; i++)
    {
        f[i]=f[i-1]*i;
        s[i][0]=0;
        s[i][i]=1;
        c[i][0]=c[i][i]=1;
        for(int j=1; j<i; j++)
        {
            s[i][j]=s[i-1][j-1]+j*s[i-1][j];
            c[i][j]=c[i-1][j-1]+c[i-1][j];
        }
    }
    int T,n,ca=0;
    for(scanf("%d",&T); T; T--)
    {
        scanf("%d",&n);
        LL ans=0;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=i;j++)
                ans+=c[n][i]*s[i][j]*f[j];
        printf("%d %d %lld\n",++ca,n,ans);
    }
    return 0;
}
