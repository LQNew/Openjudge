//本道题思维难度很大，编程实现很水，具体的思维我没有细想过，大致的思路是，每次从所有电池寿命中挑出寿命最长的，如果该电池寿命>其余电池寿命之和，那么该寿命最大的电池用不完；
//如果其他电池寿命大于最大电池寿命，那么所有电池都可以用完，具体的思路我也不是很明朗...就是理解到此处 orz..
#include <cstring>
#include <iostream>
#include <iomanip>
using namespace std;
int main(){
    int n;
    while(cin >> n)
    {
        int sum = 0;
        int maxn = 0;
        int x;
        for(int i=1;i<= n;i++){
            cin>>x;
            maxn = max(maxn, x);
            sum += x;
        }
        int sum2 = sum-maxn;
        if(sum2 <= maxn) cout<<fixed<<setprecision(1)<<double(sum2)<<endl;
        else cout<<fixed<<setprecision(1)<<double(sum/2.0)<<endl;
    }
    return 0;
}
