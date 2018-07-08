//逻辑分析题，蛮有意思的一道题
#include<iostream>
using namespace std;
int t;
char str1[3];
char str2[3];
int x0,y0,x1,y1;
int main(){
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>str1>>str2;
        x0=str1[0]-'a'+1;
        x1=str2[0]-'a'+1;
        y0=str1[1]-'0';
        y1=str2[1]-'0';
        //王的步数
        int min1=min(abs(x0-x1),abs(y0-y1));
        int step1=abs(x0-x1)+abs(y0-y1)-min1;
        //后的步数
        int step2;
        if(x0==x1&&y0==y1) step2=0;
        else if(abs(x0-x1)==abs(y0-y1)||x0==x1||y0==y1) step2=1;
        else step2=2;
        //车的步数
        int step3;
        if(x0==x1&&y0==y1) step3=0;
        else if(x0==x1||y0==y1) step3=1;
        else step3=2;
        //象的步数
        int step4;
        if((abs(x1-x0)+abs(y1-y0))%2) step4=-1;
        else{
            if(x0==x1&&y0==y1) step4=0;
            else if(abs(x1-x0)==abs(y1-y0)) step4=1;
            else step4=2;
        }
        cout<<step1<<' '<<step2<<' '<<step3<<' ';
        if(step4==-1) cout<<"Inf"<<endl;
        else cout<<step4<<endl;
    }
    return 0;
}
