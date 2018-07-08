/*
    输入一系列整数，建立二叉排序数，并进行前序，中序，后序遍历。
*/
//分析，关于遍历的书写已径很熟悉了，非常模板的题型，但是二叉排序树的建立，与之前的二叉树遍历题颇为不一样，也是需要注意的！
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
void postOrder(Node*T){ //后序遍历树的常规方程，一定要牢记！
    if(T->lchild!=NULL){ //递归遍历左子树
        postOrder(T->lchild);
    }
    if(T->rchild!=NULL){ //递归遍历右子树
        postOrder(T->rchild);
    }
    cout<<T->data<<' ';
}
void inOrder(Node*T){ //中序遍历树的常规方程，一定要牢记！
    if(T->lchild!=NULL){ //递归遍历左子树
        inOrder(T->lchild);
    }
    cout<<T->data<<' ';
    if(T->rchild!=NULL){ //递归遍历右子树
        inOrder(T->rchild);
    }
}
void preOrder(Node*T){ //前序遍历树的常规方程，一定要牢记！
    cout<<T->data<<' ';
    if(T->lchild!=NULL){ //递归遍历左子树
        preOrder(T->lchild);
    }
    if(T->rchild!=NULL){ //递归遍历右子树
        preOrder(T->rchild);
    }
}
Node*insert_1(Node*T,int x){ //二叉树的建立，记录了节点以及权值，构树的方式很套路，一定要熟悉！
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
int main(){
    while(cin>>n){
        Node*T=NULL;
        for(int i=0;i<n;i++)
            cin>>num[i];
        for(int i=0;i<n;i++) //构造树
            T=insert_1(T,num[i]);
        loc=0;
        preOrder(T);
        cout<<endl;
        inOrder(T);
        cout<<endl;
        postOrder(T);
        cout<<endl;
    }
    return 0;
}
