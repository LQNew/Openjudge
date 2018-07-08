/*
    现在给你N个关键字值各不相同的节点，要求你按顺序插入一个初始为空树的二叉排序树中，每次插入后成功后，求相应的父亲节点的关键字值，
    如果没有父亲节点，则输出-1。
*/
//关于二叉排序树的建立，刚刚已经提及，但是打印父亲节点，因为我们构树时采取的数据结构只是左孩子、右孩子形式，所以打印父亲节点，此处我采取了比较笨的方法，直接遍历树...
#include<iostream>
#include<cstring>
using  namespace std;
int num[101];
int n;
int flag;
struct Node{
    Node*lchild;//左孩子
    Node*rchild;//右孩子
    int data;//数字
};
Node node[100];
int loc;
Node*creat(){
    node[loc].lchild=node[loc].rchild=NULL;
    return &node[loc++];
}
Node*insert_1(Node*T,int x){ //插入构造二叉排序树
    if(T==NULL){
        T=creat();
        T->data=x;
        return T;
    }
    else if(x<T->data){
        T->lchild=insert_1(T->lchild,x);
    }
    else if(x>T->data){
        T->rchild=insert_1(T->rchild,x);
    }
    return T;
}
void print(int x,Node*T){ //遍历查找二叉树的父节点，并打印权值~
    if((T->lchild!=NULL&&T->lchild->data==x)||(T->rchild!=NULL&&T->rchild->data==x))
        cout<<T->data<<endl;
    if(T->lchild!=NULL&&x<T->lchild->data)
        print(x,T->lchild);
    else if(T->lchild!=NULL&&x>T->lchild->data&&x<T->data)
        print(x,T->lchild);
    else if(T->rchild!=NULL&&x<T->rchild->data&&x>T->data)
        print(x,T->rchild);
    else if(T->rchild!=NULL&&x>T->rchild->data)
        print(x,T->rchild);
}
int main(){
    while(cin>>n){
        Node*T=NULL;
        for(int i=0;i<n;i++)
            cin>>num[i];
        loc=0;
        for(int i=0;i<n;i++)
            T=insert_1(T,num[i]);
        cout<<-1<<endl;
        for(int i=1;i<n;i++)
            print(num[i],T);
    }
    return 0;
}
