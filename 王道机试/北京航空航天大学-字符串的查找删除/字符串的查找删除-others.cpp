#include <stdio.h>
#include <string>
#include <iostream>
#include <ctype.h>
using namespace std;
int main () {
    char str[101];
    gets(str); //输入短字符串
    string a = str; //将其保存在a中
    for (int i = 0;i < a.size();i ++) {
        a[i] = tolower(a[i]);
    } //将a中的字符全部改成小写
    while (gets(str)) { //输入长字符串
        string b = str,c = b; //将字符串保存至b,c
        for (int i = 0;i < b.size();i ++) {
            b[i] = tolower(b[i]);
        } //将b中字符全部改成小写,以便匹配
        int t = b.find(a,0); //在b中查找a的位置
        while (t != string::npos) { //若查找成功,则重复循环
            c.erase(t,a.size()); //删除c中相应位置字符,c为原串
            b.erase(t,a.size()); //删除b中相应位置字符,b为改为小写字符的串
            t = b.find(a,t); //继续查找b中下一个出现字符串a的位置
        }
        t = c.find(' ',0); //查找c中空格
        while(t != string::npos) {
            c.erase(t,1);
            t = c.find(' ',0);
        } //删除c中所有空格
        cout << c << endl; //输出
    }
    return 0;
}
