/*
    描述
        在我们现在使用的日历中, 闰年被定义为能被4整除的年份，但是能被100整除而不能被400整除的年是例外，它们不是闰年。
         给定从公元2000年1月1日开始逝去的天数，你的任务是给出这一天是哪年哪月哪日星期几。
    输入
        输入包含若干行，每行包含一个正整数，表示从2000年1月1日开始逝去的天数。输入最后一行是−1, 不必处理。可以假设结果的年份不会超过9999。
    输出
        对每个测试样例，输出一行，该行包含对应的日期和星期几。格式为“YYYY-MM-DD DayOfWeek”,
        其中 “DayOfWeek” 必须是下面中的一个："Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday" 或 "Saturday“。
*/
//分析：本题是计算年月日 周几 ；其中周几好得到，只需除7取余
//关于年月日，本题中是不断迭代减去年份的天数、月份的天数最后得到了年月日，方法是比较巧妙的！

#include<iostream>
#include<iomanip> //引入控制输出格式的头文件
using namespace std;
int year[2]={365,366}; //平年、闰年对应的天数
//两组month，分别对应平年、闰年的月份天数
int month[2][13]={0,31,28,31,30,31,30,31,31,30,31,30,31,
                  0,31,29,31,30,31,30,31,31,30,31,30,31};
char weekday[7][10]={"Saturday","Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
int days;

int type_year(int a) //判断是否为闰年
{
    if(a%4==0)
    {
        if(a%100==0&&a%400!=0)
            return 0;
        else
            return 1;
    }
    else
        return 0;
}

int main()
{
    cin>>days;
    while(days!=-1)
    {
        char*weekday_1=weekday[days%7];
        int i,j;
        for(i=2000;days>=year[type_year(i)];i++) //迭代减至对应的年份
            days-=year[type_year(i)];
        for(j=1;days>=month[type_year(i)][j];j++) //迭代减至相应的月份
            days-=month[type_year(i)][j];
        cout<<i<<"-"<<setfill('0')<<setw(2)<<j<<"-"<<setw(2)<<days+1<<" "<<weekday_1<<endl; //按照特定的格式输出年月日
        //setw(2)设置输出为两位，setfill('0')多余的用0填充
        cin>>days;
    }
    return 0;
}
