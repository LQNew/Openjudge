//水题，加个bool型数组去判别是否是一对一的关系，本道题其实我解得不大严谨，我是只解决了多对一的问题，但是并没有解决一对多的问题，不过本道题倒是不太卡这个
#include<iostream>
#include<cstring>
using namespace std;
char Decode[26];
bool Decode_1[26];
bool flag;
char str1[101],str2[101],wait_for_translate[101];
int main(){
    memset(Decode,'#',sizeof(Decode));
    memset(Decode_1,0,sizeof(Decode_1));
    flag=true;
    cin>>str1>>str2>>wait_for_translate;
    for(int i=0;i<strlen(str1);i++){
        if(Decode_1[str2[i]]==false){
            Decode_1[str2[i]]=true;
            Decode[str1[i]-'A']=str2[i];
        }
    }
    for(int i=0;i<26;i++){
        if(Decode[i]=='#'){
            flag=false;
            break;
        }
    }
    if(!flag) cout<<"Failed"<<endl;
    else{
        for(int i=0;i<strlen(wait_for_translate);i++){
            if(Decode[wait_for_translate[i]-'A']=='#') break;
            wait_for_translate[i]=Decode[wait_for_translate[i]-'A'];
        }
        cout<<wait_for_translate<<endl;
    }
    return 0;
}
