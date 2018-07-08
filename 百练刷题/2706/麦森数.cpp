 /*
    从文件中输入P (1000<P<3100000) ,计算2^p-1的位数和最后500位数字（用十进制高精度数表示）
    输入
        文件中只包含一个整数P(1000<P<3100000)
    输出
        第1行：十进制高精度数2^p-1的位数。
        第2-11行：十进制高精度数2^p-1的最后500位数字。（每行输出50位，共输出10行，不足500位时高位补0）
*/
//分析，利用快速幂思路求得2^p-1的值以及log10()函数求得位数，具体详解可看 求2的幂次项的程序注释以及word总结~
#include<iostream>
#include<cmath>
#include<cstring>
#include<iomanip>
using namespace std;
int p; //输入的幂次P
double cnt;//记录位数
int decomposition[24];//存储P的分解值
long long result[100]; //输出结果数组
long long num1[100];//乘数
long long mid[101]; //中间值
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

void multiply(long long *num1,long long *num2,long long *mid) //因为只要后500位数，所以每次只计算后五百位的值
{
    for(int i=0;i<100;i++)
    {
        for(int j=0;j<100;j++)
        {
            if(i+j<100)
                mid[i+j]+=num1[i]*num2[j];
        }
    }
    for(int i=0;i<100;i++)
    {
        if(mid[i]>100000) //处理进位的情况
        {
            mid[i+1]+=mid[i]/100000;
            mid[i]=mid[i]%100000;

        }
    }
    memcpy(num1,mid,sizeof(mid[0])*100);
    memset(mid,0,sizeof(mid[0])*101);
}

int main()
{
    cin>>p;
    memset(num1,0,sizeof(long long)*100); //数组初始化
    memset(result,0,sizeof(long long)*100);
    memset(mid,0,sizeof(long long)*101);
    num1[0]=2;
    result[0]=1;
    cnt=ceil(p*log(2)/log(10)); //技巧 分析 2^p-1与2^p的个位数可知，它与 2^p的位数是一致
    Decomposition();
    if(decomposition[0])
        result[0]=2;
    for(int i=1;i<24;i++)
    {
        multiply(num1,num1,mid);
        if(decomposition[i])
            multiply(result,num1,mid);
    }
    cout<<cnt<<endl;
    int i=0;
    for(int j=99;j>0;j--) //输出打印数据
    {

        if(result[j])
            cout<<setfill('0')<<setw(5)<<result[j]; //对于5位数据 少于5位时进行补零操作
        else
            cout<<"00000";//如果为0，打印出5个0
        i++;
        if(i%10==0) //计数，没到50位即进行换行操作
            cout<<endl;
    }
    cout<<result[0]-1; //个位进行-1操作
    cout<<endl;
}
