/*
    描述
        幻方是一个很神奇的N*N矩阵，它的每行、每列与对角线，加起来的数字和都是相同的。
        我们可以通过以下方法构建一个幻方。（阶数为奇数）
        1.第一个数字写在第一行的中间
        2.下一个数字，都写在上一个数字的右上方：
            a.如果该数字在第一行，则下一个数字写在最后一行，列数为该数字的右一列
            b.如果该数字在最后一列，则下一个数字写在第一列，行数为该数字的上一行
            c.如果该数字在右上角，或者该数字的右上方已有数字，则下一个数字写在该数字的下方
    输入
        一个数字N（N<=20）
    输出
        按上方法构造的2N-1 * 2N-1的幻方
*/
//分析：分类讨论，把各种情况列举详细~
#include<iostream>
#include<string.h>
using namespace std;
int Matrix[40][40]; //用一个大的数组存储最大为39*39的矩阵
int N;
int last_i,last_j; //引入一个变量用于记录上一次点的坐标

void Fill_grid(int i,int j,int num) //列举出各个情况下表格的填充
{
    if(i==1)
    {
        if(j==2*N-1)
        {
            Matrix[i+1][j]=num;
            last_i=i+1;
            last_j=j;
        }
        else{
        Matrix[2*N-1][j+1]=num;
        last_i=2*N-1;
        last_j=j+1;}
    }
    else if(j==2*N-1)
    {
        Matrix[i-1][1]=num;
        last_i=i-1;
        last_j=1;
    }

    else if(Matrix[i-1][j+1])
    {
        Matrix[i+1][j]=num;
        last_i=i+1;
        last_j=j;
    }
    else
    {
        Matrix[i-1][j+1]=num;
        last_i=i-1;
        last_j=j+1;
    }
}

int main()
{
    cin>>N;
    memset(Matrix,0,sizeof(Matrix));
    last_i=1;last_j=N;
    Matrix[1][N]=1;
    for(int num=2;num<=(2*N-1)*(2*N-1);num++)
    {
        Fill_grid(last_i,last_j,num);
    }
    for(int i=1;i<=2*N-1;i++)
    {
        for(int j=1;j<=2*N-1;j++)
        {
            cout<<Matrix[i][j]<<"  ";
        }
        cout<<endl;
    }
    return 0;
}
