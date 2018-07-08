/*
    问题：
        一组人过河，只有一条船，每次船上必须有一或两人，每次过河时间由较慢者决定，试确定一个策略，使得总过河时间最短
*/
//分析：本道题利用了贪心算法，这是一个典型的过河问题，有固定的思路去解：首先要将所有过河时间按照升序排序
//1、一个人时，直接过河，t[0]
//2、两个人时，过河由时间较长者决定 t[1]
//3、三个人时，过河时间恒为 t[0]+t[1]+t[2]
//4、>=4个人时，策略是每次将两个最慢的人送至彼岸，有两个策略：
//a、 两小送两大：t[0]和t[1] 先去；t[0]回来；t[n-1]和t[n-2]去；t[1]回来
//b、最快送两慢：t[0]和t[n-1]先去；t[0]回来；t[0]和t[n-2]再去；t[0]回来
//综合上面分析，那么题目已经被拆解开来，不断地执行以上步骤，即可得出最优解，不过对于题目的理解尚存有问题，为什么过河问题就是这种思路的解法？？
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int T;
int N;
int time_1[1000]; //注意，给数组命名，不要命名time数组，time是C++内置的东西！

int compare(const void*a,const void*b)
{
    return *(int*)a-*(int*)b;
}

int main()
{
    cin>>T;
    for(int i=0;i<T;i++)
    {
        memset(time_1,0,sizeof(time_1[0])); //数组初始化为0
        cin>>N;
        for(int j=0;j<N;j++)
            cin>>time_1[j];
        qsort(time_1,N,sizeof(time_1[0]),compare);//快排，数组按升序排序
        int sum=0;
        for(int i=N-1;i>=0;i=i-2)
        {
            if(i==0) sum+=time_1[0]; //一个人的情况
            else if(i==1) //两个人的情况
            {
                sum+=time_1[1];
                break;
            }
            else if(i==2) //三个人的情况
            {
                sum+=time_1[0]+time_1[1]+time_1[2];
                break;
            }
            else //>=四个人的情况
            {
                if(time_1[0]*2+time_1[i]+time_1[i-1]>2*time_1[1]+time_1[0]+time_1[i])
                    sum+=2*time_1[1]+time_1[0]+time_1[i];
                else
                    sum+=2*time_1[0]+time_1[i-1]+time_1[i];
            }
        }
        cout<<sum<<endl;
    }
}
