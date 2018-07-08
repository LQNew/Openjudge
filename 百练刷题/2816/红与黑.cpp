/*
    描述
        有一间长方形的房子，地上铺了红色、黑色两种颜色的正方形瓷砖。你站在其中一块黑色的瓷砖上，只能向相邻的黑色瓷砖移动。
        请写一个程序，计算你总共能够到达多少块黑色的瓷砖。
    输入
        包括多个数据集合。每个数据集合的第一行是两个整数W和H，分别表示x方向和y方向瓷砖的数量。W和H都不超过20。在接下来的H行中，每行包括W个字符。
        每个字符表示一块瓷砖的颜色，规则如下：
        1）‘.’：黑色的瓷砖；
        2）‘#’：白色的瓷砖；
        3）‘@’：黑色的瓷砖，并且你站在这块瓷砖上。该字符在每个数据集合中唯一出现一次。
        当在一行中读入的是两个零时，表示输入结束。
    输出
        对每个数据集合，分别输出一行，显示你从初始位置出发能到达的瓷砖数(记数时包括初始位置的瓷砖)。
*/
//分析：这道题是典型的广度优先搜索问题，思路较为简单，就是从每一点出发，去搜寻该点的四周，需要注意的是，当某个点被搜索后，应打上标识！
#include<iostream>
using namespace std;
char map1[20][20];
int W,H;
struct location
{
  int row;
  int col;
};

location find_location() //返回结构体
{
    for(int i=0;i<H;i++)
    {
        for(int j=0;j<W;j++)
        {
            if(map1[i][j]=='@')
            {
                location locat;
                locat.row=i;
                locat.col=j;
                return locat;
            }
        }
    }
}

int search_1(int i,int j)
{
    if(i<0||j<0||i>=H||j>=W)
        return 0;
    else
    {
        if(map1[i][j]=='.'||map1[i][j]=='@')
        {
            map1[i][j]='!'; //打上标识
            return search_1(i-1,j)+1+search_1(i+1,j)+search_1(i,j-1)+search_1(i,j+1);
        }
        else
            return 0;
    }
}
int main()
{
    cin>>W>>H;
    while(!(W==0||H==0))
    {
        for(int i=0;i<H;i++)
        {
            for(int j=0;j<W;j++)
            {
                cin>>map1[i][j];
            }
        }
        location locat=find_location(); //找到@的位置
        int cnt=search_1(locat.row,locat.col); //以该点为起始点开始广搜
        cout<<cnt<<endl;
        cin>>W>>H;
    }
    return 0;
}
