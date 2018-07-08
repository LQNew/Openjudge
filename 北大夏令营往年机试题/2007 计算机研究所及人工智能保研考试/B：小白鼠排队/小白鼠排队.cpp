//Ë®Ìâ
#include<iostream>
using namespace std;
int N;
struct Node{
    int weight;
    char color[10];
};
Node node[100];

int compare(const void* a, const void* b){
    Node*p1;
    Node*p2;
    p1=(Node*)a;
    p2=(Node*)b;
    return((*p2).weight-(*p1).weight);
}
int main(){
    cin>>N;
    for(int i=0;i<N;i++) cin>>node[i].weight>>node[i].color;
    qsort(node,N,sizeof(Node),compare);
    for(int i=0;i<N;i++) cout<<node[i].color<<endl;
    return 0;
}
