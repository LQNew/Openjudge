/*
    描述
        在一门课程中，一共有n场考试。假如你在i场考试中可以答对bi道题中的ai道，那么你的累计平均分定义为：100*Σai/Σbi。
        已知你这i场考试的答题情况，并且允许你放弃其中的k场考试，请你确定你最高能够得到多少的累计平均分。
        假设该课程一共有3门考试，你的答题情况为5/5，0/1和2/6。如果你每门都参加，你的累计平均分为100*(5+0+2)/(5+1+6)= 50分。
        如果你放弃第3场考试，你的累计平均分则提高到了100*(5+0)/(5+1)= 83.33 ≈ 83分。
    输入
        有多组测试数据，每组测试数据包括3行。
        每组测试数据第一行有两个数n和k，接下来一行有n个数ai，最后一行n个数bi。
        (1 ≤ k < n ≤ 1000) (1 ≤ ai ≤ bi ≤ 1, 000, 000, 000)。
        输入的最后一行为0 0，不作处理。
    输出
        输出最高的累计平均分。（四舍五入到整数）
*/
//分析：本道题是典型的求最大平均值问题，题目的思路较为刁钻，只有做过类似的题目，才有可能相出合适的题解~
//本道题其实是找 ∑vi / ∑wi >=x的最大x，把不等式进行变形，就得到了 ∑ ( vi - x * wi )>=0，
//于是判断就成了，对 vi-x*wi 的值进行排序之后贪心进行选择，判断去除k个最小值后是否还大于等于0
//对于x的寻找是用了二分查找，由于都是double型变量通常关于double型变量的比对，一般是设置一个极小值，比如eps=1e-6，判断两个数大小或者是判断数是否等于零
//这一类的问题时都是用种方法去比对，然后再四舍五入的表述时，我用了cmath库的ceil()和floor()函数去比对，可能方法不是最优，但很好地去完成了四舍五入的要求
//本道题wa了五次，其实思路从第二次就走对了，但是始终会有些小问题也是蛮尴尬的，最主要的还是compare的函数书写，不知道为什么，用另一种方法书写时就会出现奇怪的问题..
//本道题的compare()函数的书写应该是写得比较不一样的一次，值得反复研读~
#include<iostream>
#include<cmath>
const double eps=1e-6;
using namespace std;
int n,k;
double mid;

struct Node
{
    double pass;
    double total;
};
Node node[1000];

int compare(const void*a,const void*b) //用于qsort 使用的compare函数，有关此compare函数的书写应留意！格式都是一致的，自己要熟悉写法~
{
    Node*p1;
    Node*p2;
    p1=(Node*)a;
    p2=(Node*)b;
    if((*p2).pass-(*p2).total*mid>(*p1).pass-(*p1).total*mid)
        return 1;
    else
        return -1;
}

bool judge()
{
    double sum=0;
    qsort(node,n,sizeof(Node),compare);
    for(int i=0;i<n-k;i++) //找出前n-k个值，都是较大值，然后叠加验证是否和大于等于0
        sum+=(node[i].pass-mid*node[i].total);
    return sum>-eps;
}

int main()
{
    while(cin>>n>>k)
    {
        if(n==0&&k==0)
            break;
        for(int i=0;i<n;i++)
            cin>>node[i].pass;
        for(int i=0;i<n;i++)
            cin>>node[i].total;
        double max_1=1;
        double min_1=0;
        while(max_1-min_1>eps) //二分查找最合适的比值
        {
            mid =(max_1+min_1)/2.0;
            if(judge())
                min_1=mid;
            else
                max_1=mid;

        }
        double a=100*min_1; //四舍五入
        if(ceil(a)-a-0.5<eps)
            cout<<ceil(a)<<endl;
        else
            cout<<floor(a)<<endl;
    }
    return 0;
}
