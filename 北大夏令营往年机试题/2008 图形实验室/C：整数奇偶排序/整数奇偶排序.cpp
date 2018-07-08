//水题，为了方便编写代码，此处额外用了个优先级队列去处理问题~
#include<iostream>
#include<queue>
using namespace std;
priority_queue<int>Q1;
priority_queue<int,vector<int>,greater<int>> Q2; //小根堆的优先级队列
int a[10];
int main(){
    while(cin>>a[0]>>a[1]>>a[2]>>a[3]>>a[4]>>a[5]>>a[6]>>a[7]>>a[8]>>a[9]){
        while(!Q1.empty()) Q1.pop();
        while(!Q2.empty()) Q2.pop();
        for(int i=0;i<10;i++){
            if(a[i]%2)  Q1.push(a[i]);
            else Q2.push(a[i]);
        }
        while(!Q1.empty()){
            int a=Q1.top();
            Q1.pop();
            cout<<a<<' ';
        }
        while(!Q2.empty()){
            int a=Q2.top();
            Q2.pop();
            if(Q2.empty()) cout<<a<<endl;
            else cout<<a<<' ';
        }
    }
    return 0;
}
