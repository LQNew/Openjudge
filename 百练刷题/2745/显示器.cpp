/*
    描述
        你的一个朋友买了一台电脑。他以前只用过计算器，因为电脑的显示器上显示的数字的样子和计算器是不一样，所以当他使用电脑的时候会比较郁闷。
        为了帮助他，你决定写一个程序把在电脑上的数字显示得像计算器上一样。
    输入
        输入包括若干行，每行表示一个要显示的数。每行有两个整数s和n (1 <= s <= 10, 0 <= n <= 99999999)，这里n是要显示的数，s是要显示的数的尺寸。
        如果某行输入包括两个0，表示输入结束。这行不需要处理。
    输出
        显示的方式是：用s个'-'表示一个水平线段，用s个'|'表示一个垂直线段。这种情况下，每一个数字需要占用s+2列和2s+3行。
        另外，在两个数字之间要输出一个空白的列。在输出完每一个数之后，输出一个空白的行。注意：输出中空白的地方都要用空格来填充。
*/
#include<iostream>
#include<cstring>
using namespace std;
char n1[11]="- -- -----"; //将数字分为七个段 去判别十个数字是否为横、竖
char n2[11]="|   ||| ||";
char n3[11]="|||||  |||";
char n4[11]="  ----- --";
char n5[11]="| |   | | ";
char n6[11]="|| |||||||";
char n7[11]="- -- -- --";

int s;
char n[12];
int main()
{
    cin>>s>>n;
    while(s!=0||strcmp(n,"0")!=0) //与和或的关系用错了！！
    {
        for(int i=0;i<strlen(n);i++) //模拟分析
        {
            cout<<" ";
            for(int j=0;j<s;j++)
                cout<<n1[n[i]-'0'];
            cout<<"  ";
        }
        cout<<endl;
        for(int k=0;k<s;k++)
        {
            for(int i=0;i<strlen(n);i++)
            {
                cout<<n2[n[i]-'0'];
                for(int j=0;j<s;j++)
                    cout<<" ";
                cout<<n3[n[i]-'0']<<" ";
            }
            cout<<endl;
        }
        for(int i=0;i<strlen(n);i++)
        {
            cout<<" ";
            for(int j=0;j<s;j++)
                cout<<n4[n[i]-'0'];
            cout<<"  ";
        }
        cout<<endl;
        for(int k=0;k<s;k++)
        {
            for(int i=0;i<strlen(n);i++)
            {
                cout<<n5[n[i]-'0'];
                for(int j=0;j<s;j++)
                    cout<<" ";
                cout<<n6[n[i]-'0']<<" ";
            }
            cout<<endl;
        }
        for(int i=0;i<strlen(n);i++)
        {
            cout<<" ";
            for(int j=0;j<s;j++)
                cout<<n7[n[i]-'0'];
            cout<<"  ";
        }
        cout<<endl<<endl;
        cin>>s>>n;
    }
    return 0;
}
