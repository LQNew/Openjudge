//题目不仅水，还烦！！
#include<iostream>
using namespace std;
int N;
struct Node{
    char name[21];
    int test_grade;
    int class_grade;
    char student_leader[2];
    char province_student[2];
    int papers;
    int bonus;
};
Node node[100];

int compare(const void* a, const void* b){
    Node*p1;
    Node*p2;
    p1=(Node*)a;
    p2=(Node*)b;
    return((*p2).bonus-(*p1).bonus);
}
int main(){
    cin>>N;
    int ans=0;
    for(int i=0;i<N;i++){
        cin>>node[i].name>>node[i].test_grade>>node[i].class_grade>>node[i].student_leader>>node[i].province_student>>node[i].papers;
        node[i].bonus=0;
    }
    for(int i=0;i<N;i++){
        if(node[i].test_grade>80&&node[i].papers>=1) node[i].bonus+=8000;
        if(node[i].test_grade>85&&node[i].class_grade>80) node[i].bonus+=4000;
        if(node[i].test_grade>90) node[i].bonus+=2000;
        if(node[i].test_grade>85&&node[i].province_student[0]=='Y') node[i].bonus+=1000;
        if(node[i].class_grade>80&&node[i].student_leader[0]=='Y') node[i].bonus+=850;
        ans+=node[i].bonus;
    }
    qsort(node,N,sizeof(Node),compare);
    cout<<node[0].name<<endl;
    cout<<node[0].bonus<<endl;
    cout<<ans<<endl;
    return 0;
}
