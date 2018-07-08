/*
    描述
        求一个可以带括号的小学算术四则运算表达式的值
    输入
        一行，一个四则运算表达式。'*'表示乘法，'/'表示除法
    输出
        一行，该表达式的值，保留小数点后面两位
*/
//分析：关于四则运算表达式的求值，是一个典型问题，它的解法通常将中缀表达式转换为后缀表达式：
//a + b*c + (d * e + f) * g -->a b c * + d e * f  + g * + ；后缀表达式又被称为逆波兰表达式，从左至右，表达式每个元素依次入栈，对于数值型直接进栈
//对于符号，则是对应的 当前栈顶元素与次栈顶元素按照符号运算法则运算
//故本道题的核心是如何将前缀表达式转换为后缀表达式，简单来说，就是对于数值型的直接输出，而关于符号型，需要比较优先级后输出，详细的讲解见博客：
//https://blog.csdn.net/sgbfblog/article/details/8001651
//博客中给出的图示，但是编程实现时还需要利用栈结构以及字符数组去存储输出的逆波兰表达式，同时本处为了利于之后的double型数字提取，在在数字输出时可以添加了空格符以作为隔开的标志
//最后获得了转换后的数组之后，再按照逆波兰表达式求法 利用栈结构进行求值
//本道题难度较大，考虑的细节很多，主要利用了stack库的一系列入栈、出栈、检测非空、取栈顶值等函数
//iomanip库的setprecision()以及fixed()函数用于设置输出的小数点精度；cstring的memset()函数用于初始化数组；cmath库的atof()函数用于将字符数组转换为相应的double型变量
#include<iostream>
#include<iomanip>
#include<stack>
#include<cstring>
#include<cmath>
using namespace std;
stack<char>mystack;
stack<double>result;
char formular[300];
char symbol[300];
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

void transform_1()//将中缀表达式转换为后缀表达式
{
    int sum=0;//用于计数后缀表达式的位置
    int i;
    for(i=0;i<strlen(symbol);i++)
    {
        a=symbol[i];
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
        else if(a=='(') //如果是左括号，直接压入
            mystack.push(a);
        else if(a==')') //如果是右括号，那么向左边查询，找到左括号，中间的运算符均打印出来
        {
            b=mystack.top();
            while(b!='(')
            {
                mystack.pop();
                formular[sum++]=b;
                b=mystack.top();
            }
            mystack.pop();
        }
        else //如果不是运算符，那么是数值型，于是检索，将所有的数值型变量均存至数组中，并添加空格用于标识分隔
        {
            while(a!='-'&&a!='+'&&a!='*'&&a!='/'&&a!='('&&a!=')') //当不出现运算符时，当前全都是数值型变量
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
            i--;
            formular[sum++]=' ';
        }
    }
    while(!mystack.empty()) //最后将所有仍在栈中的运算符弹出栈
    {
        b=mystack.top();
        formular[sum++]=b;
        mystack.pop();
    }
}

void calculate()//用于运算转换后的逆波兰表达式
{
    char num[10];
    double num1,num2,result;
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
    cin>>symbol;
    transform_1();
    calculate();
    cout<<fixed<<setprecision(2)<<result.top()<<endl; //运算结束后，栈中只会有一个double型数据留下，就是最终的结果~，本处设置了小数点只有两位，留意此处的设置形式！
    return 0;
}
