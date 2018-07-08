//Ë®Ìâ
#include<iostream>
using namespace std;
int N;
int P;
struct Node{
    int id;
    int grade;
    int rank1;
};
Node node[256];
int compare(const void* a, const void* b){
    Node* p1;
    Node* p2;
    p1=(Node*)a;
    p2=(Node*)b;
    if((*p2).grade==(*p1).grade) return (*p1).id-(*p2).id;
    else return (*p2).grade-(*p1).grade;
}
int main(){
    while(cin>>N){
        if(N==0) break;
        for(int i=0;i<N;i++){
            cin>>node[i].grade;
            node[i].id=i+1;
        }
        qsort(node,N,sizeof(Node),compare);
        node[0].rank1=1;
        for(int i=1;i<N;i++){
            if(node[i].grade==node[i-1].grade) node[i].rank1=node[i-1].rank1;
            else node[i].rank1=i+1;
        }
        cin>>P;
        if(node[P-1].rank1!=P) cout<<0<<endl;
        else{
            for(int i=P-1;i<N;i++){
                if(node[i].rank1==P) cout<<node[i].id<<' ';
                else break;
            }
            cout<<endl;
        }
    }
    return 0;
}
