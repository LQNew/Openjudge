//Ë®Ìâ
#include<iostream>
#include<iomanip>
using namespace std;
int n;
struct Node{
    int credit;
    int grade;
};
Node node[10];
double compute_gpa(int x){
    if(x>=90&&x<=100) return 4.0;
    else if(x>=85&&x<=89) return 3.7;
    else if(x>=82&&x<=84) return 3.3;
    else if(x>=78&&x<=81) return 3.0;
    else if(x>=75&&x<=77) return 2.7;
    else if(x>=72&&x<=74) return 2.3;
    else if(x>=68&&x<=71) return 2.0;
    else if(x>=64&&x<=67) return 1.5;
    else if(x>=60&&x<=63) return 1.0;
    else return 0.0;
}
int main(){
    cin>>n;
    double credit_all=0;
    for(int i=0;i<n;i++){
        cin>>node[i].credit;
        credit_all+=node[i].credit;
    }
    for(int i=0;i<n;i++) cin>>node[i].grade;
    double ans=0;
    for(int i=0;i<n;i++) ans+=(compute_gpa(node[i].grade)*node[i].credit);
    cout<<fixed<<setprecision(2)<<ans/credit_all;
    return 0;
}
