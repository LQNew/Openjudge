/*
    描述：输入一个数，输出其素因子分解表达式。
    输入
        输入一个整数 n (2 <= n < 100)。
    输出
        输出该整数的因子分解表达式。
        表达式中各个素数从小到大排列。
        如果该整数可以分解出因子a的b次方，当b大于1时，写做 a^b ；当b等于1时，则直接写成a。
*/
//分析：很简单的因子分解问题，因为n数值很小，所以题目难度不大，只需要留意基本的素因子分解的前提就好了~
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int n;
int decompose[10];
int cnt[10];
int main(){
    while(cin>>n){
        memset(decompose,0,sizeof(decompose));
        memset(cnt,0,sizeof(decompose));
        int j=0;
        int n1=n;
        for(int i=2;i<=sqrt(n);i++){ //留意此处应是<=sqrt(n)，一开始写成了<sqrt(n)，导致有些小问题！！
            int k=0;
            while(n1%i==0){
                k++;
                n1=n1/i;
            }
            if(k!=0){
                decompose[j]=i;
                cnt[j]=k;
                j++;
            }
        }
        if(n1!=1){
            decompose[j]=n1;
            cnt[j]=1;
            j++;
        }
        for(int i=0;i<j;i++){
            if(i==j-1){
                if(cnt[i]==1) cout<<decompose[i];
                else{
                    cout<<decompose[i]<<'^'<<cnt[i];
                }
            }
            else{
                if(cnt[i]==1) cout<<decompose[i]<<'*';
                else{
                    cout<<decompose[i]<<'^'<<cnt[i]<<'*';
                }
            }
        }
        cout<<endl;
    }
    return 0;
}
