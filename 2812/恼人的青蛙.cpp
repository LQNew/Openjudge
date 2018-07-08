//poj 2812 恼人的青蛙，题目条件太多，在此处就不附上题目了，可以直接到网页去看题目
//分析：本道题实际上是遍历被踩的水稻，找到最长的路径
//从最直观的枚举思路出发，枚举首先利用快排将所有节点排好序，接下来对于固定的起始两个节点利用二分查询查询接下来的节点是否存在，注意此处 快排以及二分查询针对于结构体的书写！
//求出所有可能走的路径后，最后得到最长的路径，但这种方法耗时，如果不经过剪枝提前筛取一些判别条件，TL会是常事
//于是需要剪枝，最关键是判别起始的两个点是不是起点，以及利用当前max步长判别从当前得到的两点出发会不会出界
//坑点：1、需要剪枝，初始条件的判别要考虑清楚
//2、在二分查询判别节点是否存在时，如果当前节点下一个预测节点如果没有出界但是不存在，说明青蛙不可能通过这个路径跳出，那么这个路径并不存在，所以step应该清零！
//本程序调用了algorithm库的qsort()函数对于结构体数组进行快排，快排的函数使用一定要熟悉；以及bsearch()函数进行二分查询，bsearch的用法一定要熟悉！！
#include<iostream>
#include<algorithm>
using namespace std;
struct Plant //结构体的构造以及使用要了解！
{
    int x,y;//结构体，存储庄稼的横坐标、纵坐标
};
int R,C;
int N;
Plant plant[5001];

int compare(const void*a,const void*b) //用于qsort 使用的compare函数，有关此compare函数的书写应留意！格式都是一致的，自己要熟悉写法~
//此处以横坐标优先排序
{
    Plant*p1;
    Plant*p2;
    p1=(Plant*)a;
    p2=(Plant*)b;
    if((*p1).x==(*p2).x)
        return((*p1).y-(*p2).y);
    else
        return((*p1).x-(*p2).x);
}

int search_1(int j,int dx,int dy)
{
    int step=2;
    Plant p;
    p.x=plant[j].x+dx;
    p.y=plant[j].y+dy;
    while(p.x<=R&&p.y<=C&&p.x>=1&&p.y>=1)
    {
        if(bsearch(&p,plant,N,sizeof(Plant),compare)) //二分查找 函数模板
        //bsearch(const void *key, const void *base, size_t num, size_t size, int (*cmp)(const void *, const void *));
        //key 指向要查找的元素，base 指向进行查找的数组，num 数组中元素的个数，size 数组中每个元素的大小，一般用sizeof()表示，cmp 比较两个元素的函数，定义比较规则。
        {
            p.x+=dx;
            p.y+=dy;
            step++;
        }
        else //没有到稻田尽头便断了，说明这种路径，青蛙压根没走过！很重要的条件判别！！
        {
            step=0;
            break;
        }

    }
    if(step<3)
        return 0;
    return step;
}

int main()
{
    cin>>R>>C;
    cin>>N;
    for(int i=0;i<N;i++)
    {
        cin>>plant[i].x>>plant[i].y;
    }
    qsort(plant,N,sizeof(Plant),compare); //qsort 对于结构体的快速排序!!
    int max=0;
    int steps;
    for(int i=0;i<N-1;i++)
    {
        for(int j=i+1;j<N;j++)
        {
            int dx=plant[j].x-plant[i].x;
            int dy=plant[j].y-plant[i].y;
            if(plant[i].x-dx>=1&&plant[i].x-dx<=R&&plant[i].y-dy>=1&&plant[i].y-dy<=C) //检查起始点
                continue;
            if(plant[i].x+max*dx>R) //如果x出界，说明对于该x，接下来的任意节点都不会符合，于是跳出当前的j循环
                break;
            if(plant[i].y+max*dy<1||plant[i].y+max*dy>C) //如果出界，那么此次不参与step运算，continue是直接跳至for循环处
                continue;
            steps=search_1(j,dx,dy);
            if(max<steps)
                max=steps;
        }
    }
    cout<<max<<endl;
    return 0;
}
