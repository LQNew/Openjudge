//本道题用到了C++中的stl库，主要是next_pernutation 的调用！同时注意next_permutation 的使用~
//分析：此道题和之前的求解数组元素序列的问题相比，思路类似，难度较小，主要是利用了 next_permutation 以及 qsort 函数对于字符串元素进行排序
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
char str[7];

int compare(const void*a,const void*b) //用于qsort 使用的compare函数，有关此compare函数的书写应留意！
{
    return *(char*)a-*(char*)b;
}

int length(int len) //求出全排列元素的个数
{
    int len_1=1;
    for(int i=len;i>1;i--)
        len_1=len_1*i;
    return len_1;
}
int main()
{
    cin>>str;
    int len=length(strlen(str));
    qsort(str,strlen(str),1,compare); //对字符串进行快速排序
    cout<<str<<endl;
    for(int i=1;i<len;i++)
    {
        next_permutation(str,str+strlen(str));//next_permutation得到下一个序列 从str[0]到str[strlen(str)-1]找到下一序列
        cout<<str<<endl;
    }
    return 0;
}
