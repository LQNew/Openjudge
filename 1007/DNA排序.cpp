/*
    描述
        现在有一些长度相等的DNA串（只由ACGT四个字母组成），请将它们按照逆序对的数量多少排序。
        逆序对指的是字符串A中的两个字符A[i]、A[j]，具有i < j 且 A[i] > A[j] 的性质。如字符串”ATCG“中，T和C是一个逆序对，T和G是另一个逆序对，
        这个字符串的逆序对数为2。
    输入
        第1行：两个整数n和m，n(0<n<=50)表示字符串长度，m(0<m<=100)表示字符串数量
        第2至m+1行：每行是一个长度为n的字符串
    输出
        按逆序对数从少到多输出字符串，逆序对数一样多的字符串按照输入的顺序输出。
*/
//分析，对于输入的字符串后先计算逆序对数，之后按照逆序对数的多少排序，最后按序输出，本道题的思路较为明晰，主要用到了结构体排序这点使得问题变得更加简洁~
#include<iostream>
#include<algorithm>
using namespace std;
int m,n;
char str[101][51];
struct Node
{
    int num;
    int subscript;
};
Node node[100];

int find_num(int i) //找到逆序数
{
    int sum=0;
    for(int j=0;j<n-1;j++)
    {
        for(int k=j+1;k<n;k++)
        {
            if(str[i][j]>str[i][k])
                sum++;
        }
    }
    return sum;
}

int compare(const void*a,const void*b) //用于qsort 使用的compare函数，有关此compare函数的书写应留意！格式都是一致的，自己要熟悉写法~
//此处以逆序数优先排序，如果逆序数相等，按输入顺序排序
{
    Node*p1;
    Node*p2;
    p1=(Node*)a;
    p2=(Node*)b;
    if((*p1).num==(*p2).num)
        return((*p1).subscript-(*p2).subscript);
    else
        return((*p1).num-(*p2).num);
}

int main()
{
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        cin>>str[i];
        node[i].subscript=i;
    }

    for(int i=0;i<m;i++)
    {
        node[i].num=find_num(i);
    }

    qsort(node,m,sizeof(Node),compare); //qsort 对于结构体的快速排序!!
    for(int i=0;i<m;i++)
    {
        cout<<str[node[i].subscript]<<endl;
    }
}
