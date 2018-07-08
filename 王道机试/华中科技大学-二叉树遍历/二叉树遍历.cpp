/*
    两个字符串，其长度n均小于等于26。第一行为前序遍历，第二行为中序遍历。二叉树中的结点名称以大写字母表示：A，B，C....最多26个结点。
    输出一行，为后序遍历的字符串。
*/
//分析，这是典型的二叉树遍历问题，难度不是很大，但是要熟知流程、套路！程序需要多加阅读、巩固！！
#include<iostream>
#include<cstring>
using  namespace std;
char str1[30],str2[30];
struct Node{
    Node*lchild;//左孩子
    Node*rchild;//右孩子
    char c;//字符
};
Node node[50];
int loc;
Node*creat(){
    node[loc].lchild=node[loc].rchild=NULL;
    return &node[loc];
}
void postOrder(Node*T){ //后序遍历树的常规方程，一定要牢记！
    if(T->lchild!=NULL){ //递归遍历左子树
        postOrder(T->lchild);
    }
    if(T->rchild!=NULL){ //递归遍历右子树
        postOrder(T->rchild);
    }
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
    //如果左边树没有建完r
    if(root!=s2) ret->lchild=build(s1+1,s1+root-s2,s2,root-1); //s1+1~s1+root-s2为前序遍历的左子树半边;s2为中序遍历的起点,root-1为树的左半边
    //如果右边树没有建完
    if(root!=e2) ret->rchild=build(s1+root-s2+1,e1,root+1,e2);
    return ret;
}
int main(){
    while(cin>>str1>>str2){
        loc=0;
        int L1=strlen(str1);
        int L2=strlen(str2);
        Node*T=build(0,L1-1,0,L2-1);
        postOrder(T);
        cout<<endl;
    }
    return 0;
}
