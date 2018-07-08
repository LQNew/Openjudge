/*
    输入
        输入的第一行包含了一个整数N，表示有N组测试数据。接下来N行，每一行包括一个时间和两个时区的缩写，它们之间用空格隔开。
        时间由标准的a.m./p.m给出。midnight表示晚上12点（12:00 a.m.），noon表示中午12点（12:00 p.m.）。
    输出
        假设输入行给出的时间是在第一个时区中的标准时间，要求输出这个时间在第二个时区中的标准时间。
*/
//分析 本题是繁杂但是本身没有什么难度orz，注意本道题中有一个小trick，就是此处采用了两个数组用于计数时区间隔
//应了解 c++中 输入输出流的控制形式输出的方法！
#include<iostream>
#include<cstring>
#include<iomanip> //引入控制输出格式的头文件!!重要，注意此处一些输出要求两位整数的格式形式！！
using namespace std;
char zone[32][5] = { "UTC", "GMT", "BST","IST", "WET",
                     "WEST", "CET", "CEST", "EET", "EEST",
                     "MSK", "MSD", "AST", "ADT", "NST",
                     "NDT", "EST", "EDT", "CST", "CDT",
                     "MST", "MDT", "PST", "PDT", "HST",
                     "AKST", "AKDT", "AEST", "AEDT", "ACST",
                     "ACDT", "AWST"};
float time_interval[32] = { 0, 0, 1, 1, 0, 1, 1, 2, 2, 3,
                   3, 4, -4, -3, -3.5, -2.5, -5, -4, -6, -5,
                   -7, -6, -8, -7, -10, -9, -8, 10, 11, 9.5,
                   10.5, 8};
int N;//输入的整数N，代表N组测试数据
char zone1[5],zone2[5]; //输入的两个时区
char time_2[5];//输入的第一个时间
char AorP[5]; //判断是a.m. 还是 p.m.
int hour,minute; //输入的时间、分钟
float time_interval_1; //时区的时间间隔
float compute_time_interval() //计算时区间隔
{
    int i,j;
    for(i=0;i<32;i++)
    {
        if(strcmp(zone1,zone[i])==0)
            break;
    }
    for(j=0;j<32;j++)
    {
        if(strcmp(zone2,zone[j])==0)
            break;
    }
    return time_interval[j]-time_interval[i];
}
int find_colon() //找到:的位置
{
    for(int i=0;i<strlen(time_2);i++)
    {
        if(time_2[i]==':')
            return i;
    }
}
int main()
{
    cin>>N;
    for(int i=0;i<N;i++)
    {
        cin>>time_2;
        if(time_2[0]=='n') //如果是n，代表为noon 中午
        {
            hour=12;
            minute=0;
        }
        else if(time_2[0]=='m') //如果是m 代表为 midnight 午夜
        {
            hour=0;
            minute=0;
        }
        else
        {
            int j=find_colon();
            if(j==1)
            {
                hour=time_2[0]-48; //ascii码转换为对应的整形的数字
                minute=(time_2[2]-48)*10+(time_2[3]-48);
            }
            else
            {
                 hour=10*(time_2[0]-48)+time_2[1]-48;
                 minute=(time_2[3]-48)*10+time_2[4]-48;
            }
            cin>>AorP; //判断为a.m. 还是 p.m.
            if(AorP[0]=='p')
            {
                if(hour<12)
                    hour+=12;
            }
            else
            {
                if(hour==12)
                    hour=0;
            }
        }
        cin>>zone1>>zone2;
        time_interval_1=compute_time_interval(); //计算时区时差
        int k=time_interval_1*60;
        hour+=k/60;
        minute+=k%60;
        if(minute>=60) //如果分钟>60，进位
        {
            minute-=60;
            hour+=1;
        }
        else if(minute<0)//如果分钟<0，借位
        {
            minute+=60;
            hour-=1;
        }
        if(hour==12&&minute==0)
            cout<<"noon"<<endl;
        else if(hour%24==0&&minute==0)
            cout<<"midnight"<<endl;
        else
        {
            if(hour>=24) //如果时间超过24小时，代表为次天
                hour-=24;
            else if(hour<0)//如果时间小于0小时，代表为昨日
                hour+=24;
            if(hour<12)
            {
                if(hour<1) //如果是零点几刻，那么相应的应转换为 12:~~ a.m.
                    cout<<12<<':'<<setfill('0')<<setw(2)<<minute<<" "<<"a.m."<<endl; //设置使得minute以二位整数形式输出
                else
                    cout<<hour<<':'<<setfill('0')<<setw(2)<<minute<<" "<<"a.m."<<endl;
            }
            else
            {
                if(hour<13)  //如果是12点即可，那么相应的应转换为 12:~~ p.m.
                    cout<<12<<':'<<setfill('0')<<setw(2)<<minute<<" "<<"p.m."<<endl;
                else
                    cout<<hour-12<<':'<<setfill('0')<<setw(2)<<minute<<" "<<"p.m."<<endl;
            }
        }
    }


}
