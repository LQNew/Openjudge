/*
    题目描述：
        输入N个（N<=10000）数字，求出这N个数字中的最大值和最小值。每个数字的绝对值不大于1000000。
    输入：
        输入包括多组测试用例，每组测试用例由一个整数N开头，接下去一行给出N个整数。
    输出：
        输出包括两个整数，为给定N个数中的最大值与最小值。
*/
#include<iostream>
#include<algorithm>
using namespace std;
long long int data[10000]; //1000000需用 long long int 型存储
int N;
int compare(const void*a,const void*b) //用于qsort 使用的compare函数，有关此compare函数的书写应留意！
{
    return *(int*)a-*(int*)b;
}
int main()
{
    while(cin>>N)
    {
        for(int i=0;i<N;i++)
        {
            cin>>data[i];
        }
        qsort(data,N,sizeof(long long int),compare); //对数组进行快速排序
        cout<<data[N-1]<<" "<<data[0]<<endl;
    }
    return 0;
}
