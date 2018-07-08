/*
    给定一棵二叉树的前序遍历和中序遍历的结果，求其后序遍历。
*/
//二叉树的遍历一般存有一定的套路，这种重建二叉树难点在于建树该如何建，是一道比较经典的题目，要细细研读！！
#include<iostream>
#include<cstring>
using namespace std;
struct Node{
    Node*lchild;
    Node*rchild;
    char c;
};
Node node[50];
int loc;
char str1[30],str2[30];

Node*creat(){ //新建结点
    node[loc].lchild=node[loc].rchild=NULL; //初始化结点的左右儿子为空
    return &node[loc++]; //返回指针
}

void postOrder(Node*T){ //后序遍历的查找
    if(T->lchild!=NULL) postOrder(T->lchild);
    if(T->rchild!=NULL) postOrder(T->rchild);
    cout<<T->c;
}

Node*build(int s1,int e1,int s2,int e2){
    Node*ret=creat();
    ret->c=str1[s1];
    int root;
    for(int i=s2;i<=e2;i++){
        if(str2[i]==str1[s1]){
            root=i;
            break;
        }
    }
    //如果左边树没有建完
    if(root!=s2) ret->lchild=build(s1+1,s1+root-s2,s2,root-1); //s1+1~s1+root-s2为前序遍历的左子树半边;s2为中序遍历的起点,root-1为树的左半边
    //如果右边树没有有建完
    if(root!=e2) ret->rchild=build(s1+root-s2+1,e1,root+1,e2);
    return ret;
}

int main(){
    while(cin>>str1){
        if(strcmp(str1,"EOF")==0) break; //strcmp()用于字符串的比对，如果比对成功返回0
        cin>>str2;
        loc=0;
        int L1=strlen(str1);
        int L2=strlen(str2);
        Node*T=build(0,L1-1,0,L2-1);
        postOrder(T);
        cout<<endl;
    }
    return 0;
}
