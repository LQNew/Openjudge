#include <stdio.h>
#include <algorithm>
using namespace std;
struct goods { //表示可买物品的结构体
 double j;  //该物品总重
 double f;  //该物品总价值
 double s;  //该物品性价比
 bool operator <(const goods &A) const { //重载小于运算符,确保可用sort函数将数组按照性价比降序排列
   return s > A.s;
 }
}buf[1000];
int main () {
 double m;
 int n;
 while (scanf ("%lf%d",&m,&n) != EOF) {
   if (m == -1 && n == -1) break; //当n == -1且m == -1时跳出循环,程序运行结束
   for (int i = 0;i < n;i ++) {
     scanf ("%lf%lf",&buf[i].j,&buf[i].f); //输入
     buf[i].s = buf[i].j / buf[i].f; //计算性价比
   }
   sort(buf,buf + n); //使各物品按照性价比降序排列
   int idx = 0; //当前货物下标
   double ans = 0; //累加所能得到的总重量
   while (m > 0 && idx < n) { //循环条件为,既有物品剩余(idx < n)还有钱剩余(m > 0)时继续循环
     if (m > buf[idx].f) {
       ans += buf[idx].j;
       m -= buf[idx].f;
     } //若能买下全部该物品
     else {
       ans += buf[idx].j * m / buf[idx].f;
       m = 0;
     } //若只能买下部分该物品
     idx ++; //继续下一个物品
   }
   printf("%.3lf\n",ans); //输出
 }
 return 0;
}
