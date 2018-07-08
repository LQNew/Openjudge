/*
    对N个长度最长可达到1000的数进行排序。
    输入描述:
        输入第一行为一个整数N，(1<=N<=100)。
        接下来的N行每行有一个数，数的长度范围为1<=len<=1000。
        每个数都是一个正数，并且保证不包含前缀零。
    输出描述:
        可能有多组测试数据，对于每组数据，将给出的N个数从小到大进行排序，输出排序后的结果，每个数占一行。
*/
//此种题可以转化为字符串排序问题，用结构体存储再加上快速排序便可以轻松AC！
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int N;
struct Node
{
    char Num[1001];
};
Node node[100];

int compare(const void*a,const void*b)
{
    Node*p;
    Node*p1;
    p=(Node*)a;
    p1=(Node*)b;
    if(strlen((*p).Num)==strlen((*p1).Num))
        return strcmp((*p).Num,(*p1).Num); //按照学号排序
    else
        return strlen((*p).Num)-strlen((*p1).Num);
}

int main()
{
    while(cin>>N)
    {
        for(int i=0;i<N;i++)
            cin>>node[i].Num;
        qsort(node,N,sizeof(Node),compare);
        for(int i=0;i<N;i++)
            cout<<node[i].Num<<endl;
    }

}
