/*
    描述
        一个数如果从左往右读和从右往左读数字是相同的，则称这个数是回文数，如121，1221，15651都是回文数。
        给定位数n，找出所有既是回文数又是素数的n位十进制数。（注：不考虑超过整型数范围的情况）。
    输入
        位数n,其中1<=n<=9。
    输出
        第一行输出满足条件的素数个数。第二行按照从小到大的顺序输出所有满足条件的素数，两个数之间用一个空格区分。
*/
//回文素数，题目难度不大，就是繁杂！！关于回文素数求解，可以先构造回文数，同时添加约束，比如除2以外，以偶数结尾的数均不为素数以及除5以外，以5结尾的数均不为素数
//同时还有个发现就是对于除了11外的偶数回文数均不是素数，这些约束条件的添加，将会有效地减少素数需要判别的数字数目。不过本道题仍然是属于个人调试臆测可以，具体有没有超时仍需要线上测试！
//本道题有个坑点就是求次方时，一开始直接调用了cmath库的pow()函数，后来发现该函数会有四舍五入的情况出现，于是自己手写了一个求次方的函数，所以pow()函数还是尽量不要用，比较坑！！
//本道题一开始数组开小了，之后发生了溢出，对于n=9时的回文数，它的数目大于1w，至于会不会TL也是仍需要考虑的！
#include<iostream>
using namespace std;
int n;
int decomposition[10];
int num[100000];
int final_num[100000];
int power(int j){
    int a=1;
    while(j>0){
        a*=10;
        j--;
    }
    return a;
}
void judge(int cnt){ //判别是否为素数
    int cnt_1=0;
    int j;
    for(int i=0;i<cnt;i++){
        j=2;
        for(j;j<=sqrt(num[i]);j++){
            if(num[i]%j==0) break;
        }
        if(j>sqrt(num[i])){
            final_num[cnt_1]=num[i];
            cnt_1++;
        }
    }
    cout<<cnt_1<<endl;
    for(int k=0;k<cnt_1-1;k++)
        cout<<final_num[k]<<" ";
    cout<<final_num[cnt_1-1]<<endl;
}
int main(){
    cin>>n;
    int cnt;
    if(n==1){
        cout<<4<<endl;
        cout<<"2 3 5 7"<<endl;
    }
    else if(n==2){ //构造回文数
        cnt=0;
        for(int i=1;i<10;i+=2){
            if(i==5) continue;
            decomposition[1]=decomposition[n]=i;
            if((decomposition[1]+decomposition[n])%3==0) continue;
            else{
                num[cnt]=0;
                for(int j=n;j>0;j--){
                    num[cnt]+=decomposition[j]*power(j-1);
                }
                cnt++;
            }
        }
        judge(cnt);
    }
    else if(n%2==0){
        cout<<0<<endl;
        cout<<endl;
    }
    else if(n==3){
        cnt=0;
        for(int i=1;i<10;i+=2){
            if(i==5) continue;
            decomposition[1]=decomposition[n]=i;
            for(int z=0;z<10;z++){
                decomposition[2]=z;
                if((decomposition[1]+decomposition[2]+decomposition[n])%3==0) continue;
                else{
                    int a=0;
                    for(int j=1;j<=n;j++){
                        a+=decomposition[j]*power(j-1);
                    }
                    num[cnt++]=a;
                }
            }
        }
        judge(cnt);
    }
    else if(n==5){
        cnt=0;
        for(int i=1;i<10;i+=2){
            if(i==5) continue;
            decomposition[1]=decomposition[n]=i;
            for(int z=0;z<10;z++){
                decomposition[2]=decomposition[4]=z;
                for(int t=0;t<10;t++){
                    decomposition[3]=t;
                    if((decomposition[1]+decomposition[2]+decomposition[3]+decomposition[4]+decomposition[n])%3==0) continue;
                    else{
                        for(int j=n;j>0;j--) num[cnt]+=decomposition[j]*power(j-1);
                            cnt++;
                    }
                }
            }
        }
        judge(cnt);
    }
    else if(n==7){
        cnt=0;
        for(int i=1;i<10;i+=2){
            if(i==5) continue;
            decomposition[1]=decomposition[n]=i;
            for(int z=0;z<10;z++){
                decomposition[2]=decomposition[6]=z;
                for(int t=0;t<10;t++){
                    decomposition[3]=decomposition[5]=t;
                    for(int x=0;x<10;x++){
                        decomposition[4]=x;
                        if((decomposition[1]+decomposition[2]+decomposition[3]+decomposition[4]+decomposition[5]+decomposition[6]+decomposition[n])%3==0) continue;
                        else{
                            for(int j=n;j>0;j--) num[cnt]+=decomposition[j]*power(j-1);
                            cnt++;
                        }
                    }
                }
            }
        }
        judge(cnt);
    }
    else if(n==9){
        cnt=0;
        for(int i=1;i<10;i+=2){
            if(i==5) continue;
            decomposition[1]=decomposition[n]=i;
            for(int z=0;z<10;z++){
                decomposition[2]=decomposition[8]=z;
                for(int t=0;t<10;t++){
                    decomposition[3]=decomposition[7]=t;
                    for(int x=0;x<10;x++){
                        decomposition[4]=decomposition[6]=x;
                        for(int y=0;y<10;y++){
                            decomposition[5]=y;
                            if((decomposition[1]+decomposition[2]+decomposition[3]+decomposition[4]+decomposition[5]+decomposition[6]+decomposition[7]+decomposition[8]+decomposition[n])%3==0) continue;
                            else{
                                for(int j=n;j>0;j--) num[cnt]+=decomposition[j]*power(j-1);
                                cnt++;
                            }
                        }
                    }
                }
            }
        }
        judge(cnt);
    }
    return 0;
}
