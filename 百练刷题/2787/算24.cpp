/*
    描述
        给出4个小于10个正整数，你可以使用加减乘除4种运算以及括号把这4个数连接起来得到一个表达式。现在的问题是，
        是否存在一种方式使得得到的表达式的结果等于24。这里加减乘除以及括号的运算结果和运算的优先级跟我们平常的定义一致（这里的除法定义是实数除法）。
        比如，对于5，5，5，1，我们知道5 * (5 – 1 / 5) = 24，因此可以得到24。又比如，对于1，1，4，2，我们怎么都不能得到24。
    输入
        输入数据包括多行，每行给出一组测试数据，包括4个小于10个正整数。最后一组测试数据中包括4个0，表示输入的结束，这组数据不用处理。
    输出
        对于每一组测试数据，输出一行，如果可以得到24，输出“YES”；否则，输出“NO”。
*/
//分析：此道题其实就是递归，暴力求解，就是把所有的情况均遍历完，每次选取所剩元素中的两个进行运算，直至最后所剩元素数为1时结束
//此处的递归方法也应多去理解理解！
//本道题亮点之处在于判定两数是否相等时，由于是double运算，double型表示可能某些数无法准确表述，于是引入了从cmath库的fabs()用于计算两个数差值的绝对值
//并定义一个double型极小数，用于辅助判别二者是否相等~
#include<iostream>
#include<cmath>
using namespace std;
const double th=1e-6;
double a[4];

bool judge(int n)
{
    if(n==1)
    {
        if(fabs(a[0]-24)<th) //判别最后得到的元素值是否为24
            return true;
        else
            return false;
    }
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            double a1=a[i];
            double b=a[j];
            a[j]=a[n-1];
            a[i]=a1+b;
            if(judge(n-1)) return true;
            a[i]=a1-b;
            if(judge(n-1)) return true;
            a[i]=b-a1;
            if(judge(n-1)) return true;
            a[i]=a1*b;
            if(judge(n-1)) return true;

            if(fabs(b)>th) //判别除数是否为0
            {
                a[i]=a1/b;
                if(judge(n-1)) return true;
            }
            if(fabs(a1)>th) //判别除数是否为0
            {
                a[i]=b/a1;
                if(judge(n-1)) return true;
            }
            a[i]=a1;
            a[j]=b;
        }
    }
    return false;
}
int main()
{
    cin>>a[0]>>a[1]>>a[2]>>a[3];
    while(!(a[0]==0||a[1]==0||a[2]==0||a[3]==0))
    {
        if(judge(4))
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
        cin>>a[0]>>a[1]>>a[2]>>a[3];
    }
    return 0;
}
