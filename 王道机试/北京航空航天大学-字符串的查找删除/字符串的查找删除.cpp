/*
    给定一个短字符串（不含空格），再给定若干字符串，在这些字符串中删除所含有的短字符串。 并去掉空格,输出。
*/
//本道题利用到了 string stl库的函数操作，尤其是string库的find()函数以及 erase()函数，要多了解~，题目在string下操作比较简洁是道比较典型的题目
//也应该留意gets函数的使用，它可以读入空格，只有遇到换行符才会终止！
//了解gets的输入特点，当程序运行至gets语句后，它将依次读入遗留在输入缓冲中的数据直到出现换行符，并将除换行符外的所有已读字符保存在字符数组中，
#include <iostream>
#include <string>
using namespace std;
int main () {
    char str[101];
    gets(str); //输入短字符串
    string a=str;
    for (int i=0;i<a.size();i++) {
        a[i] = tolower(a[i]); //string 字符串的操作，将a中的字符全部改成小写
    }
    while(gets(str)) { //每输入一个长字符串便进行处理
        string b=str;
        string c = b; //将字符串保存至b,c
        for (int i = 0;i < b.size();i ++) {
            b[i] = tolower(b[i]);//将b中字符全部改成小写,以便匹配
        }
        int t = b.find(a,0); //在b中查找a的位置
        while (t != string::npos) { //若查找成功,则重复循环,find函数在找不到指定值的情况下会返回string::npos
            c.erase(t,a.size()); //删除c中相应位置字符,c为原串
            b.erase(t,a.size()); //删除b中相应位置字符,b为改为小写字符的串
            t = b.find(a,t); //继续查找b中下一个出现字符串a的位置
        }
        t = c.find(' ',0); //查找c中空格
        while(t != string::npos) {
            c.erase(t,1); //删除c中所有空格
            t = c.find(' ',0);
        }
        cout<<c<<endl; //输出
    }
    return 0;
}
