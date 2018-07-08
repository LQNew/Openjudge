//改进版，使用了reverse函数用于将数组逆序 以及next_permutation函数用于直接获取下一排序
#include<iostream>
#include<algorithm>
using namespace std;
int m;
int n,k;
int num[1025];
int flag;//用于标识当前应该被换位的序号

int main()
{
    cin>>m;
    for(int i=0;i<m;i++)
    {
        cin>>n>>k;
        for(int j=1;j<=n;j++)//录入数据，但可能cin读入 时间会爆，但实际并没有超时
            cin>>num[j];
        for(int m=0;m<k;m++)
        {
            for(flag=n;flag>0;flag--)
            {
                if(num[flag-1]<num[flag]) //找到需要换位的位置 flag
                    break;
            }
            if(flag==1) //如果此时的序列已经是排序的最后一个，那么返回第一个，从头开始
                reverse(num+1,num+n+1); //reverse函数获取从 num[1]到num[n+1]数据全部逆序
            else
               next_permutation(num+1,num+n+1);//next_permutation得到下一个序列 从num[1]到num[n]找到下一序列
        }
        for(int i=1;i<=n;i++)
            cout<<num[i]<<" ";
        cout<<endl;
    }
    return 0;
}
