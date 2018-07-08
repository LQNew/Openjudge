//Éú³É±í
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int n;
int a[10];
int b[10];
int num;
int end1;
int ans1=4;
int main(){
    int cnt=1;
    cout<<2<<','<<3<<','<<5<<','<<7<<',';
    while(cnt<1000000000){
        if(cnt<10){
            if(cnt%2==0||cnt%3==0||cnt%5==0||cnt%7==0||cnt==1){
                cnt++;
                continue;
            }
            num=cnt;
            int mark=0;
            end1=1;
            while(num!=0){
                a[mark++]=num%10;
                num/=10;
            }
            int ans=0;
            for(int i=0;i<end1;i++) ans+=a[i];
            if(ans%3==0){
                cnt++;
                continue;
            }
            memcpy(b,a,sizeof(a));
            reverse(&b[0],&b[end1]);
            int i;
            for(i=0;i<end1;i++){
                if(b[i]!=a[i]) break;
            }
            bool flag=false;
            if(i==end1){
                flag=true;
                for(int i=2;i<=sqrt(cnt);i++){
                    if(cnt%i==0){
                        flag=false;
                        break;
                    }
                }
            }
            if(flag){
                ans1++;
                cout<<cnt<<',';
            }
            cnt++;
        }
        else if(cnt<100){
            if(cnt%2==0||cnt%3==0||cnt%5==0||cnt%7==0){
                cnt++;
                continue;
            }
            num=cnt;
            int mark=0;
            end1=2;
            while(num!=0){
                a[mark++]=num%10;
                num/=10;
            }
            int ans=0;
            for(int i=0;i<end1;i++) ans+=a[i];
            if(ans%3==0){
                cnt++;
                continue;
            }
            memcpy(b,a,sizeof(a));
            reverse(&b[0],&b[end1]);
            int i;
            for(i=0;i<end1;i++){
                if(b[i]!=a[i]) break;
            }
            bool flag=false;
            if(i==end1){
                flag=true;
                for(int i=2;i<=sqrt(cnt);i++){
                    if(cnt%i==0){
                        flag=false;
                        break;
                    }
                }
            }
            if(flag){
                ans1++;
                cout<<cnt<<',';
            }
            cnt++;
        }
        else if(cnt<1000){
            if(cnt%2==0||cnt%3==0||cnt%5==0||cnt%7==0){
                cnt++;
                continue;
            }
            num=cnt;
            int mark=0;
            end1=3;
            while(num!=0){
                a[mark++]=num%10;
                num/=10;
            }
            int ans=0;
            for(int i=0;i<end1;i++) ans+=a[i];
            if(ans%3==0){
                cnt++;
                continue;
            }
            memcpy(b,a,sizeof(a));
            reverse(&b[0],&b[end1]);
            int i;
            for(i=0;i<end1;i++){
                if(b[i]!=a[i]) break;
            }
            bool flag=false;
            if(i==end1){
                flag=true;
                for(int i=2;i<=sqrt(cnt);i++){
                    if(cnt%i==0){
                        flag=false;
                        break;
                    }
                }
            }
            if(flag){
                ans1++;
                cout<<cnt<<',';
            }
            cnt++;
        }
        else if(cnt<10000){
            if(cnt%2==0||cnt%3==0||cnt%5==0||cnt%7==0){
                cnt++;
                continue;
            }
            num=cnt;
            int mark=0;
            end1=4;
            while(num!=0){
                a[mark++]=num%10;
                num/=10;
            }
            int ans=0;
            for(int i=0;i<end1;i++) ans+=a[i];
            if(ans%3==0){
                cnt++;
                continue;
            }
            memcpy(b,a,sizeof(a));
            reverse(&b[0],&b[end1]);
            int i;
            for(i=0;i<end1;i++){
                if(b[i]!=a[i]) break;
            }
            bool flag=false;
            if(i==end1){
                flag=true;
                for(int i=2;i<=sqrt(cnt);i++){
                    if(cnt%i==0){
                        flag=false;
                        break;
                    }
                }
            }
            if(flag){
                ans1++;
                cout<<cnt<<',';
            }
            cnt++;
        }
        else if(cnt<100000){
            if(cnt%2==0||cnt%3==0||cnt%5==0||cnt%7==0){
                cnt++;
                continue;
            }
            num=cnt;
            int mark=0;
            end1=5;
            while(num!=0){
                a[mark++]=num%10;
                num/=10;
            }
            int ans=0;
            for(int i=0;i<end1;i++) ans+=a[i];
            if(ans%3==0){
                cnt++;
                continue;
            }
            memcpy(b,a,sizeof(a));
            reverse(&b[0],&b[end1]);
            int i;
            for(i=0;i<end1;i++){
                if(b[i]!=a[i]) break;
            }
            bool flag=false;
            if(i==end1){
                flag=true;
                for(int i=2;i<=sqrt(cnt);i++){
                    if(cnt%i==0){
                        flag=false;
                        break;
                    }
                }
            }
            if(flag){
                ans1++;
                cout<<cnt<<',';
            }
            cnt++;
        }
        else if(cnt<1000000){
            if(cnt%2==0||cnt%3==0||cnt%5==0||cnt%7==0){
                cnt++;
                continue;
            }
            num=cnt;
            int mark=0;
            end1=6;
            while(num!=0){
                a[mark++]=num%10;
                num/=10;
            }
            int ans=0;
            for(int i=0;i<end1;i++) ans+=a[i];
            if(ans%3==0){
                cnt++;
                continue;
            }
            memcpy(b,a,sizeof(a));
            reverse(&b[0],&b[end1]);
            int i;
            for(i=0;i<end1;i++){
                if(b[i]!=a[i]) break;
            }
            bool flag=false;
            if(i==end1){
                flag=true;
                for(int i=2;i<=sqrt(cnt);i++){
                    if(cnt%i==0){
                        flag=false;
                        break;
                    }
                }
            }
            if(flag){
                ans1++;
                cout<<cnt<<',';
            }
            cnt++;
        }
        else if(cnt<10000000){
            if(cnt%2==0||cnt%3==0||cnt%5==0||cnt%7==0){
                cnt++;
                continue;
            }
            num=cnt;
            int mark=0;
            end1=7;
            while(num!=0){
                a[mark++]=num%10;
                num/=10;
            }
            int ans=0;
            for(int i=0;i<end1;i++) ans+=a[i];
            if(ans%3==0){
                cnt++;
                continue;
            }
            memcpy(b,a,sizeof(a));
            reverse(&b[0],&b[end1]);
            int i;
            for(i=0;i<end1;i++){
                if(b[i]!=a[i]) break;
            }
            bool flag=false;
            if(i==end1){
                flag=true;
                for(int i=2;i<=sqrt(cnt);i++){
                    if(cnt%i==0){
                        flag=false;
                        break;
                    }
                }
            }
            if(flag){
                ans1++;
                cout<<cnt<<',';
            }
            cnt++;
        }
        else if(cnt<100000000){
            if(cnt%2==0||cnt%3==0||cnt%5==0||cnt%7==0){
                cnt++;
                continue;
            }
            num=cnt;
            int mark=0;
            end1=8;
            while(num!=0){
                a[mark++]=num%10;
                num/=10;
            }
            int ans=0;
            for(int i=0;i<end1;i++) ans+=a[i];
            if(ans%3==0){
                cnt++;
                continue;
            }
            memcpy(b,a,sizeof(a));
            reverse(&b[0],&b[end1]);
            int i;
            for(i=0;i<end1;i++){
                if(b[i]!=a[i]) break;
            }
            bool flag=false;
            if(i==end1){
                flag=true;
                for(int i=2;i<=sqrt(cnt);i++){
                    if(cnt%i==0){
                        flag=false;
                        break;
                    }
                }
            }
            if(flag){
                ans1++;
                cout<<cnt<<',';
            }
            cnt++;
        }
        else if(cnt<1000000000){
            if(cnt%2==0||cnt%3==0||cnt%5==0||cnt%7==0){
                cnt++;
                continue;
            }
            num=cnt;
            int mark=0;
            end1=9;
            while(num!=0){
                a[mark++]=num%10;
                num/=10;
            }
            int ans=0;
            for(int i=0;i<end1;i++) ans+=a[i];
            if(ans%3==0){
                cnt++;
                continue;
            }
            memcpy(b,a,sizeof(a));
            reverse(&b[0],&b[end1]);
            int i;
            for(i=0;i<end1;i++){
                if(b[i]!=a[i]) break;
            }
            bool flag=false;
            if(i==end1){
                flag=true;
                for(int i=2;i<=sqrt(cnt);i++){
                    if(cnt%i==0){
                        flag=false;
                        break;
                    }
                }
            }
            if(flag){
                ans1++;
                cout<<cnt<<',';
            }
            cnt++;
        }
        else if(cnt<10000000000){
            if(cnt%2==0||cnt%3==0||cnt%5==0||cnt%7==0){
                cnt++;
                continue;
            }
            num=cnt;
            int mark=0;
            end1=10;
            while(num!=0){
                a[mark++]=num%10;
                num/=10;
            }
            int ans=0;
            for(int i=0;i<end1;i++) ans+=a[i];
            if(ans%3==0){
                cnt++;
                continue;
            }
            memcpy(b,a,sizeof(a));
            reverse(&b[0],&b[end1]);
            int i;
            for(i=0;i<end1;i++){
                if(b[i]!=a[i]) break;
            }
            bool flag=false;
            if(i==end1){
                flag=true;
                for(int i=2;i<=sqrt(cnt);i++){
                    if(cnt%i==0){
                        flag=false;
                        break;
                    }
                }
            }
            if(flag){
                ans1++;
                cout<<cnt<<',';
            }
            cnt++;
        }
    }
    cout<<endl;
    cout<<ans1<<endl;
    return 0;
}
