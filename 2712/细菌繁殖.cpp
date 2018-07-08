/*
    描述
        一种细菌的繁殖速度是每天成倍增长。例如：第一天有10个，第二天就变成20个，第三天变成40个，第四天变成80个，……。
        现在给出第一天的日期和细菌数目，要你写程序求出到某一天的时候，细菌的数目。
    输入
        第一行有一个整数n，表示测试数据的数目。其后n行每行有5个整数，整数之间用一个空格隔开。第一个数表示第一天的月份，第二个数表示第一天的日期，
        第三个数表示第一天细菌的数目，第四个数表示要求的那一天的月份，第五个数表示要求的那一天的日期。
        已知第一天和要求的一天在同一年并且该年不是闰年，要求的一天一定在第一天之后。数据保证要求的一天的细菌数目在长整数（long）范围内。
    输出
        对于每一组测试数据，输出一行，该行包含一个整数，为要求的一天的细菌数。
*/
//分析，数据输入中提到保证细菌数目在长整型范围内，所以考虑对于数目的存储用long长整型表示
//对于各个月份的日期数计算，可以先用一个数组将月份的日期数存储于其中，这样可以节省时间开销，总体来说题目难度不大
#include<iostream>
using namespace std;
int n;
int initial_month,initial_date,last_month,last_date;
long initial_num;
int month[13]={0,31,28,31,30,31,30,31,31,30,31,30,31}; //数组下标为0号没有作用，故随便赋值0给这个元素

long Pow(long initial_num,int days) //计算细菌的繁殖数
{
    while(days--)
        initial_num*=2;
    return initial_num;
}

int compute_days(int initial_month,int initial_date,int last_month,int last_date) //计算相差的日期数
{
    int days=0;
    if(initial_month==last_month)
    {
        days=last_date-initial_date;
        return days;
    }
    else
    {
        for(int i=initial_month+1;i<last_month;i++)
            days+=month[i];
        days+=month[initial_month]-initial_date+last_date;
        return days;
    }
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>initial_month>>initial_date>>initial_num>>last_month>>last_date;
        int days=compute_days(initial_month,initial_date,last_month,last_date);
        long last_num=Pow(initial_num,days);
        cout<<last_num<<endl;
    }
    return 0;
}
