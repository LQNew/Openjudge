#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

ll s;

bool judge () {
	for (ll i = 12; i > 1; i--) {
		ll b = i - 1;
		ll t = (ll)pow(i, i);

		if ((s + b) % t)
			continue;

		ll k = (s + b) / t;
		ll p = (ll)pow(b, i);
		ll q = k * p - b;

		if (q % i)
			continue;

		printf("%lld people and 1 monkey\n", i);
		return false;
	}
	return true;
}

int main () {
	while (scanf("%lld", &s) == 1 && s != -1) {
		printf("%lld coconuts, ", s);

		if (judge ())
			printf("no solution\n");
	}
	return 0;
}

