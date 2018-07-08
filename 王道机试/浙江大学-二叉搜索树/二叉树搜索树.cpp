/*
    开始一个数n，(1<=n<=20) 表示有n个需要判断，n= 0 的时候输入结束。
    接下去一行是一个序列，序列长度小于10，包含(0~9)的数字，没有重复数字，根据这个序列可以构造出一颗二叉搜索树。
    接下去的n行有n个序列，每个序列格式跟第一个序列一样，请判断这两个序列是否能组成同一颗二叉搜索树。
*/
//分析，首先需要清楚的是二叉搜索树指的是 二叉排序树，对于二叉树的遍历只要中序+任意一个序列遍历两个遍历结果都一致可以说明此二者树是一致相同的
//本道题难点在于如何存储状态，此处我采用数组存储，对于树形的建立，其节点每次都会清空，主要存储的是遍历后的结果，
//本道题用到了一些字符串比对函数，如strcmp()用于字符串的比对，strlen()用于计数字符串的长度，memset()用于字符串的初始化，memcpy()用于字符串的复制
//这些常用的函数一定要熟悉，否则机试时会大大耗费时间...
#include<iostream>
#include<cstring>
using  namespace std;
char num[20];
char str1[30],str2[30];
int n;
struct Node{
    Node*lchild;//左孩子
    Node*rchild;//右孩子
    char data;//数字
};
Node node[20];
int loc;
int loc_target;
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
    str1[loc_target++]=T->data; //存储字符值
    //cout<<T->data<<' ';
}
void inOrder(Node*T){ //中序遍历树的常规方程，一定要牢记！
    if(T->lchild!=NULL){ //递归遍历左子树
        inOrder(T->lchild);
    }
    str1[loc_target++]=T->data;
    //cout<<T->data<<' ';
    if(T->rchild!=NULL){ //递归遍历右子树
        inOrder(T->rchild);
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
        memset(str2,0,sizeof(char)*20);
        if(n==0) break;
        cin>>num;
        Node*T=NULL;
        loc=0;
        for(int i=0;i<strlen(num);i++) //构造树
            T=insert_1(T,num[i]);
        loc_target=0;
        postOrder(T);
        inOrder(T);
        memcpy(str2,str1,sizeof(char)*2*strlen(num));//将获得的遍历结果复制到str2中，之后用str1再获取别的遍历结果并与str2比对
        str2[2*strlen(num)]='\0';//此处字符串的结尾加上结束符，很重要的一点！！
        for(int i=0;i<n;i++)
        {
            for(int i=0;i<15;i++)
                node[i].lchild=node[i].rchild=NULL;
            cin>>num;
            memset(str1,0,sizeof(char)*2*strlen(num));
            Node*T=NULL;
            loc=0;
            for(int i=0;i<strlen(num);i++) //构造树
                T=insert_1(T,num[i]);
            loc_target=0;
            postOrder(T);
            inOrder(T);
            str1[2*strlen(num)]='\0';
            if(strcmp(str1,str2)==0)
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
        }
    }
    return 0;
}
