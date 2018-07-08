/*
    输入
        第一行有一个数字n，表示有n组测试用例。对于每组测试用例：
        输入有三行，每行表示一次称量的结果。赛利事先将银币标号为A-L。每次称量的结果用三个以空格隔开的字符串表示：天平左边放置的硬币 天平右边放置的硬币 平衡状态。
        其中平衡状态用``up'', ``down'', 或 ``even''表示, 分别为右端高、右端低和平衡。天平左右的硬币数总是相等的。
    输出
        输出哪一个标号的银币是假币，并说明它比真币轻还是重(heavy or light)。
*/
//分析：本道题较注重逻辑的分析，对于12块硬币，那么总共有24种状态，所以采用枚举的方法，逐个排查硬币的可能性
//本道题的解法程序参考了书本，逻辑性非常好，可以借鉴，注意检查字符串中是否存在某个字符串时，可以调用<cstring>库的strchr()函数
#include<iostream>
#include<cstring>
using namespace std;
char left_1[3][7]; //输入的左边序列
char right_1[3][7];//输入的右边天平序列
char result[3][5];//输出的结果序列
char characters[12]={'A','B','C','D','E','F','G','H','I','J','K','L'}; //所有的硬币种类
int n;
bool light(char x) //判断硬币是否较轻
{
    for(int i=0;i<3;i++)
    {
        if(result[i][0]=='e')
        {
            if(strchr(left_1[i],x)!=NULL||strchr(right_1[i],x)!=NULL)
                return false;
        }
        else if(result[i][0]=='u')
        {
            if(strchr(right_1[i],x)==NULL) //留意此处的书写，判别的是一定要求右边有轻的硬币，而不是轻的硬币不能位于左边，因为可能会有重复硬币的可能性！是个坑
                return false;
        }
        else
        {
            if(strchr(left_1[i],x)==NULL)
                return false;
        }
    }
    return true;
}
bool heavy(char x) //判断硬币是否较重
{
    for(int i=0;i<3;i++)
    {
        if(result[i][0]=='e')
        {
            if(strchr(left_1[i],x)!=NULL||strchr(right_1[i],x)!=NULL)
                return false;
        }
        else if(result[i][0]=='u')
        {
            if(strchr(left_1[i],x)==NULL)
                return false;
        }
        else
        {
            if(strchr(right_1[i],x)==NULL)
                return false;
        }
    }
    return true;
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<3;j++)
        {
            cin>>left_1[j]>>right_1[j]>>result[j];
        }
        for(int i=0;i<12;i++)
        {
            if(light(characters[i])) //如果经判别该硬币较轻，那么输出
            {
                cout<<characters[i]<<" is the counterfeit coin and it is light."<<endl;
                break;
            }
            else if(heavy(characters[i]))
            {
                cout<<characters[i]<<" is the counterfeit coin and it is heavy."<<endl;

                break;
            }
        }
    }
    return 0;
}
