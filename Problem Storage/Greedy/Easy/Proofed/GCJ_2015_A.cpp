#include <bits/stdc++.h>
using namespace std;

int a[1005];

int main() {
	freopen("A-large.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T, K = 1;
	cin >> T;
	while (T--) {
		int ans1 = 0, ans2 = 0;
		int n;
		cin >> n;

		for (int i = 0; i < n; ++i) cin >> a[i];

		for (int i = 1; i < n; ++i) ans1 += max(0, a[i - 1] - a[i]);

		int da = 0;
		for (int i = 1; i < n; ++i) if (a[i] < a[i - 1]) da = max(da, a[i - 1] - a[i]);

		for (int i = 0; i < n - 1; ++i) {
			ans2 += min(a[i], da);
		}
		cout << "Case #" << K++ << ": " << ans1 << ' ' << ans2 << endl;
	}
	return 0;
}
