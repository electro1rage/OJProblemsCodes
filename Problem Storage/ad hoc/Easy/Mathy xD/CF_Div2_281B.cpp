#include <bits/stdc++.h>
using namespace std;

int main() {
	long long x, y, n;
	cin >> x >> y >> n;

	long long top = 10000000, down = 1;
	long long besta, bestb;

	for (long long b = 1; b <= n; ++b) {
		long long a1 = x * b / y, a2 = (x * b + y - 1) / y;

		long long a = a1;
		if (abs(x * b - y * a1) > abs(x * b - y * a2)) a = a2;

		if (abs(x * b - y * a) * down < y * b * top) {
			top = abs(x * b - y * a);
			down = y * b;
			besta = a, bestb = b;
		}
	}

	cout << besta << '/' << bestb << endl;
	return 0;
}
