/*
    描述
        形如a3= b3 + c3 + d3的等式被称为完美立方等式。例如123= 63 + 83 + 103 。编写一个程序，对任给的正整数N (N≤100)，寻找所有的四元组(a, b, c, d)，
        使得a3 = b3 + c3 + d3，其中a,b,c,d 大于 1, 小于等于N，且b<=c<=d。
    输入
        一个正整数N (N≤100)。
    输出
        每行输出一个完美立方。输出格式为:Cube = a, Triple = (b,c,d)。其中a,b,c,d所在位置分别用实际求出四元组值代入。
        请按照a的值，从小到大依次输出。当两个完美立方等式中a的值相同，则b值小的优先输出、仍相同则c值小的优先输出、再相同则d值小的先输出。
*/
//分析：本道题难度较小，就是遍历找到满足条件的元素并打印
#include<iostream>
using namespace std;
int cube[101];//存储<=N的立方值
int N;
int a,b,c,d;
int main()
{
    cin>>N;
    for(int i=1;i<=N;i++)
        cube[i]=i*i*i;
    for(a=2;a<=N;a++)
    {
        for(b=2;b<a;b++)
        {
            if(cube[a]<cube[b]*3)
                break;
            for(c=b;c<a;c++)
            {
                if(cube[a]<cube[b]+cube[c]*2) break;
                for(d=c;d<a;d++)
                {
                    if(cube[a]<cube[b]+cube[c]+cube[d]) break;
                    if(cube[a]==cube[b]+cube[c]+cube[d])
                        cout<<"Cube = "<<a<<", Triple = ("<<b<<","<<c<<","<<d<<")"<<endl;
                }
            }
        }
    }
    return 0;
}
