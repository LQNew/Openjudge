//水题，用string stl库解决此问题，难度稍小一些！
#include<iostream>
#include<string>
using namespace std;
int N;
int num1;
char str1[100];
int main(){
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>num1;
        cin>>str1;
        string a=str1;
        a.erase(num1-1,1); //清除从字符串下标 num1-1 开始的1个字符！
        cout<<i+1<<' '<<a<<endl;
    }
    return 0;
}
