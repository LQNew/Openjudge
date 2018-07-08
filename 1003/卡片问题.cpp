//1003 简单题
//In general you can make n cards overhang by 1/2 + 1/3 + 1/4 + ... + 1/(n + 1) card lengths,
//where the top card overhangs the second by 1/2, the second overhangs tha third by 1/3, the third overhangs the fourth by 1/4, etc.,
//and the bottom card overhangs the table by 1/(n + 1).
//卡片长度元单位为1，输入给出总卡片长度，求出叠盖了多少张卡片~
#include<iostream>
using namespace std;
int main()
{
	float input;
	while (cin >> input)
	{
		if (input == 0.00)
			break;
		float total = 0.00;
		int i = 1;
		while (total < input)
		{
			i = i + 1;
			total = total + 1.0 / i; //此处隐式类型转换，注意/两边的数据类型！！
		}
		cout << i-1 <<" "<<"card(s)"<< endl;
	}
	return 0;
}
