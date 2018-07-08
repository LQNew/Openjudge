//Ë®Ìâ
#include<iostream>
#include<cstring>
using namespace std;
bool lock[101];
int num;
int n;
int main(){
    cin>>num;
    for(int i=0;i<num;i++){
        cin>>n;
        memset(&lock[1],1,sizeof(lock[0])*n);
        for(int i=1;i<=n;i++){
            int j=i;
            while(j<=n){
                lock[j]=!lock[j];
                j+=i;
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            if(!lock[i]) ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}
