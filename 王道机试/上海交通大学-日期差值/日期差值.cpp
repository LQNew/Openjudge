#include<iostream>
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
        int days_diff=0;
        for(int i=original_year+1;i<final_year;i++)
        {
            if(judge_year(i))
                days_diff+=366;
            else
                days_diff+=365;
        }
        if(original_year==final_year)
        {
            for(int i=original_month;i<final_month;i++)
            {
                days_diff+=days[judge_year(final_year)][i-1];
            }
            days_diff+=(final_date-original_date+1);
        }
        else
        {
            days_diff+=days[judge_year(original_year)][original_month-1]-original_date+1;
            for(int i=original_month+1;i<13;i++)
            {
                days_diff+=days[judge_year(original_year)][i-1];
            }
            for(int i=1;i<final_month;i++)
            {
                days_diff+=days[judge_year(final_year)][i-1];
            }
            days_diff+=final_date;

        }
        cout<<days_diff<<endl;
    }
    return 0;
}
