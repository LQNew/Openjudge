//Ë®Ìâ
#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;
int x0,y0,x1,y1;
int a[100][100];
int b[100][100];
int c[100][100];
int main(){
    memset(c,0,sizeof(c));
    cin>>x0>>y0;
    for(int i=0;i<x0;i++){
        for(int j=0;j<y0;j++) cin>>a[i][j];
    }
    cin>>x1>>y1;
    for(int i=0;i<x1;i++){
        for(int j=0;j<y1;j++) cin>>b[i][j];
    }
    for(int i=0;i<x0;i++){
        for(int j=0;j<y1;j++){
            for(int k=0;k<y0;k++) c[i][j]+=a[i][k]*b[k][j];
        }
    }
    for(int i=0;i<x0;i++){
        for(int j=0;j<y1;j++) cout <<setw(5)<< c[i][j];
        cout<<endl;
    }


    return 0;
}
