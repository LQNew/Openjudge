/*草原上有一种羚羊，假设它们出生时为0岁，那么经过3年的成长，当它们在3岁的时候会成年，并开始繁殖。
  每一对羚羊在3岁的那一年会产下两只小羚羊，并且这对成年羚羊结为永久的伴侣，在以后的每一年又生出两只小羚羊。
  假定一对羚羊产下的两只小羚羊必定为一雄一雌，羚羊在3岁时必定会找到另外一只同年羚羊结为永久伴侣，并开始繁殖。此外，假定这种羚羊在50岁以内不会死去。
  如果在第0年，草原上有一对0岁的羚羊，那么第n年末草原上有多少对羚羊？
  输入
  第一行是一个正整数m(1<=n<=15)，表示共有m个问题。
  下面m行，每行是一个数字n(0<=n<=40)，表示第n年。
  输出
  总共m行，每行一个数字，表示相应的第n年末草原上有几对羚羊。

  分析：可以在纸上推演寻找数学关系，后来发现符合类似于斐波那契的一种数列形式~
*/
#include<iostream>
using namespace std;
int computer_nums(int n) //类似斐波那契数列的函数代码实现
{
    //设置三个中间值变量:before middle num ;因为每一次新的值是当前值加上前前值生成的~
    //i.e   (0 1) 1 1 2 3 4 6 9
    int num=1;
    int num_middle=1;
    int num_before=0;
    for(int i=1;i<n;i++)
    {
        int j=num;
        num=num+num_before;
        num_before=num_middle;
        num_middle=j;
    }
    return num;
}

int main()
{
    int m;
    cin>>m;
    int n;
    for(int i=0;i<m;i++)
    {
        cin>>n;
        int num=computer_nums(n);
        cout<<num<<endl;
    }
    return 0;
}
