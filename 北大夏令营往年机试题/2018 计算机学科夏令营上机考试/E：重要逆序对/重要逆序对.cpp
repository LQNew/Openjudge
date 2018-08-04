//在求逆序对数的基础上稍微加了点判别修饰，因为指针的添加并不会过多地影响到总的时间复杂度，所以仍是nlog(n)的复杂度
#include<iostream>
using namespace std;
int a[200000];//初始化数组中元素个数最大为20000
int N;
long long cnt;
void Merge_pass(int *A,int *L,int left_count,int *R,int right_count){
    int i,j,k,pointer;
    i=0;j=0;k=0;pointer=0;
    while(i<left_count && j<right_count){
        if(L[i]<=R[j]) A[k++]=L[i++];
        else{
            while((long)L[pointer]<=(long)2*R[j] && pointer<left_count){
                pointer++;
            }
            if(pointer<left_count) cnt+=(left_count-pointer);
            A[k++]=R[j++];
        }
    }
    while(i<left_count) A[k++]=L[i++];
    while(j<right_count) A[k++]=R[j++];
}

void Merge_sort(int *A, int cnt){
    int mid=cnt/2;
    if(mid==0) return;
    int *L=new int[mid];
    int *R=new int[cnt-mid];
    for(int i=0;i<mid;i++) L[i]=A[i];
    for(int j=mid;j<cnt;j++) R[j-mid]=A[j];
    Merge_sort(L, mid);
    Merge_sort(R, cnt-mid);
    Merge_pass(A,L,mid,R,cnt-mid);
    delete[]R;
    delete[]L;
}

int main(){
    cin>>N;
    if(N<=0) cout<<0<<endl;
    else{
        cnt=0;
        for(int i=0;i<N;i++) cin>>a[i];
        Merge_sort(a,N);
        /*
        for(int i=0;i<N;i++) cout<<a[i]<<' '; //打印出排好序的数组元素
        cout<<endl;
        */
        cout<<cnt<<endl;
    }
    return 0;
}
