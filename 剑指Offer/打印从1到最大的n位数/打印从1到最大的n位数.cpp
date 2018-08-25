// 递归思路，对于递归问题，我写得不是很娴熟，思路还是有点僵化！
#include<iostream>
#include<cstring>
using namespace std;

void Print(char* number){ // 打印字符串，并去除首部的空格
    int i = 0;
    int length = strlen(number);
    bool flag = true;
    while(i<length){
        if(number[i] == '0' && flag){
            flag = true;
            i++;
        }
        else{
            cout<<number[i];
            i++;
            flag = false;
        }
    }
    cout<<' '; // 横向空格
}

void PrintCycle(char* number, int length, int index){ // 循环，每次打印除去首位数字的其他数字位的循环体
    if(index == length - 1){
        Print(number);
        return;
    }
    for(int i=0;i<10;i++){
        number[index + 1] = i + '0';
        PrintCycle(number, length, index + 1);
    }
}

void PrintToMax(int n){
    if(n <= 0) return;
    char* number = new char[n + 1];
    number[n] = '\0'; // 构造字符串
    for(int i=0;i<10;i++){
        number[0] = i + '0'; // 初始化首位数字
        PrintCycle(number, n, 0);
    }
    delete[] number;

}

int main(){
    int n;
    cin>>n;
    PrintToMax(n);
    return 0;
}
