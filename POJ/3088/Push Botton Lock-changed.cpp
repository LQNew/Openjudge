/*
    对于一个门锁，它有B个按钮，按照特定的组合、顺序按下按钮后即可开锁，要求按钮不可重复按下：如(1-2-3)(4)(7-8) 按照此顺序可以打开门锁，要求求出
    总的按钮排序种类、个数
*/
//两个递推公式应该记住！
//1.组合数 c[i][j]=c[i-1][j-1]+c[i-1][j], c[i][0]=c[i][i]=1
//2.第二类斯特林数 ：考虑第p个物品，p可以单独构成一个非空集合，此时前p-1个物品构成k-1个非空的不可辨别的集合，方法数为S(p-1,k-1)；也可以前p-1种物品构成k个非空的不可辨别的集合，第p个物品放入任意一个中，这样有k*S(p-1,k)种方法。
//  s[i][j]=s[i-1][j-1]+j*s[i-1][j],s[i][0]=0,s[i][i]=1 对于 n个不同的球投入m个不同的盒子中，盒子不可为空，因为盒子不同，所以此处s[i][j]*j! 表示种数
//  这也是八种球盒问题中的110问题：不同的球、不同的盒子、盒子不允许为空的问题
//分析本道题，可以知道我们可以任选B个按钮中 的i个用于设置，对于这i个又可以设置<=i个的box 去含括这些按钮，简单地来说就是一个n个不同的球投入m个不同的盒子的组合问题
//这时将每种情况考虑清楚后，将各个情况求得的个数相加之和便是最后的方案个数！
//本道题思路比较具有综合性，是一道好题！！

#include<iostream>
using namespace std;
int N;
int B;
long long s[12][12],c[12][12],a[12]; //第二类斯特林数，组合数，全排列数的计算
long long total;
int main(){
    c[0][0]=1;
    a[0]=1;
    for(int i=1; i<=11; i++){
        a[i]=a[i-1]*i;//计算得出全排列数
        c[i][0]=c[i][i]=1;//组合数的初始化
        for(int j=1; j<i; j++) c[i][j]=c[i-1][j-1]+c[i-1][j]; //递归求出组合数
    }
    for(int i=1;i<=11;i++) s[i][1]=c[N][i];
    for(int i=1;i<=11;i++){
        for(int j=2;j<=11;j++){
            for(int t=1;t<=i;t++) s[i][j]+=s[i-t][j-1]*c[N-i+t][t];
        }
    }
    while(cin>>N){
        for(int i=1;i<=N;i++){
            total=0;
            cin>>B;
            for(int i=1;i<=B;i++){
                for(int j=1;j<=i;j++){
                    total+=c[B][i]*s[i][j]*a[j]; //叠加每一个方案对应的个数
                }
            }
            cout<<i<<' '<<B<<' '<<total<<endl;
        }
        break;
    }
    return 0;
}
