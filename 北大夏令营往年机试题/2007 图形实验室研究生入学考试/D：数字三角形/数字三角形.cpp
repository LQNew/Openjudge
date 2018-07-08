//从三角形的底回溯求解
#include<iostream>
using namespace std;
int N;
int matrix[101][101]; //matrix[i][j] 表示第i行第j列的数字
int a[101][101];
int main(){
    cin>>N;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=i;j++) cin>>matrix[i][j];
    }
    for(int i=N-1;i>=1;i--){
        for(int j=1;j<=i;j++){
            matrix[i][j]=max(matrix[i+1][j]+matrix[i][j],matrix[i+1][j+1]+matrix[i][j]);
        }
    }
    cout<<matrix[1][1]<<endl;
    return 0;
}
