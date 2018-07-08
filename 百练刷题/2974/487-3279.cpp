/*
    输入
        输入的格式是，第一行是一个正整数，指定电话号码薄中号码的数量（最多100000）。
        余下的每行是一个电话号码。每个电话号码由数字，大写字母（除了Q和Z）以及连接符组成。每个电话号码中只会刚好有7个数字或者字母。
    输出
        对于每个出现重复的号码产生一行输出，输出是号码的标准格式紧跟一个空格然后是它的重复次数。
        如果存在多个重复的号码，则按照号码的字典升序输出。如果输入数据中没有重复的号码，输出一行：No duplicates.
*/
/*
分析：
    开一个大的二维数组用于存储所有输入的电话号码转换后的形式
    对于转换后的电话号码整个进行排序
    对于排序后的电话号码计数输出重复的电话号码数目
*/

#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
char map[27]="22233344455566677778889999"; //建立字母向数字映射的字符数组
char TelNum[100000][9]; //将所有的电话号码存储在一个二维数组中，注意此处字符当做字符串处理用于之后的字符串的比对，所以一行为9个单位，最后一个单位存储\0
char str[100]; //用于存储从屏幕输入的数据，单位应设的大一些！

void Transfer(int n)
{
    int j,k=0;
    for(int i=0;i<strlen(str);i++)
    {
        if(k==3) {TelNum[n][k]='-';k++;}
        if(str[i]=='-')
            continue;
        if(str[i]>='A'&&str[i]<='Z')
            TelNum[n][k++]=map[str[i]-'A'];
        else
            TelNum[n][k++]=str[i];
    }
    TelNum[n][k]='\0';//加上换行符，代表为每一行为一个字符串

}

int compare(const void*a,const void*b) //用于qsort 使用的compare函数，有关此compare函数的书写应留意！
{
    return strcmp((char *)a,(char *)b); //转化为字符串数组元素的比对，留意strcmp函数的使用
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>str;
        Transfer(i); //将输入的数据转化
    }

    qsort(TelNum,n,9,compare); //调用C++模板中的排序函数
    /*qsort函数： qsort ( 数组名 ，元素个数，元素占用的空间(sizeof)，比较函数)
      比较函数是一个自己写的函数  遵循 int com(const void *a,const void *b) 的格式。
      当a b关系为 >  <  = 时，分别返回正值 负值 零 （或者相反）。
      使用a b 时要强制转换类型，从void * 转换回应有的类型后，进行操作。
    */

    bool total_repeat= false;
    int i=0,j=0;
    while(i<n)
    {
        bool repeat=false;
        j=i;
        i++;
        //strcmp函数，留意它的头文件必须是 <string.h>头文件，
        //strcmp(s1,s2) 若参数s1 和s2 字符串相同则返回0、s1 若大于s2 则返回大于0 的值、s1 若小于s2 则返回小于0的值。
        while(strcmp(TelNum[i],TelNum[j])==0) //用于计数排好序后的数组中的重复元素的个数！此处思路较为巧妙，自己要掌握此种思路~
        {
            i++;
            repeat=true;
            total_repeat=true;
        }
        if(repeat)
            cout<<TelNum[i-1]<<" "<<i-j<<endl;
    }
    if(total_repeat==false)
        cout<<"No duplicates."<<endl;
}
