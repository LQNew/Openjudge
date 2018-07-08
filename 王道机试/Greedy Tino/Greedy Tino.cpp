//本道动规题难度较大，不太好想出合适的解法！
/*  分析：
    因为本题要求解的是重量相等的两堆柑橘中每堆的最大重量，并且在堆放过程中，由于新的柑橘被加到第一堆或者第二堆，两堆之间的重量差会动态发生改
    变，所以我们设状态 dp[i][j]表示前 i 个柑橘被选择后（每个柑橘可能放到第一堆或者第二堆）后，第一堆比第二堆重 j 时（当 j 为负时表示第二堆比第一堆重），
    两堆的最大总重量和。
    初始时，dp[0][0]为 0，即不往两堆中加任何柑橘时，两堆最大总重量为 0；dp[0][j]（j 不等于 0）为负无穷，即其它状态都不存在。
    根据每一个新加入的柑橘被加入到第一堆或者第二堆或者不加到任何一堆，设当前加入柑橘重量为 weight[i]，这将造成第一堆与第二堆的重量差增大 weight[i]或减
    小 weight[i]或者不变，我们在它们之中取最大值，其状态转移为： dp[i][j]=max(dp[i-1][j-weight[i]]+weight[i],dp[i-1][j+weight[i]]+weight[i],dp[i-1][j])
    当根据该状态转移方程求出所有的状态后，状态 dp[n][0] / 2 即是所求
*/
#include<iostream>
using namespace std;
const int offset=2000;
int n;
int t;
int weight_1,cnt; //每个柑橘的重量以及总共柑橘的数目
bool flag;//用于标识是否有重量为0的柑橘
int weight[101];
int dp[101][4001]; //表示加入前i个柑橘后，第一堆比第二堆重j时，两堆的最大重量和，因为考虑到可能第二堆比第一堆重，于是引入offset=2000将差值均拉至正数范围内
int main(){
    cin>>t;
    for(int i=0;i<t;i++){
        flag=false;
        cin>>n;
        cnt=0;
        for(int i=1;i<=n;i++){
            cin>>weight_1;
            if(weight_1==0){
                flag=true;
                continue;
            }
            else{
                cnt++;
                weight[cnt]=weight_1;
            }
        }
        for(int i=-2000;i<=2000;i++) dp[0][i + offset] = -1; //初始化,所有dp[0][i]为-1。
        dp[0][0 + offset]=0; //dp[0][0]初始化为0
        for(int i=1;i<=cnt;i++){ //遍历每个柑橘
            for(int j=-2000;j<=2000;j++){//遍历每种可能的重量差
                int tmp1=-1,tmp2=-1; //分别记录当前柑橘放在第一堆或第二堆时转移得来的新值,若无法转移则为-1
                if(j+weight[i]<=2000&&dp[i-1][j+weight[i]+offset]!=-1){ //当状态可以由放在第一堆转移而来时
                    tmp1=dp[i-1][j+weight[i]+offset]+weight[i]; //记录转移值
                }
                if(j-weight[i]>=-2000&&dp[i-1][j-weight[i]+offset]!=-1){ //当状态可以由放在第二堆转移而来时
                    tmp2 = dp[i-1][j-weight[i]+offset]+weight[i]; //记录该转移值
                }
                if(tmp1<tmp2){
                    tmp1=tmp2;
                } //取两者中较大的那个,保存至tmp1
                if(tmp1<dp[i-1][j+offset]){ //将tmp1与当前柑橘不放入任何堆即状态差不发生改变的原状态值比较，取较大的值保存至tmp1
                    tmp1=dp[i-1][j+offset];
                }
                dp[i][j +offset]=tmp1; //当前值状态保存为三个转移来源转移得到的新值中最大的那个
            }
        }
        cout<<"Case "<<i+1<<": ";//按题目输出要求输出
        if (dp[n][0+offset]==0){//dp[n][0]为0
            if(flag==true) cout<<'0'<<endl; //如果输入的柑橘中有重量为0的，那么输出就是0
            else cout<<"-1"<<endl; //如果输入的柑橘中没有重量为0的，那么输出就是-1，说明没有使得左右担的重量相等的柑橘去匹配
        }
        else cout<<dp[n][0+offset]/2<<endl; //否则输出dp[n][0]/2
    }
    return 0;
}
