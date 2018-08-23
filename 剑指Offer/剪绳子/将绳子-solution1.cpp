// 简单的动归思路~
// 从小问题逐步划分至最终的大问题~
// f(n) = max(f(i)*f(n-i))
#include<iostream>
using namespace std;
int max_Product(int length){
    if(length < 2) return 0;
    if(length == 2) return 1;
    if(length == 3) return 2;
    int *product = new int[length+1];
    product[0] = 0;
    product[1] = 1; // 作为乘子时，不需要再剪
    product[2] = 2; // 作为乘子时，不需要再剪
    product[3] = 3; // 作为乘子时，不需要再剪
    // 在长度 <=4 的绳子中，剪绳子可得到的最大乘积值是 <= 总长度本身值的，所以把这些作为递推的元条件开始分析
    for(int i=4;i<=length;i++){
        int max1 = 0;
        for(int j=1;j<=i/2;j++){
            int a = product[j]*product[i-j];
            max1 = max(a,max1);
            product[i] = max1;
        }
    }
    int max_value = product[length];
    delete[] product;
    return max_value;
}

int main(){
    int length;
    cin>>length;
    cout<<max_Product(length)<<endl;
    return 0;

}
