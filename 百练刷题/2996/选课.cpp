//找出当前排序的下M个排序，水题，直接调用next_permutation()函数即可
#include<iostream>
#include<algorithm>
using namespace std;
int N;
int M;
int num[10000];
int main()
{
    cin>>N>>M;
    for(int i=0;i<N;i++)
        cin>>num[i];
    for(int i=0;i<M;i++)
        next_permutation(num,num+N);
    for(int i=0;i<N;i++)
        cout<<num[i]<<" ";
    cout<<endl;
    return 0;
}
