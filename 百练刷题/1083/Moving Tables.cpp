/* 移桌子问题，数学思维类型的题
   解题关键是计算经过每对房间的次数，然后计数最大的次数即为挪动桌子的次数！！

   输入
   The input consists of T test cases. The number of test cases ) (T is given in the first line of the input file.
   Each test case begins with a line containing an integer N , 1 <= N <= 200, that represents the number of tables to move.
   Each of the following N lines contains two positive integers s and t,
   representing that a table is to move from room number s to room number t each room number appears at most once in the N lines). From the 3 + N -rd
   line, the remaining test cases are listed in the same manner as above.
   输出
   The output should contain the minimum time in minutes to complete the moving, one per line.
*/

#include<iostream>
#include <string.h>
using namespace std;
int main()
{
    int T;
    cin>>T;
    int room[201];
    while(T--)
    {
        memset(room,0,sizeof(room)); //memset函数的使用！！赋予数组初值  要有string库的导入才可使用
        int N;
        cin>>N;
        int a,b;
        for(int i=0;i<N;i++)
        {
            cin>>a>>b;
            if(a>b)
                swap(a,b); //内置函数 swap 交换变量数值的函数
            if(a%2)
                a=a/2+1;
            else
                a=a/2;
            if(b%2)
                b=b/2+1;
            else
                b=b/2;
            //将房间对应的房间号当做一个对称过道，总共两百条过道，计数两百条过道数被通过的次数
            for(int i=a;i<=b;i++)
                room[i]++;
        }
        int max_times=0;
        for(int i=1;i<sizeof(room)/4;i++) //sizeof()函数返回的是数组占据的字节数 所以要进行 /4 操作！
            max_times=max(max_times,room[i]);
        int min_time=max_times*10;
        cout<<min_time<<endl;
    }
    return 0;
}
