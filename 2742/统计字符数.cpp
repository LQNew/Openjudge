/*
描述
判断一个由a-z这26个字符组成的字符串中哪个字符出现的次数最多
输入
    第1行是测试数据的组数n，每组测试数据占1行，是一个由a-z这26个字符组成的字符串
    每组测试数据之间有一个空行，每行数据不超过1000个字符且非空
输出
    n行，每行输出对应一个输入。一行输出包括出现次数最多的字符和该字符出现的次数，中间是一个空格。
    如果有多个字符出现的次数相同且最多，那么输出ascii码最小的那一个字符
*/
//分析：简单题型，用一个字符串数组存储输入的字符，在用一个int型数组记录各个字符出现的次数
//      此处需要注意的是，本次编译首次出现 presentation error的问题，就是输出格式出错，做题时应注意输出格式的问题！！
#include<iostream>
#include<string.h>
using namespace std;
char data[1001];//存储输入的字符，因为题目中提到输入的字符不超过1000个，故开设1001空间用于存储字符
int sum[26]; //统计 a-z各个字符出现的次数
int n;
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        memset(sum,0,sizeof(sum)); //对于数组的初始化
        cin>>data;
        for(int j=0;j<strlen(data);j++)
        {
            sum[int(data[j]-'a')]++; //对于各个字符出现的次数计数
        }
        int max=0;
        for(int k=1;k<26;k++)
        {
            if(sum[max]<sum[k]) max=k; //统计出现次数最多的字符
        }
        cout<<char(max+'a')<<" "<<sum[max]<<endl;
    }
    return 0;
}
