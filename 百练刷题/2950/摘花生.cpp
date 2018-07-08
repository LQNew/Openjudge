/*
    输入
        输入的第一行包括一个整数T，表示数据组数
        每组输入的第一行包括三个整数，M, N和K，用空格隔开；表示花生田的大小为M * N（1 <= M, N <= 50），
        多多采花生的限定时间为K（0 <= K <= 1000）个单位时间。接下来的M行，每行包括N个非负整数，也用空格隔开；第i + 1行的第j个整数Pij（0 <= Pij <= 500）
        表示花生田里植株(i, j)下花生的数目，0表示该植株下没有花生。
    输出
        输出包括T行，每一行只包含一个整数，即在限定时间内，多多最多可以采到花生的个数。
*/
//分析，仍是每次到达指定的位置后判别跳到下一处会不会有时间返程
//模拟问题，理清逻辑即可，此处关于绝对值 可从 cmath库导入abs函数
#include<iostream>
#include <cmath>
using namespace std;
int T;
int M,N,K;
int max_row,max_line; //最大行值、最大列值
int row,line;//当前行值、列值
int max_value;//最大花生数目值
int value;
int Grid[51][51];

void find_max() //每次找到表格中花生数最多的一个网格点
{
    max_value=0;
    for(int j=1;j<=M;j++)
    {
        for(int k=1;k<=N;k++)
        {
            if(max_value<Grid[j][k])
            {
                max_value=Grid[j][k]; //获取当前花生数最大值
                max_row=j; //返回网格的行
                max_line=k; //返回网格的列
            }
        }
    }
}
int main()
{
    cin>>T;
    for(int i=0;i<T;i++)
    {
        cin>>M>>N>>K;
        for(int j=1;j<=M;j++)
        {
            for(int k=1;k<=N;k++)
                cin>>Grid[j][k];
        }
        find_max();
        int K_1=K;
        row=0;line =max_line;
        K_1-=abs(max_row-row)+abs(max_line-line)+max_row+1; //减去到目标最大值处以及返程所花的时间
        while(K_1>=0)
        {
            K-=abs(max_row-row)+abs(max_line-line)+1;//减去当目标最大值处所花的时间
            K_1=K;
            value+=max_value;
            Grid[max_row][max_line]=0;
            row=max_row;line=max_line;
            find_max();
            if(max_value==0)
                break;
            K_1-=abs(max_row-row)+abs(max_line-line)+max_row+1;
        }
        cout<<value<<endl;
        value=0;
    }

}
