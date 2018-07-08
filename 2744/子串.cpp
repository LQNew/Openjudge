/*
    描述
        现在有一些由英文字符组成的大小写敏感的字符串，你的任务是找到一个最长的字符串x，使得对于已经给出的字符串中的任意一个y，x或者是y的子串，
        或者x中的字符反序之后得到的新字符串是y的子串。
    输入
        输入的第一行是一个整数t (1 <= t <= 10)，t表示测试数据的数目。对于每一组测试数据，第一行是一个整数n (1 <= n <= 100)，表示已经给出n个字符串。
        接下来n行，每行给出一个长度在1和100之间的字符串。
    输出
        对于每一组测试数据，输出一行，给出题目中要求的字符串x的长度。
*/
//分析：将获取得到的字符串先存储下来，再去找公有子串，重点需要重视的是string函数的几个模板函数:
//      strstr 在字符串中寻找子字符串 ; strcpy 复制字符串 ; strncpy 复制子字符串 ; strlen 计算字符串的长度 ; reverse 对于数组进行逆序操作

#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
char all_str[100][101]; //二维函数，用于存储所有输入的字符串
char min_str[101]; //用于存储最短长度的字符串
char max_substr[101]; //用于存储子串
char max_rev_substr[101]; //用于存储子串的逆序形式
int n,t; //输入 t、n

int Find_max_str()
{
    int k=strlen(min_str);
    for(int i=k;i>0;i--)
    {
        for(int j=0;j<=k-i;j++)
        {
            strncpy(max_substr,min_str+j,i); //strncpy 复制函数，复制字符串中指定长度及位置处的子串至指定的字符数组中
            strncpy(max_rev_substr,min_str+j,i);
            max_substr[i]=max_rev_substr[i]='\0';//添加'\0'表示为字符串数据
            reverse(max_rev_substr,max_rev_substr+i); //调用 algorithm库中的 reverse函数将数组中的数据逆序存储
            int cnt=0;
            for(int num=0;num<n;num++)
            {
                if(strstr(all_str[num],max_substr)||strstr(all_str[num],max_rev_substr)) //strstr函数 查找字符串中是否含有相应的子字符串
                    cnt++; //每匹配一个，计数+1
            }
            if (cnt==n) //若匹配的总个数等于输入的字符串个数，说明为公有子串
                return i;
        }

    }
    return 0;
}

int main()
{
    cin>>t;
    for(int i=0;i<t;i++)
    {
        cin>>n;
        int min_len=101;
        for(int j=0;j<n;j++)
        {
            cin>>all_str[j];
            if(strlen(all_str[j])<min_len) //找出最短长度的字符串，因为最长公共子串一定要含在最短长度的字符串中，这样会减少开销！
            {
                min_len=strlen(all_str[j]);
                strcpy(min_str,all_str[j]);
            }
        }
        cout<<Find_max_str()<<endl;
    }
    return 0;
}
