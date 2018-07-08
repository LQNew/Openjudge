/*
    二叉搜索树的构造，是典型套路题，要清楚题目该从哪个套路点出发去解~
*/
#include<iostream>
using namespace std;
struct Node{
    Node*lchild;
    Node*rchild;
    int data;
};
Node node[1000];
int num[1000];
int loc;

Node* creat(){
    node[loc].lchild=node[loc].rchild=NULL;
    return &node[loc++];//返回指向结构体的指针
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
    return T; //每次都返回到最开始的根节点
}

int main(){
    int i=0;
    loc=0;
    Node*T=NULL;
    while(cin>>num[i]) T=insert_1(T,num[i]);
    preOrder(T);
    cout<<endl;
    return 0;
}
