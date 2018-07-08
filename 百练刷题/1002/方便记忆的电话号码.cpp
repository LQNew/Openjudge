/*
    描述
    英文字母（除Q和Z外）和电话号码存在着对应关系，如下所示：
    A,B,C -> 2
    D,E,F -> 3
    G,H,I -> 4
    J,K,L -> 5
    M,N,O -> 6
    P,R,S -> 7
    T,U,V -> 8
    W,X,Y -> 9
    标准的电话号码格式是xxx-xxxx，其中x表示0-9中的一个数字。有时为了方便记忆电话号码，我们会将电话号码的数字转变为英文字母，如把263-7422记成America。
    有时，我们还加上“-”作为分隔符，如把449-6753记成Hi-World。当然，我们未必要将所有的数字都转变为字母，比如474-6635可以记成iPhone-5。
    总之，一个方便记忆的电话号码由数字和除Q、Z外的英文字母组成，并且可以在任意位置插入任意多的“-”符号。
    现在 ，我们有一个列表，记录着许多方便记忆的电话号码。不同的方便记忆的电话号码可能对应相同的标准号码，你的任务就是找出它们。

    输入
        第一行是一个正整数n（n <= 100000），表示列表中的电话号码数。
        其后n行，每行是一个方便记忆的电话号码，它由数字和除Q、Z外的英文字母、“-”符号组成，其中数字和字母的总数一定为7，字符串总长度不超过200。
    输出
        输出包括若干行，每行包括一个标准电话号码（xxx-xxxx）以及它重复出现的次数k（k >= 2），中间用空格分隔。输出的标准电话号码需按照升序排序。
        如果没有重复出现的标准电话号码，则输出一行“No duplicates.”。
*/
//分析：本道题首先是要将输入的电话号码转换为标准形式，关于字母可以用一个数组将其关系映射
//接下来需要做的是对于电话号码进行快速排序，关于针对字符串的快速排序，一定要熟悉，这是个固定的模板套路
//之后就是对于快排的电话号码两两比对，得到重复数目并输出
#include<iostream>
#include<cstring>
using namespace std;
char standard[100000][10]; //用于存储全部的标准化后的电话号码
char input[201]; //用于暂时存储输入的不规整的电话号码
int n; //输入的电话号码总数
char map[26]={'2','2','2','3','3','3','4','4','4','5','5','5','6','6','6','7','7','7','7','8','8','8','9','9','9','9'};//映射关系

void transform1(int i)
{
    int cnt=0;
    for(int j=0;j<strlen(input);j++)
    {
        if(input[j]=='-') //如果出现'-'号，那么剔除
            continue;
        else
        {
            if(cnt==8) //如果总数>8,说明有用信息已经录完了，退出
                break;
            if(cnt==3) //此时可以添加一个'-'号
            {
                standard[i][cnt]='-';
                cnt++;
            }
            if(input[j]>='0'&&input[j]<='9')
            {
                standard[i][cnt]=input[j];
                cnt++;
            }
            else if(input[j]>='A'&&input[j]<='Z')
            {
                standard[i][cnt]=map[input[j]-'A'];
                cnt++;
            }
        }
    }
}

int compare(const void*a,const void*b) //用于字符串比对的compare函数
{
    return strcmp((char*)a,(char*)b);
}

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>input;
        transform1(i); //标准化字符串
    }
    qsort(standard,n,sizeof(standard[0]),compare);
    int cnt=1;
    bool flag=false;
    for(int i=0;i<n-1;i++)
    {
        if(strcmp(standard[i],standard[i+1])==0) //找出所有重复数>=2的电话号码并输出
        {
            cnt++;
            flag=true;
        }
        else
        {
            if(cnt>=2)
            {
                cout<<standard[i]<<" "<<cnt<<endl;
                cnt=1;
            }
        }
    }
    if(flag&&cnt>=2) //上面的循环并没有充分考虑到倘若最后一组也有循环时怎么办，于是在此额外处理下如果最后一组也是重复时输出它
        cout<<standard[n-1]<<" "<<cnt<<endl;
    else if(!flag)
        cout<<"No duplicates."<<endl;
}
