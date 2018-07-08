/*一个笼子里面关了鸡和兔子（鸡有2只脚，兔子有4只脚，没有例外）。已经知道了笼子里面脚的总数a，问笼子里面至少有多少只动物，至多有多少只动物
  输入:一个正整数a
  输出：一行，包含两个正整数，第一个是最少的动物数，第二个是最多的动物数，两个正整数用一个空格分开
*/
//思路的巧妙处是：利用鸡兔的脚数目均为偶数的特性，去计算最多和最少的动物数~
#include<iostream>
using namespace std;
void computer(int num_feet)
{
    if(num_feet%2)
        cout<<0<<" "<<0<<endl;
    else
    {
        if(num_feet%4)
            cout<<num_feet/4+1<<" "<<num_feet/2<<endl;
        else
            cout<<num_feet/4<<" "<<num_feet/2<<endl;
    }
}
int main()
{
    int num_feet;
    while(cin>>num_feet)
    {
        computer(num_feet);
    }
    return 0;
}
