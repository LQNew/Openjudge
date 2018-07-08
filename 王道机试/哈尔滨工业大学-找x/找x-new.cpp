#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int n;
char value[100];
char search_value[100];

struct Node
{

    char value[100];
    int sign;
};
Node node[200];

int compare(const void*a,const void*b)
{
    Node*p;
    Node*p1;
    p=(Node*)a;
    p1=(Node*)b;
    return strcmp((*p).value,(*p1).value); //按照学号排序
}

int main()
{
    while(cin>>n)
    {
        for(int i=0;i<n;i++)
        {
            cin>>node[i].value;
            node[i].sign=i;
        }
        cin>>search_value;
        qsort(node,n,sizeof(Node),compare);
        if(bsearch(&search_value,node,n,sizeof(Node),compare))//No未查询的元素，给的是索引形式~
        {
             Node*p=(Node*)bsearch(&search_value,node,n,sizeof(Node),compare); //获取对应的结构体元素
             cout<<(*p).sign<<endl;
        }
        else
            cout<<-1<<endl;
    }
    return 0;
}
