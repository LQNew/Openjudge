/*
    描述
        把M个同样的苹果放在N个同样的盘子里，允许有的盘子空着不放，问共有多少种不同的分法？（用K表示）5，1，1和1，5，1 是同一种分法。
    输入
        第一行是测试数据的数目t（0 <= t <= 20）。以下每行均包含二个整数M和N，以空格分开。1<=M，N<=10。
    输出
        对输入的每组数据M和N，用一行输出相应的K
*/
//分析：此道题为典型的递归题，1. 至少空出一个盘子不放（相对于目前），则转化为在(n-1)个盘子里放m个苹果，在剩下的盘子里放入0个苹果，即apple(m,n-1)；
//                            2. 所有盘子至少放入一个。先在每个盘子里都放入1个苹果，剩下m-n个苹果，再在n个盘子里进行放置。即apple(m-n,n)。
//然后是结束的条件，有三种：  1. 当m==0时，苹果已经放完，只有一种情况，即不放置，返回1；
//                            2. 当n==1时，只有一个盘子可以放置，返回1；
//                            3. 当m<n时，苹果数小于盘子数，和将m个苹果放入m个盘子情况相同。
//此道题的递归思路不是很容易想到，要多理解这种类型题目的思路，才知道如何解题！！
#include<iostream>
using namespace std;
int M,N;
int t;
int strategies(int m,int n)
{
    if(m==0||n==1) return 1;
    else if(m<n) return strategies(m,m);
    else  return strategies(m,n-1)+strategies(m-n,n);
}
int main()
{
    cin>>t;
    for(int i=0;i<t;i++)
    {
        cin>>M>>N;
        int K=strategies(M,N);
        cout<<K<<endl;
    }
    return 0;
}
