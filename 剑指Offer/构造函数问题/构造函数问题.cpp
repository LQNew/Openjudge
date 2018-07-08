//不是很懂复制、构造、析构函数这些区别与联系...
#include<iostream>
using namespace std;
class A{
    private:
        int value;

    public:
        A(int n){ value=n; }
        A(A other){ value=other.value; }
        void print(){
            cout<<value<<endl;
        }
};
int main(){
    A a=10;
    A b=a;
    b.print();
    return 0;
}
