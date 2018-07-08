/*王、后、车、象的走子规则如下：
  王：横、直、斜都可以走，但每步限走一格。
  后：横、直、斜都可以走，每步格数不受限制。
  车：横、竖均可以走，不能斜走，格数不限。
  象：只能斜走，格数不限。
  写一个程序，给定起始位置和目标位置，计算王、后、车、象从起始位置走到目标位置所需的最少步数。
  分析：对于王，由于步数每次只可以走一步，所以最少步数为:abs(Lx-Ly)+min(Lx,Ly)--Lx Ly分别为起始位置与目标位置的横向距离与纵向距离~ 此处可以自己在纸上绘图理解
        对于后，步数不受限制的话，那么如果：Lx=0/Ly=0/Lx=Ly，则步数为1，否则为2
        对于车，Lx=0/Ly=0时，有步数为1，否则为2
        对于象，因为有时候点之间是无法彼此到达的，引入二类点的概念(此处要求对于数学规律的总结要足够敏感！！)，第一类点--纵坐标与横坐标绝对值差值为偶数
                第二类点--纵坐标与横坐标绝对值差值为奇数，此二类点彼此之间不可相互到达，在为同一类点后，如果Lx=Ly，步数为1，如果Lx!=Ly，步数为2

  输入：第一行是测试数据的组数t（0 <= t <= 20）。以下每行是一组测试数据，每组包括棋盘上的两个位置，第一个是起始位置，第二个是目标位置。
        位置用"字母-数字"的形式表示，字母从"a"到"h"，数字从"1"到"8"。
  输出：对输入的每组测试数据，输出王、后、车、象所需的最少步数。如果无法到达,就输出"Inf".
*/
//题目难度不大，但是也需要自己的分析~~

#include<iostream>
using namespace std;
void Judge(int Lx,int Ly)
{
    if(Lx==0&&Ly==0)
        cout<<"0 0 0 0"<<endl;
    else
    {
    //输出王的步数
    cout<<max(Lx,Ly)<<" ";
    //输出后的步数
    if(Lx==0||Ly==0||Lx==Ly)
        cout<<1<<" ";
    else
        cout<<2<<" ";
    //输出车的步数
    if(Lx==0||Ly==0)
        cout<<1<<" ";
    else
        cout<<2<<" ";
    //输出象的步数
    if(abs(Lx-Ly)%2)
        cout<<"Inf"<<endl;//不属于同一类点
    else
    {
        if(Lx==Ly)
            cout<<1<<endl;
        else
            cout<<2<<endl;
    }
    }
}
int main()
{
    int num_group;
    cin>>num_group;
    char first[3];
    char ending[3];
    for(int i=num_group;i>0;i--)
    {
        cin>>first;
        cin>>ending;
        int Lx=abs(first[0]-ending[0]);
        int Ly=abs(first[1]-ending[1]);
        Judge(Lx,Ly);
    }
    return 0;
}
//小插曲：此处在If判别时因为粗心，将==写成=，导致了不必要的错误，为此排错了很久，下次改正！！

