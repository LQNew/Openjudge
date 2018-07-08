/*
    用小于等于n元去买100只鸡，大鸡5元/只，小鸡3元/只,还有1/3元每只的一种小鸡，分别记为x只,y只,z只。编程求解x,y,z所有可能解。
*/
//水题，因为是100只鸡限定，时间复杂度为O(n^2) 也就万级别，所以直接暴力求解就行了~
#include<iostream>
using namespace std;
int n;
int main(){
    while(cin>>n){
        for(int x=0;x<=100;x++){
            for(int y=0;y<=100;y++){
                double z=x*5+y*3+(100-x-y)/3.0;
                if(z<n)
                    cout<<"x="<<x<<','<<"y="<<y<<','<<"z="<<100-x-y<<','<<endl;
            }
        }
    }
    return 0;
}
