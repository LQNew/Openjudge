/*
    球赛的规则如下：如果 A 打败了 B，B 又打败了 C，而 A 与 C 之间没有进行过比赛，那么就认定，A 一定能打败 C。
    如果 A 打败了 B，B 又打败了 C，而且，C 又打败了 A，那么 A、B、C 三者都不可能成为冠军。
    根据这个规则，无需循环较量，或许就能确定冠军。你的任务就是面对一群比赛选手，在经过了若干场撕杀之后，确定是否已经实际上产生了冠军。
*/
/*
    map的功能:
    1. 自动建立Key-value的对应。key 和 value可以是任意你需要的类型。
    2. 根据key值快速查找记录，查找的复杂度基本是Log(N)，如果有1000个记录，最多查找10次，1,000,000个记录，最多查找20次。
    3. 快速插入Key-Value 记录。
    4. 快速删除记录
    5. 根据Key 修改value记录。
    6. 遍历所有记录。
*/
//分析可知，这是一个拓扑排序衍生出的题，可以产生冠军的情况即为全图中入度为零的点唯一
//本题中比较恶心的地方是只给了字符串去替代人名，我们需要将人名和对应的数字匹配上，才方便进行数组操作
//采用了map将选手的姓名映射为结点的编号
#include<iostream>
#include<map>
#include<string>
using namespace std;
int n;
char str1[50],str2[50];
int mark[2000];
map<string,int> M;//完成一个string到int的映射，用map完成映射特别方便，同时也是高度优化，在遇到此种类型的题目，建议使用！
int main(){
    while(cin>>n){
        if(n==0) break;
        for(int i=0;i<2*n;i++){ //n对选手，最多有2n个不同的选手
            mark[i]=0;//初始化所有结点入度为0
        }
        M.clear(); //map中的映射关系清空
        int idx=0;
        for(int i=0;i<n;i++){
            cin>>str1>>str2;
            string a=str1;string b=str2;
            int idxa,idxb;
            if(M.find(a)==M.end()){ //检查a是否在map中已经有映射
                idxa=idx;
                M[a]=idx++;
            }
            else idxa=M[a];
            if(M.find(b)==M.end()){
                idxb=idx;
                M[b]=idx++;
            }
            else idxb=M[b];
            mark[idxb]++; //b对应的结点入度+1
        }
        int cnt=0;
        for(int i=0;i<idx;i++){ //检查整张图中所有入度为0的结点个数
            if(mark[i]==0) cnt++;
        }
        if(cnt==1) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}
