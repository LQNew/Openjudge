//题目难度不大，但是关于 cin和 gets()函数混用时，要注意 添加一个getchar()用于去除缓冲字符~
#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
int n;
char str2[101];
struct Node{
    char str1[101];
    int length;
};
Node node[1000];

int compare(const void* a, const void* b){
    Node* p1;
    Node* p2;
    p1=(Node*)a;
    p2=(Node*)b;
    return (*p1).length-(*p2).length;
}
int main(){
    while(cin>>n){
        getchar();//去除缓冲的字符
        int i;
        for(i=0;i<n;i++){
            gets(str2);
            if(strcmp(str2,"stop")==0) break;
            memcpy(node[i].str1,str2,sizeof(str2));
            node[i].length=strlen(str2);
        }
        qsort(node,i,sizeof(Node),compare);
        for(int j=0;j<i;j++) cout<<node[j].str1<<endl;
    }
    return 0;
}
