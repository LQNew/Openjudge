/*
    输入描述:
        有多组数据，每组数据有两行，分别表示两个日期，形式为YYYYMMDD
    输出描述:
        每组数据输出一行，即日期差值
*/
//对于日期题，可以选择一个起始时间，以它为相对时间去计算差值，代码更易于书写~
#include<iostream>
#include<cmath>
using namespace std;
int original_,final_;
int original_year,final_year;
int original_month,final_month;
int original_date,final_date;

int days[2][12]={31,28,31,30,31,30,31,31,30,31,30,31,
                 31,29,31,30,31,30,31,31,30,31,30,31 };

bool judge_year(int year)
{
    if(year%100!=0&&year%4==0||year%400==0)
        return true;
    else
        return false;
}

int days_all(int year,int month,int date)
{
    int days_diff=0;
    for(int i=0;i<year;i++)
    {
        if(judge_year(i))
            days_diff+=366;
        else
            days_diff+=365;
    }
    for(int i=1;i<month;i++)
    {
        days_diff+=days[judge_year(year)][i-1];
    }
    days_diff+=date;
    return days_diff;
}
int main()
{
    while(cin>>original_>>final_)
    {
        original_year=original_/10000;
        final_year=final_/10000;
        original_month=(original_%10000)/100;
        final_month=(final_%10000)/100;
        original_date=original_%100;
        final_date=final_%100;
        cout<<abs(days_all(final_year,final_month,final_date)-days_all(original_year,original_month,original_date)+1)<<endl;
    }
    return 0;
}
