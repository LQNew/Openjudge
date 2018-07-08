/*
玛雅历问题，本身是很简单的问题，但是题目有些弯弯绕，就是文字游戏！！！
*/
//分析： 将一种日历形式转换为另一种日历形式，就是数学上的代换，需要注意的是，此道题因为WA了五六次！就是审题问题！
//1、输入时点的读取，新设一个字符去承接
//2、玛雅历有第19月，这点蛮坑。。
//3、输出时也有数据量这一项
//4、算术取余有一些细节上的小问题没思考好
#include<iostream>
#include<cstring>
using namespace std;
int cnt;
char month[10];
char dot='.';
int date;
int year;
int Tzolkin_date;
char Tzolkin_month[10];
int Tzolkin_year;
char Haab[19][10]={"pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen",
                    "yax", "zac", "ceh","mac", "kankin", "muan", "pax", "koyab", "cumhu","uayet"};
char Tzolkin[20][10]={"ahau","imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", "muluk", "ok",
                        "chuen", "eb","ben", "ix", "mem", "cib", "caban", "eznab", "canac"};
int com_month() //计算玛雅历下的月份
{
    int j;
    for(j=0;j<19;j++)
    {
        if(strcmp(month,Haab[j])==0)
            return j;
    }
}
int main()
{
    cin>>cnt;
    cout<<cnt<<endl;
    for(int i=0;i<cnt;i++)
    {
        cin>>date>>dot>>month>>year;
        int months=com_month();
        int days=year*365+months*20+date+1;
        if(days%13) //此处对于取余要注意13的倍数处理上的trick！
            Tzolkin_date=days%13;
        else
            Tzolkin_date=13;
        strcpy(Tzolkin_month,Tzolkin[days%20]);
        Tzolkin_year=(days-1)/260;
        cout<<Tzolkin_date<<" "<<Tzolkin_month<<" "<<Tzolkin_year<<endl;
    }
    return 0;
}
