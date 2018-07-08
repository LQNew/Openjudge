//本道题是我第一次采用了位运算，一定要熟悉这个操作！！
#include<iostream>
#include<cstring>
using namespace std;
const int standard=0x0000ffff;
int x,y,a;
int n;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d%d",&x,&y);
        int cnt=0;
        for(int i=0;i<16;i++){
            a=((x>>(16-i))|(x<<i))&(standard); //循环移位的运算：右移16-i位，左移i位，彼此做或运算，之后再截取低16位
            if(a==y){
                printf("YES\n");
                break;
            }
            else cnt++;
        }
        if(cnt==16) printf("NO\n");
    }
    return 0;
}
