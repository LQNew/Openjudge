/*
    描述
        人生来就有三个生理周期，分别为体力、感情和智力周期，它们的周期长度为23天、28天和33天。每一个周期中有一天是高峰。
        在高峰这天，人会在相应的方面表现出色。例如，智力周期的高峰，人会思维敏捷，精力容易高度集中。
        因为三个周期的周长不同，所以通常三个周期的高峰不会落在同一天。对于每个人，我们想知道何时三个高峰落在同一天。
        对于每个周期，我们会给出从当前年份的第一天开始，到出现高峰的天数（不一定是第一次高峰出现的时间）。
        你的任务是给定一个从当年第一天开始数的天数，输出从给定时间开始（不包括给定时间）下一次三个高峰落在同一天的时间（距给定时间的天数）。
        例如：给定时间为10，下次出现三个高峰同天的时间是12，则输出2（注意这里不是3）。

    输入
        一行，包含四个整数：p, e, i和d，相邻两个整数之间用单个空格隔开。 p, e, i分别表示体力、情感和智力高峰出现的时间（时间从当年的第一天开始计算）。
        d 是给定的时间，可能小于p, e, 或 i。 所有给定时间是非负的并且小于等于365, 所求的时间小于等于21252。
    输出
        一个整数，即从给定时间起，下一次三个高峰同天的时间（距离给定时间的天数）。
*/
//分析，此道题其实难度上较小，但是有些细节处要注意，因为审题原因，wa了一次，有些尴尬，注意在输入中提到，不包括给定时间，以及结束时间是d+21252，这个时间界限要分清
//其实就是找到一个x满足:(x-p)%23=0;(x-e)%28=0;(x-i)%33=0;且从d+1开始的某一天计算出来
//猜测可能暴力求解也可以求出，不过此处是首先找到所有满足(x-p)%23=0 条件的数用数组存储，接下来再从该数组中排查出(x-e)%28=0 再用数组存储，最后再排查出(x-i)%33
//最后将第一个满足该条件的数打印
#include<iostream>
using namespace std;
int p,e,i,d;
int Filter_1[1000];//存储满足(x-p)%23=0的所有数
int Filter_2[500];//存储满足(x-e)%28=0的所有数
int Filter_3[200];//存储满足(x-i)%33=0的所有数
int search_1(int day_initial,int num,int *a,int *b,int cnt) //num 进制，a 输入数组，b 输出数组，cnt 数组的长度
{
    int cnt_1=0;
    for(int i=0;i<cnt;i++)
    {
        if((a[i]-day_initial)%num==0)
        {
            b[cnt_1]=a[i];
            cnt_1++;
        }
    }
    return cnt_1;
}
int main()
{
    cin>>p>>e>>i>>d;
    int a=((d-p)/23+1)*23+p;//从d+1开始第一个满足(x-p)%23=0条件的数
    int cnt=0;
    while(a<=21252+d)
    {
        Filter_1[cnt]=a;
        a=a+23;
        cnt++;
    }
    int cnt_1=search_1(e,28,Filter_1,Filter_2,cnt);
    int cnt_2=search_1(i,33,Filter_2,Filter_3,cnt_1);
    cout<<Filter_3[0]-d<<endl;
    return 0;
}
