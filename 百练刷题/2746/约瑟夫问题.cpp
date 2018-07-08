/*
    描述
        约瑟夫问题：有ｎ只猴子，按顺时针方向围成一圈选大王（编号从１到ｎ），从第１号开始报数，一直数到ｍ，数到ｍ的猴子退出圈外，剩下的猴子再接着从1开始报数。就这样，直到圈内只剩下一只猴子时，这个猴子就是猴王，编程求输入ｎ，ｍ后，输出最后猴王的编号。
    输入
        每行是用空格分开的两个整数，第一个是 n, 第二个是 m ( 0 < m,n <=300)。最后一行是：0 0
    输出
        对于每行输入数据（最后一行除外)，输出数据也是一行，即最后猴王的编号
*/
//分析：模拟题型，就是挨次去数，每数至m便删去一个节点，只要逻辑理清了，此道题难度并不大
#include<iostream>
#include<cstring>
using namespace std;
int n,m;
int length;
int sign[310];//定义一个标识数组，用于标识出节点是否被删除
int main()
{
    cin>>n>>m;
    while(n!=0&&m!=0)
    {
        length=n;
        int i=0;
        int j=1;
        memset(sign,0,sizeof(sign)); //对于数组进行 0值初始化
        while(length>1) //模拟过程
        {
            while(i<m)
            {
                if(sign[j%n]==0)
                {
                    i++;
                    j++;
                }
                else
                    j++;
            }
            i=0;
            sign[(j-1)%n]=1;//节点被赋值为1，即该节点已退出~
            length--;
        }
        for(j=0;j<n;j++) //循环，找出值为0的节点，此种解法属于暴力求解，没有运用任何技巧!
        {
            if(sign[j]==0)
                break;
        }
        if(j==0) //因为本出 0节点代表 n节点，为了方便取余所设置的~
            cout<<n<<endl;
        else
            cout<<j<<endl;
        cin>>n>>m;
    }
}
