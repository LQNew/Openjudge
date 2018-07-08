//Ë®Ìâ
#include<iostream>
#include<string>
using namespace std;
int N;
int b[8]={128,64,32,16,8,4,2,1};
int a1[8],a2[8],a3[8],a4[8];
string str1;
int main(){
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>str1;
        for(int i=0;i<4;i++){
            int j=i*8;
            string a=str1.substr(j,8); //½ØÈ¡×Ö·û´®Æ¬¶Î
            int ans=0;
            for(int i=0;i<8;i++) ans+=b[i]*int(a[i]-'0');
            if(i==3) cout<<ans<<endl;
            else cout<<ans<<'.';
        }
    }
    return 0;
}
