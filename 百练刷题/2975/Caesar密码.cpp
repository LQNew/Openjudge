/*
    输入
        最多不超过100个数据集组成。每个数据集由3部分组成：
        起始行：START
        密码消息：由1到200个字符组成一行，表示Caesar发出的一条消息
        结束行：END
        在最后一个数据集之后，是另一行：ENDOFINPUT
    输出
        每个数据集对应一行，是Caesar 的原始消息。
*/
//分析：本道题比较简单，最主要的是应该注意格式的要求，此道题需用 cin.getline()接收数据
#include <iostream>
#include <string.h>
using namespace std;
char message[201];
char decoding_message[201]; //存储翻译后的字符串
char decoding_table[]="VWXYZABCDEFGHIJKLMNOPQRSTU"; //译码表

void Decode()
{
    int i=0;
    for(i;i<strlen(message);i++)
    {
        if(message[i]>='A'&&message[i]<='Z')
            decoding_message[i]=decoding_table[message[i]-'A'];
        else
            decoding_message[i]=message[i];
    }
    decoding_message[i]='\0';
    cin.getline(message,200); //留意cin.getline()函数的使用，用于按行接收数，而cin是碰到空格或换行就读取结束
    cout<<decoding_message<<endl;
    cin.getline(message,200);
}

int main()
{
    cin.getline(message,200);
    while(strcmp(message,"START")==0) //strcmp字符串比对函数
    {
        cin.getline(message,200);
        Decode();
    }
    return 0;
}
