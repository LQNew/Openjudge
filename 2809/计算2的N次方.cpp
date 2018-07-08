/*
    描述
        任意给定一个正整数N(N<=100)，计算2的n次方的值。
    输入
        输入一个正整数N。
    输出
        输出2的N次方的值。
*/
//分析:此道题几乎和麦森数那道题完全一样，难度较之麦森数更低，因为对于N，只是<=100，此处需要对于2的N次方有个概念，100次方大概也就撑死40多位
//1000多次方大概有300多位，有个概念在脑海里~
//由于是从麦森数那边直接复制粘贴过来的题解所以大致来说，就是首先将P分解为2的次方因式项，接下来，就是模拟2^p的运算操作，会发现每次乘积运算都是上一次的
//乘数自己平方，得到下一个乘数，下一个乘数再和当前的乘积相乘（此处应该蕴含着快速幂的思想，对于2的幂次，那么P就拆为2的幂次因式项）
//关于打印数据，此处有些小trick，因为高位为0的数不可打印，又因为此处采用了十万进制的运算，对于5位数如果不为0，那么高位还应补零，此时应代用iomanip库的
//etfill()函数以及setw()函数，这两个函数的使用一定要熟悉，因为cout函数较于C中的printf()函数对于进制转换要复杂些~
#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;
int p; //输入的次方值
int decomposition[7]; //存储分解的因子
long long result[100];//存储运算结果
long long num1[100];//当前的乘数
long long mid[101];//运算时用于传递的中间值

void Decomposition() //将p分解为2的因子式
{
    int p_1=p;
    int i=0;
    while(p_1!=0)
    {
        if(p_1%2)
        {
            decomposition[i]=1;
            p_1=p_1/2;
        }
        else
        {
            p_1=p_1/2;
            decomposition[i]=0;
        }
        i++;
    }
}

void multiply(long long *num1,long long *num2,long long *mid) //此处是已知2的一百次方顶多40多位，于是500位的数组去运算措措有余
{
    for(int i=0;i<100;i++)
    {
        for(int j=0;j<100;j++)
        {
            if(i+j<100)
                mid[i+j]+=num1[i]*num2[j]; //对应位的乘积
        }
    }
    for(int i=0;i<100;i++)
    {
        if(mid[i]>100000) //如果产生进位，那么将进位值传递给上一位
        {
            mid[i+1]+=mid[i]/100000;
            mid[i]=mid[i]%100000;
        }
    }
    memcpy(num1,mid,sizeof(mid[0])*100); //将中间值拷贝到当前的乘数
    memset(mid,0,sizeof(mid[0])*101);
}

int main()
{
    cin>>p;
    memset(num1,0,sizeof(long long)*100); //数组初始化为0
    memset(result,0,sizeof(long long)*100);
    memset(mid,0,sizeof(long long)*101);
    num1[0]=2; //第一个值为2^(2^0)=2
    result[0]=1;
    Decomposition();
    if(decomposition[0]) //如果第一位有分项，那么result为1*2=2
        result[0]=2;
    for(int i=1;i<7;i++) //迭代相乘，快速幂思想
    {
        multiply(num1,num1,mid);
        if(decomposition[i])
            multiply(result,num1,mid);
    }
    //输出打印
    int j;
    for(j=99;j>=0;j--)
    {
        if(result[j]!=0) //筛去高位的0项
            break;
    }
    cout<<result[j]; //第一个高位不须补零操作
    j--;
    for(j;j>=0;j--)
    {
        cout<<setfill('0')<<setw(5)<<result[j]; //后续位的数可进行补零操作
    }
    cout<<endl;
}
