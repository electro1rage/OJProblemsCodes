#include <bits/stdc++.h>
using namespace std;

const int MN = 100005;
const long long MVAL = 10000000000LL;

long long h[MN], p[MN];

int n, m;
bool is_good(long long time) {
	for (int i = 0, j = 0; i < n; ++i) {
		if (p[j] >= h[i]) j = upper_bound(p, p + m, h[i] + time) - p;
		else {
			long long ldist = h[i] - p[j];
			if (time < ldist) return false;
			long long maxi = max((time - ldist) / 2, time - 2 * ldist) + h[i];
			j = upper_bound(p, p + m, maxi) - p;
		}
		if (j == m) return true;
	}
	return false;
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; ++i) cin >> h[i];
	for (int i = 0; i < m; ++i) cin >> p[i];

	long long ans = MVAL * 2;
	long long s = 0, e = 2 * MVAL;
	while (s <= e) {
		long long mid = (s + e) / 2;
		if (is_good(mid)) e = mid - 1, ans = mid;
		else s = mid + 1;
	}

	cout << ans << endl;
	return 0;
}
