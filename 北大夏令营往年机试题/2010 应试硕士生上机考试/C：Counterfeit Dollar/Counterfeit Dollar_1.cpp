//暴力枚举 orz...，将12枚硬币假币情况枚举出来比对
#include<iostream>
#include<cstring>
using namespace std;
int a[24][12]={
    0,0,0,0,0,0,0,0,0,0,0,1,
    0,0,0,0,0,0,0,0,0,0,1,0,
    0,0,0,0,0,0,0,0,0,1,0,0,
    0,0,0,0,0,0,0,0,1,0,0,0,
    0,0,0,0,0,0,0,1,0,0,0,0,
    0,0,0,0,0,0,1,0,0,0,0,0,
    0,0,0,0,0,1,0,0,0,0,0,0,
    0,0,0,0,1,0,0,0,0,0,0,0,
    0,0,0,1,0,0,0,0,0,0,0,0,
    0,0,1,0,0,0,0,0,0,0,0,0,
    0,1,0,0,0,0,0,0,0,0,0,0,
    1,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,-1,
    0,0,0,0,0,0,0,0,0,0,-1,0,
    0,0,0,0,0,0,0,0,0,-1,0,0,
    0,0,0,0,0,0,0,0,-1,0,0,0,
    0,0,0,0,0,0,0,-1,0,0,0,0,
    0,0,0,0,0,0,-1,0,0,0,0,0,
    0,0,0,0,0,-1,0,0,0,0,0,0,
    0,0,0,0,-1,0,0,0,0,0,0,0,
    0,0,0,-1,0,0,0,0,0,0,0,0,
    0,0,-1,0,0,0,0,0,0,0,0,0,
    0,-1,0,0,0,0,0,0,0,0,0,0,
    -1,0,0,0,0,0,0,0,0,0,0,0
};
char str1[10];
char str2[10];
char str3[5];
char str4[10];
char str5[10];
char str6[5];
char str7[10];
char str8[10];
char str9[5];
int num;
int main(){
    cin>>num;
    for(int i=0;i<num;i++){
        cin>>str1>>str2>>str3>>str4>>str5>>str6>>str7>>str8>>str9;
        for(int i=0;i<24;i++){
            int ans,ans1;
            if(strcmp(str3,"even")==0){
                ans=0;
                ans1=0;
                for(int t=0;t<strlen(str1);t++) ans+=a[i][str1[t]-'A'];
                for(int t=0;t<strlen(str2);t++) ans1+=a[i][str2[t]-'A'];
                if(ans!=ans1) continue;
            }
            else if(strcmp(str3,"up")==0){
                ans=0;
                ans1=0;
                for(int t=0;t<strlen(str1);t++) ans+=a[i][str1[t]-'A'];
                for(int t=0;t<strlen(str2);t++) ans1+=a[i][str2[t]-'A'];
                if(ans<=ans1) continue;
            }
            else if(strcmp(str3,"down")==0){
                ans=0;
                ans1=0;
                for(int t=0;t<strlen(str1);t++) ans+=a[i][str1[t]-'A'];
                for(int t=0;t<strlen(str2);t++) ans1+=a[i][str2[t]-'A'];
                if(ans>=ans1) continue;
            }
            if(strcmp(str6,"even")==0){
                ans=0;
                ans1=0;
                for(int t=0;t<strlen(str4);t++) ans+=a[i][str4[t]-'A'];
                for(int t=0;t<strlen(str5);t++) ans1+=a[i][str5[t]-'A'];
                if(ans!=ans1) continue;
            }
            else if(strcmp(str6,"up")==0){
                ans=0;
                ans1=0;
                for(int t=0;t<strlen(str4);t++) ans+=a[i][str4[t]-'A'];
                for(int t=0;t<strlen(str5);t++) ans1+=a[i][str5[t]-'A'];
                if(ans<=ans1) continue;
            }
            else if(strcmp(str6,"down")==0){
                ans=0;
                ans1=0;
                for(int t=0;t<strlen(str4);t++) ans+=a[i][str4[t]-'A'];
                for(int t=0;t<strlen(str5);t++) ans1+=a[i][str5[t]-'A'];
                if(ans>=ans1) continue;
            }
            if(strcmp(str9,"even")==0){
                ans=0;
                ans1=0;
                for(int t=0;t<strlen(str7);t++) ans+=a[i][str7[t]-'A'];
                for(int t=0;t<strlen(str8);t++) ans1+=a[i][str8[t]-'A'];
                if(ans!=ans1) continue;
            }
            else if(strcmp(str9,"up")==0){
                ans=0;
                ans1=0;
                for(int t=0;t<strlen(str7);t++) ans+=a[i][str7[t]-'A'];
                for(int t=0;t<strlen(str8);t++) ans1+=a[i][str8[t]-'A'];
                if(ans<=ans1) continue;
            }
            else if(strcmp(str9,"down")==0){
                ans=0;
                ans1=0;
                for(int t=0;t<strlen(str7);t++) ans+=a[i][str7[t]-'A'];
                for(int t=0;t<strlen(str8);t++) ans1+=a[i][str8[t]-'A'];
                if(ans>=ans1) continue;
            }
            for(int k=0;k<12;k++){
                if(a[i][k]==-1){
                    cout<<char(k+'A')<<" is the counterfeit coin and it is light."<<endl;
                    break;
                }
                if(a[i][k]==1){
                    cout<<char(k+'A')<<" is the counterfeit coin and it is heavy."<<endl;
                    break;
                }
            }
            break;
        }
    }
    return 0;
}
