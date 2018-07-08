/*
    描述
        求两个不超过200位的非负整数的积。
    输入
        有两行，每行是一个不超过200位的非负整数，没有多余的前导0。
    输出
        一行，即相乘后的结果。结果里不能有多余的前导0，即如果结果是342，那么就不能输出为0342。
*/
//分析：关于乘法操作，需要模拟的是每位的乘法得出的结果先到指定位的操作，然后再去处理相邻位存在进位的情况
//开一个大数组去存储乘法进位时的每位的数值
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
char num1[201]; //输入的乘数1
char num2[201];//输入的乘数2
unsigned int mul[410];//存储输出的乘法之和的数，可以去分析 9*9这样的情况扩展到多位乘数的情况，可知对于200位*200位的乘法运算，顶多也就是产生400位的乘积
int len_num1; //输入的乘数1的长度
int len_num2;//输入的乘数2的长度
void multiply() //乘法操作
{
    for(int j=0;j<len_num2;j++)
        for(int i=0;i<len_num1;i++)
            mul[i+j]+=(num1[i]-48)*(num2[j]-48); //计算每次对应的乘积值
    for(int k=0;k<len_num2+len_num1-1;k++)// 处理进位
    {
        int a=mul[k];
        mul[k]=a%10;
        mul[k+1]+=a/10;
    }
}
int main()
{
    memset(mul,0,sizeof(mul[0])*410); //对于数组进行初始化
    cin>>num1>>num2;
    len_num1=strlen(num1);
    len_num2=strlen(num2);
    reverse(num1,num1+len_num1); //将输入的字符串数组逆序 留意reverse函数的使用，此处逆序的是 num1[0]~num1[len_num1-1]的元素
    reverse(num2,num2+len_num2); //将输入的字符串数组逆序
    multiply();
    if(mul[len_num2+len_num1-1]) //如果乘法发生了进位
    {
        for(int i=len_num2+len_num1-1;i>=0;i--)//逆序从高位到低位打印数据
            cout<<mul[i];
        cout<<endl;
    }
    else
    {
        for(int i=len_num2+len_num1-2;i>=0;i--)//逆序从高位到低位打印数据
            cout<<mul[i];
        cout<<endl;
    }
}
