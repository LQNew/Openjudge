//水题，本题我用了优先级队列，并且设置优先级队列的优先级是小在先
#include<iostream>
#include<queue>
using namespace std;
priority_queue<int,vector<int>,greater<int>> odd_q; //greater设置为小根堆，队列是从小到大排序
priority_queue<int,vector<int>,greater<int>> even_q;
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
