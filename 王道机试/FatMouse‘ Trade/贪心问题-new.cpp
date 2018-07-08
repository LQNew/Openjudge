//一种典型的贪心思想，我们每次都尽可能的多买性价比高的物品直到该物品被买完或者金钱耗尽。
#include<iostream>
#include<algorithm>
#include<iomanip> //设置输出精度
using namespace std;
int n;
double m;
struct Goods
{
    double weight;
    double total_price;
    double price;
};
Goods goods[1000];
int compare(const void*a,const void*b)
{
    Goods*p;
    Goods*p1;
    p=(Goods*)a;
    p1=(Goods*)b;
    return (*p1).price-(*p).price; //按照学号排序
}
int main()
{
    while(cin>>m>>n)
    {
        double total_weight=0;
        if(m==-1&&n==-1)
            break;
        for(int i=0;i<n;i++)
        {
            cin>>goods[i].weight>>goods[i].total_price;
            goods[i].price=goods[i].weight/goods[i].total_price;
        }
        qsort(goods,n,sizeof(Goods),compare); //商品性价比排序
        for(int i=0;i<n;i++)
        {
            if(m>goods[i].total_price)
            {
                m-=goods[i].total_price;
                total_weight+=goods[i].weight;
            }
            else
            {
                total_weight+=m*goods[i].price;
                break;
            }
        }
        cout<<fixed<<setprecision(3)<<total_weight<<endl;
    }
    return 0;
}
