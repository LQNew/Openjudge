/*
    描述
        国王将金币作为工资，发放给忠诚的骑士。第一天，骑士收到一枚金币；之后两天（第二天和第三天）里，每天收到两枚金币；
        之后三天（第四、五、六天）里，每天收到三枚金币；之后四天（第七、八、九、十天）里，每天收到四枚金币……这种工资发放模式会一直这样延续下去：
        当连续N天每天收到N枚金币后，骑士会在之后的连续N+1天里，每天收到N+1枚金币（N为任意正整数）。
        你需要编写一个程序，确定从第一天开始的给定天数内，骑士一共获得了多少金币。
    输入
        输入包含至少一行，但不多于21行。除最后一行外，输入的每行是一组输入数据，包含一个整数（范围1到10000），表示天数。
        输入的最后一行为0，表示输入结束。
    输出
        对每个数据输出一行，包含该数据对应天数和总金币数，用单个空格隔开。
*/
//分析，此道题为水题，很简单，主要需要考虑的是确定天数对应的是第几个连续天数内，可以数学推演而出
//用到了cmath库的sqrt()函数以及ceil()上取整函数附带着 还有个floor()函数，是下取整函数，可以了解下~
#include<iostream>
#include<cmath>
using namespace std;
int days;

int computer(int days)
{
    int total=0;
    int a=ceil(sqrt(2*days)); //ceil函数，是上取整函数
    if(2*days>a*(a-1)) //确定为哪个连续天数区间内
    {
        for(int i=1;i<a;i++)
            total+=i*i;
        total+=a*(days-(a-1)*a/2);
    }
    else
    {
        for(int i=1;i<a-1;i++)
            total+=i*i;
        total+=(a-1)*(days-(a-2)*(a-1)/2);
    }
    return total;
}

int main()
{
    while(1)
    {
        cin>>days;
        if(days==0)
            break;
        cout<<days<<" "<<computer(days)<<endl;
    }
    return 0;
}
