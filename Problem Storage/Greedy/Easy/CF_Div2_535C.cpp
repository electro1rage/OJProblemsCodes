#include <bits/stdc++.h>
using namespace std;

int main() {
	long long a, b;
	cin >> a >> b;
	int n, i;
	cin >> n;
	for (i = 0; i < n; ++i) {
		long long l, t, m;
		cin >> l >> t >> m;
		long long s = l, e = 1000000 * 2;
		long long ans = -1;
		while (s <= e) {
			long long r = (s + e) / 2;
			long long val = a + (r - 1) * b;
			if (val > t) e = r - 1;
			else if (m * t >= a * (r - l + 1) + b * (r * (r - 1) / 2 - (l - 1) * (l - 2) / 2)) ans = r, s = r + 1;
			else e = r - 1;
		}
		cout << ans << endl;
	}
	return 0;
}
