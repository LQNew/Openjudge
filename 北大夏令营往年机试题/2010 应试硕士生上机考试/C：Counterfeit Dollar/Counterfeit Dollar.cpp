//逻辑推导，但是答案有误..
#include<iostream>
#include<cstring>
using namespace std;
int judge[12];
char str1[10];
char str2[10];
char str3[5];
int num;
int main(){
    cin>>num;
    for(int i=0;i<num;i++){
        memset(judge,-1,sizeof(judge));
        for(int j=0;j<3;j++){
            cin>>str1>>str2>>str3;
            if(strcmp(str3,"up")==0){
                for(int i=0;i<strlen(str1);i++){
                    if(judge[str1[i]-'A']==0) continue;
                    judge[str1[i]-'A']=1;//1代表重
                }
                for(int i=0;i<strlen(str2);i++){
                    if(judge[str2[i]-'A']==0) continue;
                    judge[str2[i]-'A']=2;//2代表轻
                }
            }
            else if(strcmp(str3,"even")==0){
                for(int i=0;i<strlen(str2);i++) judge[str2[i]-'A']=0;
                for(int i=0;i<strlen(str1);i++) judge[str1[i]-'A']=0;
            }
            else{
                for(int i=0;i<strlen(str1);i++){
                    if(judge[str1[i]-'A']==0) continue;
                    judge[str1[i]-'A']=2;//2代表轻
                }
                for(int i=0;i<strlen(str2);i++){
                    if(judge[str2[i]-'A']==0) continue;
                    judge[str2[i]-'A']=1; //1代表重
                }
            }
        }
        for(int i=0;i<12;i++){
            if(judge[i]==1){
                cout<<char(i+'A')<<" is the counterfeit coin and it is heavy."<<endl;
                break;
            }
            else if(judge[i]==2){
                cout<<char(i+'A')<<" is the counterfeit coin and it is light."<<endl;
                break;
            }
        }
    }
    return 0;
}
