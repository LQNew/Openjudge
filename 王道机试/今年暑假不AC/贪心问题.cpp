//给出一系列节目播放时间，找出能完整观看的最大节目数
//贪心问题，每次都找出当前结束时间最早的节目~依次遍历
#include <stdio.h>
#include <algorithm>
using namespace std;
struct program { //电视节目结构体
 int startTime; //节目开始时间
 int endTime; //节目结束时间
 bool operator < (const program & A) const { //重载小于号,保证sort函数能够按照结束时间升序排列
   return endTime < A.endTime;
 }
}buf[100];
int main () {
 int n;
 while (scanf ("%d",&n) != EOF) {
   if (n == 0) break;
   for (int i = 0;i < n;i ++) {
     scanf ("%d%d",&buf[i].startTime,&buf[i].endTime);
   } //输入
   sort(buf,buf + n); //按照结束时间升序排列
   int currentTime = 0 , ans = 0; //记录当前时间变量初始值为0,答案计数初始值为0
   for (int i = 0;i < n;i ++) { //按照结束时间升序便利所有的节目
     if (currentTime <= buf[i].startTime) { //若当前时间小于等于该节目开始时间,那么收看该在剩余节目里结束时间最早的节目
       currentTime = buf[i].endTime; //当前时间变为该节目结束时间
       ans ++; //又收看了一个节目
     }
   }
   printf("%d\n",ans); //输出
 }
 return 0;
}
