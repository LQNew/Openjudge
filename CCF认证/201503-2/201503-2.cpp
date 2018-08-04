#include<iostream>
using namespace std;

bool cmp(int a[], int b[]) {

}

int main() {
	int count[1000] = { 0 };
	int num;
	if (cin >> num) {
		for (int i = 0; i < num; i++)
		{
			int j;
			if (cin >> j)
			{
				count[j]++;
			}
		}
	}

}