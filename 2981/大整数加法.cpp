/*
    描述
        求两个不超过200位的非负整数的和。
    输入
        有两行，每行是一个不超过200位的非负整数，可能有多余的前导0。
    输出
        一行，即相加后的结果。结果里不能有多余的前导0，即如果结果是342，那么就不能输出为0342。
*/
//分析：本道题难度并不大，因为是高精度运算，只能采用数组模拟运算时的进位，逐位相加，挨个进位~
//本道题有一些小细节上的问题：如 输入的字符串是高位在数组的低位，此时应该将数组倒序排列下，此外对于不同数组，可能数组的长度不同，长度较短的数组应该进行填'0'操作，
//对于题目中，自身已经提到 对于高位的0不应输出，这需要一个判别
//对于200的非负整数相加，可能会产生进位，那么数组的大小应开得稍微大一些
//还应考虑 0+0的情况~ 可以见得此道题细节的考查较多，要多留心~
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
char num1[201]; //输入的数
char num2[201]; //输入的数
char add[205]; //相加之后的数
int main()
{
    cin>>num1>>num2;
    int len_num1=strlen(num1);
    int len_num2=strlen(num2);
    int a; //计数逐位相加时的本位和
    int b=0; //计数逐位相加时的进位数
    int i; //记录相加后的数组的元素位置
    reverse(num1,num1+len_num1); //将输入的字符串数组逆序 留意reverse函数的使用，此处逆序的是 num1[0]~num1[len_num1-1]的元素
    reverse(num2,num2+len_num2); //将输入的字符串数组逆序
    if(len_num1>len_num2)
        fill(num2+len_num2,num2+max(len_num2,len_num1),48); //对于数组元素进行 '0'填充，留意fill函数的使用
    else if(len_num1<len_num2)
        fill(num1+len_num1,num1+max(len_num2,len_num1),48);
    for(i=0;i<max(len_num1,len_num2);i++)
    {
        a=num1[i]+num2[i]-96+b; //获取每个位的相加之和
        if(a<10)
        {
            add[i]=a+48; //转换为ASCII码值
            b=0;
        }
        else
        {
            add[i]=a%10+48;
            b=a/10; //获取进位的数值
        }
    }
    if(b) //如果产生进位，将进位填至最高位
    {
        add[i]=b+48;
        i++;
    }
    if(strlen(add)==1&&add[0]=='0') //检测若是 0+0的情况
        cout<<add[0]<<endl;
    else //筛去高位的0
    {
        for(i;i--;i>=0)
        {
            if(add[i]=='0')
                continue;
            else
                break;
        }
        reverse(add,add+i+1);
        add[i+1]='\0';
        cout<<add<<endl;
    }
}
