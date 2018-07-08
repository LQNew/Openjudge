/*
    例如如下的先序遍历字符串： ABC##DE#G##F### 其中“#”表示的是空格，空格字符代表空树。建立起此二叉树以后，再对二叉树进行中序遍历，输出遍历结果。
*/
//分析，这是典型的二叉树遍历问题，难度不是很大，但是要熟知流程、套路！程序需要多加阅读、巩固！！同时要理解题目意思~
#include<iostream>
#include<cstring>
using  namespace std;
int s1,e1;
char str1[100];
struct Node{
    Node*lchild;//左孩子
    Node*rchild;//右孩子
    char c;//字符
};
Node node[100];
int loc;
Node*creat(){
    node[loc].lchild=node[loc].rchild=NULL;
    return &node[loc++];
}
void inOrder(Node*T){ //中序遍历树的常规方程，一定要牢记！
    if(T->lchild!=NULL){ //递归遍历左子树
        inOrder(T->lchild);
    }
    cout<<T->c<<' ';
    if(T->rchild!=NULL){ //递归遍历右子树
        inOrder(T->rchild);
    }
}
Node*build(){ //按照根、左、右的遍历方式遍历得到，关于递归的书写，比较不易领会，一定要多阅读程序，理解其中原理！！

    if((s1<=e1&&str1[s1]=='#')||s1>e1){
        s1++;
        return NULL;
    }
    Node*ret=creat();
    ret->c=str1[s1];
    s1++;
    ret->lchild=build();
    ret->rchild=build();
    return ret;
}
int main(){
    while(cin>>str1){
        loc=0;
        s1=0;
        e1=strlen(str1);
        Node*T=build();
        inOrder(T);
        cout<<endl;
    }
    return 0;
}
