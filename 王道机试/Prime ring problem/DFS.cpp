/*
    A ring is composed of n (even number) circles as shown in diagram.Put natural numbers 1, 2, . . . , n into each circle separately, and the
    sum of numbers in two adjacent circles should be a prime.
    Output
        The output format is shown as sample below. Each row represents a series of circle numbers in the
        ring beginning from 1 clockwisely and anticlockwisely. The order of numbers must satisfy the above
        requirements.
*/
//分析：这是个一个常见的深搜题，没有什么剪枝操作，但是DFS代码的书写还是需要注意！并没有那么容易书写！！要有递归的思想！！
//深搜相较于广搜，它对于思维的要求更深刻，本道题是一道经典的题型，要细心把玩理解！！
#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
int n;
int ans[17];
bool mark[17];
bool judge(int x){ //判别是否为素数
    if(x==2) return true;
    else{
        for(int i=2;i<=sqrt(double(x));i++){
            if(x%i==0) return false;
        }
    }
    return true;
}
void Dfs(int num){
    if(num==n&&judge(ans[n]+ans[1])){
        for(int i=1;i<n;i++) cout<<ans[i]<<' ';
        cout<<ans[n]<<endl;
    }
    else if(num==n&&!judge(ans[n]+ans[1])) return;
    else{
        for(int i=2;i<=n;i++){
            if(!mark[i]&&judge(i+ans[num])){
                mark[i]=true;
                ans[num+1]=i;
                Dfs(num+1);
                mark[i]=false;
            }
        }
        return;
    }
}
int main(){
    int t=0;
    while(cin>>n){
        if(t!=0) cout<<endl; //迎合输出格式，也是很恶心的输出格式要求了...
        t++;
        ans[1]=1;
        memset(mark,0,sizeof(mark));
        mark[1]==true;
        cout<<"Case "<<t<<':'<<endl;
        Dfs(1);

    }
    return 0;
}
