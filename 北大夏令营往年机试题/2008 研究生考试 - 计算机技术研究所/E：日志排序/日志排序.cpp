#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
char str1[200];
char num[50];
struct Node{
    char str2[200];
    double value;
};
Node node[10001];
int compare(const void* a,const void* b){
    Node* p1;
    Node* p2;
    p1=(Node*)a;
    p2=(Node*)b;
    if(*)
    return (*p1).value-(*p2).value;
}
int main(){
    int cnt=0;
    while(1){
        gets(str1);
        if(strlen(str1)==0) break;
        int i;
        int j;
        int t=0;
        for(i=strlen(str1);i>=0;i--){
            if(str1[i]==')') break;
        }
        for(j=i-3;i>=0;j--){
            if(str1[j]!=' '){
                num[t]=str1[j];
                t++;
            }
            else break;
        }
        reverse(&num[0],&num[t]);
        double b=atof(num);
        memcpy(node[cnt].str2,str1,sizeof(str1));
        node[cnt].value=b;
        cnt++;
    }
    qsort(node,cnt,sizeof(Node),compare);
    for(int i=0;i<cnt;i++) cout<<node[i].str2<<endl;
    return 0;
}
