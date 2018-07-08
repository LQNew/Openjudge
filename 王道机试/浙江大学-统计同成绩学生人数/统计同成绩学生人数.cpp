#include<iostream>
#include<algorithm>
using namespace std;
int N;
int grade[1000];
int search_grade;

int compare(const void*a,const void*b)
{
    return *(int*)a-*(int*)b;
}

int sign;
int main()
{
    while(cin>>N) //输入格式是个大问题！！要注意输入格式的选择！
    {
        if(N==0)
            break;
        for(int i=0;i<N;i++)
        {
            cin>>grade[i];
        }
        cin>>search_grade;
        qsort(grade,N,sizeof(grade[0]),compare);
        if(bsearch(&search_grade,grade,N,sizeof(grade[0]),compare))//search_grade未查询的元素，给的是索引形式~
        {
             sign=(long(bsearch(&search_grade,grade,N,sizeof(grade[0]),compare))-long(grade))/sizeof(int); //获取查询出的下标~
             int num=1;
             for(int i=sign+1;i<N;i++)
             {
                 if(grade[i]==search_grade)
                    num++;
                 else
                    break;
             }
             for(int i=sign-1;i>=0;i--)
             {
                 if(grade[i]==search_grade)
                    num++;
                 else
                    break;
             }
             cout<<num<<endl;
        }
        else
            cout<<0<<endl;
    }
    return 0;
}
