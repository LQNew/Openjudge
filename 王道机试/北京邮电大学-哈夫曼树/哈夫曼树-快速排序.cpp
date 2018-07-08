//模拟哈夫曼树建树的过程，用快速排序解决问题！
#include<iostream>
#include<cstring>
using namespace std;
int n;
int node[1000];
int weight;

int compare(const void*a,const void*b) //用于qsort 使用的compare函数，有关此compare函数的书写应留意！
{
    return *(int*)b-*(int*)a;
}
int main(){
    while(cin>>n){
        memset(node,0,sizeof(int)*n);
        for(int i=0;i<n;i++){
            cin>>weight;
            node[i]=weight;
        }
        int ans=0;
        while(n>1){
            qsort(node,n,sizeof(int),compare); //对数组进行快速排序
            n--;
            node[n-1]=node[n]+node[n-1]; //将每次得到的最新的值插入数组尾部，再进行快速排序，并记录下非叶节点的权值
            cout<<node[n-1]<<endl;
            ans+=node[n-1];
        }
        cout<<ans<<endl;
    }
    return 0;
}
