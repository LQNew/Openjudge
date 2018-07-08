//暴力求解，难度一般，关于字符串字典序排序，可以直接调用strcmp()函数！
#include<iostream>
#include<cstring>
using namespace std;
struct Node{
    char str1[90];
    int grade;
    bool flag;
};
Node node[20];
int T;
int N;

int compare(const void* a, const void* b){
    Node* p1;
    Node* p2;
    p1=(Node*)a;
    p2=(Node*)b;
    return (*p2).grade-(*p1).grade;
}

int compare1(const void* a, const void* b){
    Node* p1;
    Node* p2;
    p1=(Node*)a;
    p2=(Node*)b;
    return strcmp((*p1).str1,(*p2).str1);
}

int main(){
    cin>>T;
    for(int i=0;i<T;i++){
        cin>>N;
        for(int j=0;j<N;j++){
            cin>>node[j].str1>>node[j].grade;
            node[j].flag=false;
        }
        qsort(&node[0],N,sizeof(Node),compare);
        int ans=0;
        for(int i=0;i<N-2;i++){
            bool flag=false;
            for(int j=i+1;j<N-1;j++){
                for(int k=j+1;k<N;k++){
                    if((node[j].grade+node[k].grade)==node[i].grade){
                        flag=true;
                        break;
                    }
                }
                if(flag) break;
            }
            if(flag){
                ans++;
                node[i].flag=true;
                //cout<<node[i].str1<<endl;
            }
            if(!flag){
                for(int j=i+1;j<N-2;j++){
                    for(int k=j+1;k<N-1;k++){
                        for(int t=k+1;t<N;t++){
                            if((node[j].grade+node[k].grade+node[t].grade)==node[i].grade){
                                flag=true;
                                break;
                            }
                            if(flag) break;
                        }
                    }
                    if(flag) break;
                }
                if(flag){
                    ans++;
                    node[i].flag=true;
                    //cout<<node[i].str1<<endl;
                }
            }
        }
        cout<<ans<<endl;
        qsort(&node[0],N,sizeof(Node),compare1); //字符串排序
        for(int i=0;i<N;i++){
            if(node[i].flag) cout<<node[i].str1<<endl;
        }
    }
    return 0;
}
