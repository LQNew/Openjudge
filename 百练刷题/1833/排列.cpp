/*描述
    题目描述：
        大家知道，给出正整数n，则1到n这n个数可以构成n！种排列，把这些排列按照从小到大的顺序（字典顺序）列出，
        如n=3时，列出1 2 3，1 3 2，2 1 3，2 3 1，3 1 2，3 2 1六个排列。
    任务描述：
        给出某个排列，求出这个排列的下k个排列，如果遇到最后一个排列，则下1排列为第1个排列，即排列1 2 3…n。
        比如：n = 3，k=2 给出排列2 3 1，则它的下1个排列为3 1 2，下2个排列为3 2 1，因此答案为3 2 1。
    输入
        第一行是一个正整数m，表示测试数据的个数，下面是m组测试数据，每组测试数据第一行是2个正整数n( 1 <= n < 1024 )和k(1<=k<=64)，
        第二行有n个正整数，是1，2 … n的一个排列。
    输出
        对于每组输入数据，输出一行，n个数，中间用空格隔开，表示输入排列的下k个排列。
*/
//分析，此道题最简单的方式就是利用C++模板库中的next_permutation 算法直接求出下一个排列，简单无脑
//此处是用模拟的方法，自己每次找出下一个排序，就是从第n个数往前比对，如果第j-1个数<第j个数，那么说明从第j-1个数开始的排序不是最后最终的排序
//可以从第j个数往后找到最小的大于第j-1个数的数值，并将二者位置交换，之后对于从第j个数开始进行快排，则得出下一个排列
//应注意的是 algorithm库中的qsort快排函数的使用以及 compare函数形式的书写
#include<iostream>
#include<algorithm>
using namespace std;
int m;
int n,k;
int num[1025];
int flag;//用于标识当前应该被换位的序号

int compare(const void*a,const void*b) //用于qsort 使用的compare函数，有关此compare函数的书写应留意！
{
    if(*(int *)a>*(int *)b) //利用快排编写的compare函数
        return 1;
    else
        return -1;
}
int main()
{
    cin>>m;
    for(int i=0;i<m;i++)
    {
        cin>>n>>k;
        for(int j=1;j<=n;j++)//录入数据，但可能cin读入时间会超时，实际上并没有 orz
            cin>>num[j];
        for(int m=0;m<k;m++)
        {
            for(flag=n;flag>0;flag--)
            {
                if(num[flag-1]<num[flag]) //找到需要换位的位置 flag
                    break;
            }
            if(flag==1) //如果此时的序列已经是排序的最后一个，那么返回第一个，从头开始
                qsort(num+1,n,sizeof(num[0]),compare); //留意qsort函数的使用，第一个为排序地址，偏移量多少直接用 数组首地址+偏移量表示即可
            else
            {
                qsort(num+flag,n-flag+1,sizeof(num[0]),compare); //从flag之后数据先来个快排
                for(int z=flag;z<=n;z++) //把从flag开始的之后数据最小大于num[flag-1]的数与num[flag-1]交换数值
                {
                    if(num[z]>num[flag-1])
                    {
                        int t=num[z];
                        num[z]=num[flag-1];
                        num[flag-1]=t;
                        break;
                    }
                }
            }
        }
        for(int i=1;i<=n;i++)
            cout<<num[i]<<" ";
        cout<<endl;
    }
    return 0;
}
