//题意：n+1个自然数，其中m是确定的，其他n个数都不超过m,有多少种方案使得 a1*x1+a2*x2+...+an*xn+M*xn+1 = 1 有解，
//即：gcd (a1, a2, ..., an, M) = 1，接下来对M进行素因子分解，然后排除公因子非1的情况即可

/*详析：
根据数论的知识，n个数的最大公约数规定为这n个数线性和的最小自然数，所以此题就是要求最大公约数为1的数列的个数，步骤如下：
1）求出m的所有质约数，假设有k个如果这n + 1个数的最大公约数不是1，m至少含有一个质约数，这个质约数也是前n个数的约数
2）序列的总个数为 m ^ n;
3）设t(n)表示 能够整除任意n个m的质约数且<=m的数的个数
利用容斥原理可知公约数不为1的数列的个数为 f = t(1) - t(2) + t(3) - ... + (-1) ^ (k - 1) t(k) (容斥原理，奇加偶减)
4) 符合要求的序列个数为 m ^ n - f
*/

#include<iostream>
using namespace std;
typedef long long ll; //对于M^n，因为输入数据M允许为较大值，故需要定义长整型数据类型为八字节
int M; //卡片的最大数M
int N; //卡片最大数前有N张数值<=M的卡片
int factor[65]; //用于存储分解出的质因数
int factor_for_dfs[65]; //用于在dfs搜索中存储质因数
int total_cnt; //用于记录M一共有多少个质因数
ll part_num;//用于计数有num个共同质因子时的组合数
ll f; //用于计数 f = t(1) - t(2) + t(3) - ... + (-1) ^ (k - 1) t(k)

void Divide(int M) //计算得到M所有的质因数
{
    total_cnt=0; //用于记录
    for(int i=2;i*i<=M;i++)
    {
        if(M%i==0)
            factor[total_cnt++]=i;
        while(M%i==0)
            M=M/i;
    }
    if (M>1) factor[total_cnt++]=M;
    //如果剩下的除后的最后一个数为>1的数，那么它便是最后一个质因数！ i.e: 30=2*3*5 ,而当未除至最后一个数之前，i^2肯定会小于当前M，只有可能除至最后一个因子时i^2>当前M
}

ll Power(int a,int b) //求解 a^b的值
{
    ll res = 1;
    while (b--) res *= a;
    return res;
}

void dfs(int pos ,int cnt , int num)  //深度优先搜索，搜索 M加上前n个数一共n+1个数中有num个共同质因子 的组合数
{
    int x;
    if(cnt == num)
    {
        x=M;
        for(int i=0;i<num;i++)
            x=x/factor_for_dfs[i];
        part_num+=Power(x,N);
    }
    else //dfs 递归思想想不到...
    {
        for(int i=pos;i<total_cnt;i++)
        {
            factor_for_dfs[cnt]=factor[i];
            dfs(i+1,cnt+1,num);
        }
    }

}

int main()
{
    while(cin>>N>>M)
    {
        Divide(M);
        f=Power(M,N); //计算 M^N
        for(int i=1;i<=total_cnt;i++) //计算 M^N-t(1)+t(2)-t(3)+.....
        {
            part_num=0;
            dfs(0,0,i);
            if(i%2==0)
                f+=part_num;
            else
                f-=part_num;

        }
        cout<<f<<endl;
    }
    return 0;

}
