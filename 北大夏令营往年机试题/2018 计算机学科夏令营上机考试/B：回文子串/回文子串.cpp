//字符串处理问题，主要用到了reverse函数，substr()函数用于子串的截取，然后用了map进行一个映射，其实此处没必要做映射的，增设一个string变量存储就好了，但是编的时候没动脑子就这么编了
//本道题线下测试是样例都过的，但是没有线上确认AC
#include<iostream>
#include<string>
#include<algorithm>
#include<map>
using namespace std;
int n;
string str1;
map<int, string> M;
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>str1;
        string c;
        string b;
        int max1=0;
        M.clear();
        for(int i=0;i<str1.size()-1;i++){
            for(int j=str1.size()-i;j>max1;j--){
                c=str1.substr(i,j);
                b=c;
                reverse(c.begin(),c.end());
                if(b==c){
                    if(M.find(j)==M.end()){
                        M[j]=c;
                    }
                    max1=j;
                }
            }
        }
        if(max1==0) cout<<str1<<endl;
        else cout<<M[max1]<<endl;
    }
    return 0;
}
