//二叉树的镜面映射同时之后还有宽搜，难度很大，本道题是结合网上的理解勉强写出来的程序...
//之后可以加强理解得去刷~
#include<iostream>
#include<stack>
#include<queue>
using namespace std;

struct Node{
    Node* lchild;
    Node* rchild;
    char c;
};
Node node[1000];
char tmp[1000][3];
int loc,cnt,mark;

Node* creat(){ //新建结点
    node[loc].lchild=node[loc].rchild=NULL; //初始化结点的左右儿子为空
    return &node[loc++]; //返回指针
}

Node* build(){//按照前序排序 构造出树
    //cout<<mark<<' '<<tmp[mark]<<endl;
    Node* ret=creat();
    ret->c=tmp[mark][0];
    mark++;
    if(tmp[mark-1][1]=='0'){ //如果非0收尾，说明是叶节点，那么不会有左右孩子
        ret->lchild=build();
        ret->rchild=build();
    }
    return ret;
}

void PreOrder(Node* T){
    cout<<T->c<<' ';
    if(T->lchild!=NULL) PreOrder(T->lchild);
    if(T->rchild!=NULL) PreOrder(T->rchild);
}

void Print(Node* p){ //输出该树的镜像翻转
    stack<Node*> s;
    queue<Node*> Q;
    while(p != NULL){   //此处是关键，根据“左孩子右兄弟”的特点，一直向右遍历，将树同一层的结点都放在栈内
        if(p->c!= '$') s.push(p);
        p = p->rchild;
    }
    while(!s.empty()){  //将栈内的结点依次弹出，压入队列，完成镜像翻转的功能
        Q.push(s.top());
        s.pop();
    }
    while(!Q.empty()){
        p = Q.front();
        Q.pop();
        cout<<p->c<<' ';
        if(p->lchild != NULL){
            p = p->lchild;
            while(p!= NULL){   //同理，上面是处理根节点的，因为那时队列还为空，这里是处理剩下的全部结点
                if(p->c!= '$') s.push(p);
                p = p->rchild;
            }
            while(!s.empty()){
                Q.push(s.top());
                s.pop();
            }
        }
    }
}

int main(){
    while(cin>>cnt){
        for(int i=0;i<cnt;i++) cin>>tmp[i];
        loc=0;
        mark=0;
        //cout<<tmp[7];
        Node*root=build();
        //PreOrder(root);
        Print(root);
        cout<<endl;
    }
    return 0;
}
