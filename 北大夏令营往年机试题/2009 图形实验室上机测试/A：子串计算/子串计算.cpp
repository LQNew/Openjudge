//字符串处理问题，感觉本道题是做过的题目中字符串处理类型最难得一道题..
//本道题我的思路就是把所有不重复的子字符串提出来，为了保证子字符串不重复，特地用了一个map容器映射保证重复的字符串不存储，同时保证子字符串是按字典序排序的
//字符串的子字符串 的函数.substr()函数的用法一定要熟悉，它是必须得掌握的函数，同时关于字符串负值函数的使用也要了解，本处是strncpy()函数，三个参数
//第一参数是待被赋值的char型数组，第二个参数是string变量的首地址，第三个参数是string变量的尾地址+1
//还有关于字符串比对用到了strncmp()，这个函数也是第一次使用，也是三个参数，第一个参数是被比较的字符串的起始地址，第二个是比较的字符串，第三个是比较的字符串的长度
//关于map容器的遍历，用到了iter指针遍历，iter指针的声明也很有特色要熟悉！
//总而言之，本道题是字符串处理问题的巅峰难度，我觉得应该勤加巩固此题思路!很有帮助！
#include<iostream>
#include<string>
#include<map>
#include<cstring>
using namespace std;
string str1;
map<string,int> M;
char substr1[101];
char str2[101];

int cmp(char* str, char* substr1) //比对子串重复次数
{
    int i=0,cnt=0,len1,len2;
    len1=strlen(str);
    len2=strlen(substr1);
    while(i <= len1-len2)
    {
        if(strncmp(str+i,substr1,len2) == 0) cnt++;
        i++;
    }
    return cnt;
}

int main(){
    cin>>str2;
    string str1=str2;
    M.clear();
    int len=str1.length();
    string st;
    int idx=-1;
    for(int i=0;i<len;i++){
        for(int j=1;j<=len-i;j++){
            st=str1.substr(i,j); //substr(i,j) 代表从字符串第i个位置开始，往后j个字符均为下一个子串
            if(M.find(st)==M.end()){ //用map映射管理，将重复的字符串剔除
                idx++;
                M[st]=idx;
            }
        }
    }
    //此处需要注意的是对于map映射，默认的就是按键值有个排序，因为是string类型，所以默认就是按字典排序
    map<string, int>::iterator iter; //遍历map表的指针
    iter = M.begin();
    while(iter!= M.end()){
        string a=iter->first;
        strncpy(substr1, a.c_str(), a.length()+1); //将string类型转化为char型
        int ans=cmp(str2,substr1);
        if(ans>1) cout<<substr1<<' '<<ans<<endl;
        iter++;
    }
    return 0;
}
