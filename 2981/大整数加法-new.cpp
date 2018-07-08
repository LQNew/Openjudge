/*
    描述
        求两个不超过200位的非负整数的和。
    输入
        有两行，每行是一个不超过200位的非负整数，可能有多余的前导0。
    输出
        一行，即相加后的结果。结果里不能有多余的前导0，即如果结果是342，那么就不能输出为0342。
*/
//分析，对于题目的处理较之解法一可能方法上更直白，没有那么巧的设计了，就是单纯地各位相加后，再逐个看每位是否会产生进位
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
char num1[201]; //输入的数
char num2[201]; //输入的数
unsigned int add[210]; //输出的和
int len_num1;
int len_num2;
void add_1()
{
    if(len_num1>len_num2) //加数1长度>加数2长度
    {
        for(int i=0;i<len_num2;i++) //计算指定位的加数和
            add[i]=(num1[i]-48)+(num2[i]-48);
        for(int i=len_num2;i<len_num1;i++)
            add[i]=num1[i]-48;
        for(int k=0;k<len_num1;k++) //计算各个位的进位
        {
            int a=add[k];
            add[k]=a%10;
            add[k+1]+=a/10;
        }
    }
    else //加数1长度<加数2长度
    {
        for(int i=0;i<len_num1;i++) //计算指定位的加数和
            add[i]=(num1[i]-48)+(num2[i]-48);
        for(int i=len_num1;i<len_num2;i++)
            add[i]=num2[i]-48;
        for(int k=0;k<len_num2;k++) //计算各个位的进位
        {
            int a=add[k];
            add[k]=a%10;
            add[k+1]+=a/10;
        }
    }
}
int main()
{
    memset(add,0,sizeof(add[0])*210); //数组用0初始化
    cin>>num1>>num2;
    len_num1=strlen(num1);
    len_num2=strlen(num2);
    reverse(num1,num1+len_num1); //将输入的字符串数组逆序 留意reverse函数的使用，此处逆序的是 num1[0]~num1[len_num1-1]的元素
    reverse(num2,num2+len_num2); //将输入的字符串数组逆序
    add_1();
    bool c=true; //校验参数
    for(int i=max(len_num1,len_num2);i>=0;i--) //用于判别去除高位上虚晃的0，用了一些小trick，但是可能会有更简洁的方式...
    {
        if(add[i]==0&&i>0&&c)
            c=true;
        else
        {
            c=false;
            cout<<add[i];
        }
    }
    cout<<endl;
}

