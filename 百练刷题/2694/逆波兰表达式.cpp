/*
    描述
        逆波兰表达式是一种把运算符前置的算术表达式，例如普通的表达式2 + 3的逆波兰表示法为+ 2 3。逆波兰表达式的优点是运算符之间不必有优先级关系，
        也不必用括号改变运算次序，例如(2 + 3) * 4的逆波兰表示法为* + 2 3 4。本题求解逆波兰表达式的值，其中运算符包括+ - * /四个。
    输入
        输入为一行，其中运算符和运算数之间都用空格分隔，运算数是浮点数。
    输出
        输出为一行，表达式的值。
*/
//分析，此道题是个递归题，可以用二叉树去体会思路，根节点是符号，往下每层都是符号，只有最底层是数字，然后返回去计算，从最底层算起直到算到根节点处
//体会本道题的递归思想！ 本道题用到了 cmath库的atof()函数用于获取字符串的数值
#include<iostream>
#include<cmath>
using namespace std;
double calculate()
{
    char symbol[10];
    cin>>symbol;
    if(symbol[0]=='*')
        return calculate()*calculate();
    else if(symbol[0]=='+')
        return calculate()+calculate();
    else if(symbol[0]=='-')
        return calculate()-calculate();
    else if(symbol[0]=='/')
        return calculate()/calculate();
    else
        return atof(symbol);
}
int main()
{
    double ans=calculate();
    printf("%f\n", ans); //输出精度有要求。。。
}
