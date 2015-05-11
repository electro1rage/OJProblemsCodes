#include <bits/stdc++.h>
using namespace std;

long long get_count(long long a, long long b) {
	if (a == 1) return b;
	if (b == 1) return a;
	return a / b + get_count(b, a % b);
}

int main() {
	long long a, b;
	cin >> a >> b;

	cout << get_count(a, b) << endl;
	return 0;
}
