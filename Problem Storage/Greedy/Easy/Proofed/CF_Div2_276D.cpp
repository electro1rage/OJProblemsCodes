#include <bits/stdc++.h>
using namespace std;

int bit(long long x, long long i) {
	return (x >> i) & 1;
}

int main() {
	long long l, r;
	cin >> l >> r;

	long long ans = 0;
	for (int i = 60; i >= 0; --i) {
		if (bit(r, i) && !bit(l, i)) {
			ans = (1LL << (i + 1)) - 1;
			break;
		}
	}

	cout << ans << endl;
	return 0;
}
