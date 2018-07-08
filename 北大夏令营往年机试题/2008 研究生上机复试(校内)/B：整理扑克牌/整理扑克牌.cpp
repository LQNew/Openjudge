//朴素的解法，tl了，更有效率的解法因为思路有点乱，暂时不解..
#include<iostream>
using namespace std;
int special_card;
int a[54];
int compare(const void *a, const void* b){
    return *(int*)a-*(int*)b;
}
int main(){
    while(cin>>special_card){
        int cnt=0;
        for(int i=0;i<54;i++){
            cin>>a[i];
        }
        qsort(&a[0],54,sizeof(a[0]),compare);
        while(special_card&&(a[0]!=0)){
            special_card--;
            cnt++;
            for(int i=1;i<54;i++) a[i]--;
            qsort(&a[0],54,sizeof(a[0]),compare);
        }
        if(special_card==0) cout<<cnt+a[0]<<endl;
        else if(a[0]==0){
            if(a[1]==0) cout<<cnt<<endl;
            else cout<<cnt+min(a[1],special_card)<<endl;
        }
    }
    return 0;
}
