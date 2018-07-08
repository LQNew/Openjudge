/*
描述
在 skew binary表示中, 第 k 位的值xk表示xk*(2^(k+1)-1)。 每个位上的可能数字是0 或 1，最后面一个非零位可以是2, 例如, 10120(skew) = 1*(25-1) + 0*(24-1) + 1*(23-1) + 2*(22-1) + 0*(21-1) = 31 + 0 + 7 + 6 + 0 = 44. 前十个skew数是 0、1、2、10、11、12、20、100、101、以及102。
输入
输入包含一行或多行，每行包含一个整数n。 如果 n = 0 表示输入结束，否则n是一个skew 数
输出
对于每一个输入，输出它的十进制表示。转换成十进制后， n 不超过 2^31-1 = 2147483647
*/
//分析：此题比较简单，注意由于n是按十进制输入，那么n最大可为32位十进制形式，那么即使用long long型也无法存储输入的数据，于是要考虑到使用字符串存储数据
//关于字符串，此处需要了解的是：当求字符串的长度时，可以用strlen函数求解字符串的长度！
#include<iostream>
#include<string.h>
using namespace std;
int factor[31]; //用于存储各个位上的数字
int cnt; //用于记录输入数据的位数

int Power(int b) //求幂次的函数
{
    int res = 1;
    while (b--) res *= 2;
    return res;
}

int Get_value()//计算skew数
{
    int value=0;
    for(int i=0;i<cnt;i++)
    {
        value+=factor[i]*(Power(i+1)-1);
    }
    return value;

}

int main()
{
    char skew[32];
    while(cin>>skew)
    {
        cnt=strlen(skew);
        if(cnt==1&&skew[0]=='0') break; //比较是否输入为0
        for(int i=0;i<cnt;i++)
        {
            factor[i]=int(skew[cnt-1-i]-'0'); //分解字符串，转换为数字
        }

        cout<<Get_value()<<endl;
    }
    return 0;
}
