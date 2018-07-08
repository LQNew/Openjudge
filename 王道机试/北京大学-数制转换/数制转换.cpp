#include<iostream>
#include<cstring>
using namespace std;
long a,b,temp;
long num,num1;
char input[100]; //存储输入的数
int final[40];//用于存储转换为相应进制后的数
char transform_1[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'}; //用于最后的数制转换输出
long multiply(long m,long sum,int b) //高精度乘法运算
{
    if(sum==0)
        return 0;
    while(b--)
    {
        sum=sum*m;
    }
    return sum;
}

int main()
{
    while(cin>>a>>input>>b)
    {
        num=0;
        int j=0;
        for(int i=strlen(input)-1;i>=0;i--) //获取对应为真实的十进制数
        {
            if(input[i]>='0'&&input[i]<='9')
                temp=input[i]-'0';
            else if(input[i]>='A'&&input[i]<='F')
                temp=input[i]-'A'+10;
            else
                temp=input[i]-'a'+10;
            num+=multiply(a,temp,j);
            j++;
        }
        int flag=0;
        memset(final,0,sizeof(final[0]));
        if(num==0) //留意此处！
        {
            cout<<0<<endl;
            continue;
        }
        num1=num;
        while(num!=0)
        {
            num=num/b;
            final[flag++]=num1%b;
            num1=num;
        }
        for(int i=flag;i--;i>=0)
            cout<<transform_1[final[i]];
        cout<<endl;
    }
    return 0;
}
