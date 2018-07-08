//水题，主要是细节的处理~
#include<iostream>
#include<cstring>
using namespace std;
int computer_letters[26];
char str1[80];
int main(){
    memset(computer_letters,0,sizeof(computer_letters));
    for(int i=0;i<4;i++){
        gets(str1);
        for(int i=0;i<strlen(str1);i++){
            if(str1[i]>='A'&&str1[i]<='Z') computer_letters[str1[i]-'A']++;
        }
    }
    int max1=0;
    for(int i=0;i<26;i++) max1=max(max1,computer_letters[i]);
    for(int i=max1;i>0;i--){
        for(int j=0;j<26;j++){
            if(computer_letters[j]==i){
                cout<<"* ";
                computer_letters[j]--;
            }
            else cout<<"  ";
        }
        cout<<endl;
    }
    for(int i=0;i<26;i++) cout<<char('A'+i)<<' ';
    //cout<<endl;
    return 0;
}
