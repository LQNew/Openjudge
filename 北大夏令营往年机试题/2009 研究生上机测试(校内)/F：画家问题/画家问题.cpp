//标准题型，就是熄灯问题，可以视作一类题型，从第一行开始一次向后遍历查询直至最后一行，如果最后一行满足条件，那么返回结果！！
//算是比较难的枚举问题，也要多加思考记忆此类题型，此类题型形式很固定，有固定的题解~
#include<iostream>
#include<cstring>
using namespace std;
const int INF=0x7fffffff;
bool map1[17][17];
int a[16];
int b[16];
bool press[16][16];
bool map_copy[17][17];
char symbol;
int ans;
int n;
void decomposition(int x){ //将一个十进制数分解至n位的二进制数
    for(int i=1;i<=n;i++){
        a[i]=x%2;
        x=x/2;
    }
}

void press_1(int i){ //遍历每一行会被按下的情况，然后更改相邻的状态
    for(int j=1;j<=n;j++){
        if(press[i][j]){
            map_copy[i][j]=!map_copy[i][j];
            map_copy[i-1][j]=!map_copy[i-1][j];
            map_copy[i+1][j]=!map_copy[i+1][j];
            map_copy[i][j-1]=!map_copy[i][j-1];
            map_copy[i][j+1]=!map_copy[i][j+1];
        }
    }
}

void decide(int i){ //遍历上一行的状态，找到非黄色的砖块，在其对应的下一行同列 决定是否绘制该砖块
    for(int j=1;j<=n;j++){
        if(!map_copy[i][j]){
            press[i+1][j]=true;
            ans++;
        }
    }
}

int main(){
    int b1=1;
    for(int i=1;i<=15;i++){ //生成2^1~2^15的所有2的次方数
        b1*=2;
        b[i]=b1;
    }
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>symbol;
            if(symbol=='w') map1[i][j]=0; //对输入进行一个预处理，将白色砖块视为0，黄色砖块视为1，利于后序代码的编写
            else map1[i][j]=1;
        }
    }
    int min1=INF;
    for(int i=0;i<b[n];i++){ //遍历每一个第一行的情况，并判别该情况是否成立~
        ans=0;
        memset(press,0,sizeof(press));
        memcpy(map_copy,map1,sizeof(map1)); //获取当前地图的副本
        decomposition(i);//生成第一行的各种情况
        for(int i=1;i<=n;i++){ //初始化第一行情况
            if(a[i]){
                press[1][i]=true;
                ans++;
            }
            else press[1][i]=false;
        }
        for(int i=1;i<n;i++){
            press_1(i);
            decide(i);
        }
        press_1(n);
        int cnt=0;
        for(int j=1;j<=n;j++){
            if(map_copy[n][j]) cnt++;
            else break;
        }
        if(cnt==n){ //如果最后一行检测全为黄色砖块，那么该次第一行的假设成立
            min1=min(ans,min1);
        }
    }
    if(min1==INF) cout<<"inf"<<endl;
    else cout<<min1<<endl;
    return 0;
}
