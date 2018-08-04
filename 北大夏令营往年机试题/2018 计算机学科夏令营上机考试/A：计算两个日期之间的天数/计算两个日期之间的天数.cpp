//水题，边界条件考虑得比较多，同年的，同月的都要把逻辑理清楚！
#include<iostream>
using namespace std;
int start_year,start_month,start_day;
int end_year,end_month,end_day;
int leap_days[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};
int non_days[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};

bool is_leap_year(int x){
    if(((x%4==0)&&(x%100!=0))||((x%4==0)&&(x%400==0))) return true;
    return false;
}

int main(){
    cin>>start_year>>start_month>>start_day>>end_year>>end_month>>end_day;
    int a=0;
    for(int i=start_year+1;i<end_year;i++){
        if(is_leap_year(i)) a+=366;
        else a+=365;
    }
    if(start_year!=end_year){
        if(is_leap_year(start_year)){
            for(int i=start_month+1;i<=12;i++) a+=leap_days[i];
            a+=(leap_days[start_month]-start_day);
        }
        else{
            for(int i=start_month+1;i<=12;i++) a+=non_days[i];
            a+=(non_days[start_month]-start_day);
        }
        if(is_leap_year(end_year)){
            for(int i=1;i<end_month;i++) a+=leap_days[i];
            a+=end_day;
        }
        else{
            for(int i=1;i<end_month;i++) a+=non_days[i];
            a+=end_day;
        }
    }
    else{
        if(is_leap_year(start_year)){
            for(int i=start_month+1;i<end_month;i++) a+=leap_days[i];
            if(start_month==end_month) a+=(end_day-start_day);
            else{
                a+=(leap_days[start_month]-start_day);
                a+=end_day;
            }
        }
        else{
            for(int i=start_month+1;i<end_month;i++) a+=non_days[i];
            if(start_month==end_month) a+=(end_day-start_day);
            else{
                a+=(non_days[start_month]-start_day);
                a+=end_day;
            }
        }
    }
    cout<<a<<endl;
    return 0;
}
