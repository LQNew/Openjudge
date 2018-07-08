#include<iostream>
#include<queue>
using namespace std;
struct cmp{
    bool operator()(int& a,int& b){
        return a>b;
    }
};
priority_queue<int,vector<int>,cmp> odd_q;
priority_queue<int,vector<int>,cmp> even_q;
int a;
int main(){
    while(!odd_q.empty()) odd_q.pop();
    while(!even_q.empty()) even_q.pop();
    for(int i=0;i<10;i++){
        cin>>a;
        if(a%2) odd_q.push(a);
        else even_q.push(a);
    }
    while(!odd_q.empty()){
        a=odd_q.top();
        cout<<a<<' ';
        odd_q.pop();
    }
    while(!even_q.empty()){
        a=even_q.top();
        cout<<a<<' ';
        even_q.pop();
    }
    cout<<endl;
    return 0;
}
