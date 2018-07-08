/*
    描述
        求两个大的正整数相除的商。
    输入
        第1行是被除数，第2行是除数。每个数均不超过100位。
    输出
        一行，相应的商的整数部分
*/
//分析：大整数除法是高精度运算中蛮复杂的一个运算，较于大整数加法及大整数乘法，此种运算应该难度最大
//先写出 大整数减法的运算规则，对于除法就是从高位除起，对于每一位的除法都是采用了减法计数，循环减法，逐位记值，但是用到的trick可能较多，思路不是很清晰的写法...
//本道题中用到了 cstring库中的 memeset()对于数组初始化；memcpy()对于数组进行复制运算；以及algorithm库中的reverse()函数对于数组进行翻转作用
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
char num1[101]; //输入的数一，被除数
char num2[101]; //输入的数二，除数
unsigned int division[100];//输出的商
int minus_1[110]; //存储被减数 及减后的值
int a[110]; //存储被减数
int b[200]; //存储减数，因为本程序中使用了一些小trick，所以为了保证程序的运行，需要开一个较大空间的数组
int length_minus; //记录被除数与除数之间的长度差值

bool minus_(int length,int flag)
{
    for(int i=0;i<length;i++)
        minus_1[i]=a[i]-b[i+length_minus-flag]; //逐位减法运算，并且是通过flag确定除数后面加0个数
    for(int i=0;i<length;i++)
    {
        int c=minus_1[i]; //减法运算后 对各个位判别是否发生借位情况
        if(c<0)
        {
            minus_1[i]+=10;
            minus_1[i+1]-=1;
        }
    }
    if(minus_1[length]<0) //当最高位存在借位时，说明此次减法运算不成立
    {
        memset(minus_1,0,sizeof(minus_1[0])*110);//将存储差值的数组清0，以防此次运算后的差值数据将接下来循环运算的减法运算差值覆盖
        return false;
    }
    else //否则的话，此次减法运算成立
    {
        memcpy(a,minus_1,sizeof(minus_1[0])*110); //将减法运算后的数值赋给a数组
        memset(minus_1,0,sizeof(minus_1[0])*110); //将存储差值的数组清0
        return true;
    }
}

int main()
{
    memset(a,0,sizeof(a[0])*100); //数组 a初始化
    memset(b,0,sizeof(b[0])*200); //数组 b初始化
    memset(division,0,sizeof(division[0])*100); //数组division初始化
    cin>>num1>>num2;
    int length_num1=strlen(num1);
    int length_num2=strlen(num2);
    reverse(num1,num1+length_num1); //将输入的字符串数组逆序 留意reverse函数的使用，此处逆序的是 num1[0]~num1[len_num1-1]的元素
    reverse(num2,num2+length_num2); //将输入的字符串数组逆序
    length_minus=length_num1-length_num2;//记录被除数与除数长度的差值，因为二者均为正数，所以所以二者差值若小于0，则被除数小于除数，那么商定为0
    if(length_minus<0)
        cout<<0<<endl;
    else
    {
        for(int i=0;i<length_num1;i++)
            a[i]=num1[i]-48;
        for(int j=0;j<length_num2;j++)
            b[j+length_minus]=num2[j]-48;//前length_minus个位置空位为0，用于辅以标识之后运算 除数之后应补多少位0
        for(int i=length_minus;i>=0;i--)
        {
            while(minus_(length_num1,i))
                division[i]++;
        }
        bool judge=true;
        if(length_minus==0&&!division[0])//如果二者长度一致，同时商未有变化，同样说明 被除数小于除数，商为0
            cout<<0<<endl;
        else
        {
            for(int i=length_minus;i>=0;i--)
            {
                if(!division[i]&&judge) //用了一个标识附 judge，用于去除商高位的0
                    judge=true;
                else
                {
                    judge=false;
                    cout<<division[i];
                }
            }
        cout<<endl;
        }
    }
}
