//本道题和POJ上的四则运算表达式相比，难度要小一些，不过此处我仍然按照将中缀表达式转换为后缀表达式的思想去处理题目
//此类题型颇有意思，要多多把玩！
//关于此道题的输入形式很有意思，用了C语言中的gets()函数读取一行数据，然后之后用strcmp()函数比对，注意比对必须是字符串！
#include<iostream>
#include<stack>
#include<cstring>
#include<iomanip>
#include<cmath>
using namespace std;
char symbol[201];
char formular[201];
stack<char>mystack;
stack<double>result;
char a,b;
bool compare(char a,char b) //比较运算符的优先级，优先级低或者一致时，当前栈内的运算符弹出：+和-优先级最低，*和/的优先级高于 +和-
{
    if(b=='+'||b=='-')
    {
        if(a=='+'||a=='-')
            return false;
    }
    else if(b=='*'||b=='/')
    {
        if(a=='+'||a=='-'||a=='*'||a=='/')
            return false;
    }
    return true;
}

void transform_1()
{
    int sum=0;
    int i;
    for(i=0;i<strlen(symbol);i++)
    {
        a=symbol[i];
        if(a==' ')
            continue;
        if(a=='+'||a=='-')
        {
            if(mystack.empty()) //如果栈空则压入
                mystack.push(a);
            else
            {
                b=mystack.top();
                if(compare(a,b)) //将当前的运算符和栈顶的运算符比较优先级，如果优先级高则直接压入栈
                {
                    mystack.push(a);
                }
                else
                {
                    while(!compare(a,b)) //否则的话比较优先级，直至碰到比自己优先级低的才罢手，当然此处如果碰到左括号，那么符号会直接压入
                    {
                        formular[sum++]=b;
                        mystack.pop();
                        if(mystack.empty())
                            break;
                        b=mystack.top();
                    }
                    mystack.push(a);
                }
            }
        }
        else if(a=='*'||a=='/')
        {
            if(mystack.empty())
                mystack.push(a);
            else
            {
                b=mystack.top();
                if(compare(a,b))
                {
                    mystack.push(a);
                }
                else
                {
                    while(!compare(a,b))
                    {
                        formular[sum++]=b;
                        mystack.pop();
                        if(mystack.empty())
                            break;
                        b=mystack.top();
                    }
                    mystack.push(a);
                }
            }
        }
        else //如果不是运算符，那么是数值型，于是检索，将所有的数值型变量均存至数组中，并添加空格用于标识分隔
        {
            while(a!=' ')
            {
                formular[sum++]=a;
                i++;
                if(i==strlen(symbol))//如果查询至中缀表达式的式尾，则跳出
                    break ;
                a=symbol[i];
            }
            if(i==strlen(symbol)) //如果查询到最后，仍要添加一个空格符
            {
                formular[sum++]=' ';
                break;
            }
            formular[sum++]=' ';
        }
    }
    while(!mystack.empty()) //最后将所有仍在栈中的运算符弹出栈
    {
        b=mystack.top();
        formular[sum++]=b;
        mystack.pop();
    }
    formular[sum++]='\0';
}

void calculate()//用于运算转换后的逆波兰表达式
{
    char num[10];
    double num1,num2,result1;
    int i=0;
    for(i=0;i<strlen(formular);i++)
    {
        a=formular[i];
        if(a=='+') //对于不同的运算符执行不同的运算操作
        {
            num1=result.top();
            result.pop();
            num2=result.top();
            result.pop();
            result1=num1+num2;
            result.push(result1);
        }
        else if(a=='-')
        {
            num1=result.top();
            result.pop();
            num2=result.top();
            result.pop();
            result1=num2-num1;
            result.push(result1);
        }
        else if(a=='*')
        {
            num1=result.top();
            result.pop();
            num2=result.top();
            result.pop();
            result1=num1*num2;
            result.push(result1);
        }
        else if(a=='/')
        {
            num1=result.top();
            result.pop();
            num2=result.top();
            result.pop();
            result1=num2/num1;
            result.push(result1);
        }
        else //如果为数值，那么将当前的这一数值完整遍历出来，并用char型数组存储，方便调用atof()函数将其转换为double型数值
        {
            memset(num,0,sizeof(int)); //num数组每次都应初始化
            int flag=0;
            while(a!=' ')
            {
                num[flag++]=a;
                i++;
                if(i==strlen(formular))
                    break;
                a=formular[i];
            }
            result.push(atof(num));
        }
    }
}

int main()
{
    while(gets(symbol))
    {
        if(strcmp("0", symbol)==0) break;
        transform_1();
        calculate();
        cout<<fixed<<setprecision(2)<<result.top()<<endl; //运算结束后，栈中只会有一个double型数据留下，就是最终的结果~，本处设置了小数点只有两位，留意此处的设置形式！
    }
    return 0;
}
