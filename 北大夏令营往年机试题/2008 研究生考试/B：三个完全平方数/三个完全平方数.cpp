//题目一般，不难
//361 529 784
#include<iostream>
using namespace std;
int MAX;
int a[20];
int b[10];
int compare(const void* a, const void* b){
    int* p1;
    int* p2;
    p1=(int*)a;
    p2=(int*)b;
    return *p1-*p2;
}
struct Node{
    int x;
    int y;
    int z;
};
Node node[100];
int main(){
    /*
    求出所有的三个完全平方数的组合
    int cnt=0;
    int t=0;
    for(int i=13;i<=31;i++) a[cnt++]=i*i;
    for(int i=0;i<=18;i++){
        for(int j=i+1;j<=18;j++){
            for(int k=j+1;k<=18;k++){
                int cnt1=0;
                b[1]=a[i]/100;
                b[2]=(a[i]%100)/10;
                b[3]=(a[i]%100)%10;
                b[4]=a[j]/100;
                b[5]=(a[j]%100)/10;
                b[6]=(a[j]%100)%10;
                b[7]=a[k]/100;
                b[8]=(a[k]%100)/10;
                b[9]=(a[k]%100)%10;
                qsort(&b[1],9,sizeof(b[0]),compare);
                for(int i=1;i<=9;i++){
                    if(b[i]==i) cnt1++;
                }
                if(cnt1==9){
                    node[t].x=a[i];
                    node[t].y=a[j];
                    node[t].z=a[k];
                    t++;
                }
            }
        }
    }
    for(int i=0;i<t;i++){
        cout<<node[i].x<<' '<<node[i].y<<' '<<node[i].z<<endl;
    }
    */
    cin>>MAX;
    if(MAX>784) cout<<361<<' '<<529<<' '<<784<<endl;
    else if(MAX>529) cout<<361<<' '<<529<<endl;
    else if(MAX>361) cout<<361<<endl;
    return 0;
}
