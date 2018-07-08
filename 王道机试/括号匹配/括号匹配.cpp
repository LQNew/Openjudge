#include<iostream>
#include<cstring>
#include<stack>
using namespace std;
stack<int> S; //定义一个堆栈
char str[110]; //保存输入字符串
char ans[110]; //保存输出字符串
int main () {
    while (cin>>str) { //输入字符串
        int i;
        for (i = 0;i<strlen(str);i ++)
        { //从左到右遍历字符串
            if (str[i] == '(')  //若遇到左括号
            {
                S.push(i); //将其数组下标放入堆栈中
                ans[i] = ' '; //暂且将对应的输出字符串位置改为空格
            }
            else if (str[i] == ')')
            { //若遇到右括号
                if (!S.empty())
                { //若此时堆栈非空
                     S.pop(); //栈顶位置左括号与其匹配,从栈中弹出该已经匹配的左括号
                     ans[i] = ' '; //修改输出中该位置为空格
                }
                else ans[i] = '?'; //若堆栈为空,则无法找到左括号与其匹配,修改输出中该位置为?
            }
            else ans[i] = ' '; //若其为其它字符,与括号匹配无关，则修改输出为空格
        }
        while(!S.empty()) //当字符串遍历完成后,尚留在堆栈中的左括号无法匹配
        {
            ans[ S.top() ] = '$'; //修改其在输出中的位置为$
            S.pop(); //弹出
        }
        ans[i] = '\0'; //为了使输出形成字符串，在其最后一个字符后添加一个空字符
        cout<<str<<endl;  //输出原字符串
        cout<<ans<<endl; //输出答案字符串
    }
    return 0;
}
