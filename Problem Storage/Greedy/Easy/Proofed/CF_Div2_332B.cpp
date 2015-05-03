#include <bits/stdc++.h>
using namespace std;

const int MN = 200005;

int a[MN];
pair<long long, int> maxl[MN], maxr[MN];

int main() {
	int n, k;
	scanf("%d %d", &n, &k);

	for (int i = 0; i < n; ++i) scanf("%d", a + i);

	long long ans = 0;
	int i, j;
	for (i = n - 1, j = 0; j < k; --i, ++j) {
		ans += a[i];
	}

	maxr[i + 1].first = ans, maxr[i + 1].second = i + 1;
	for (; i >= 0; --i) {
		ans -= a[i + k], ans += a[i];
		if (ans >= maxr[i + 1].first) maxr[i].first = ans, maxr[i].second = i;
		else maxr[i] = maxr[i + 1];
	}

	ans = 0;
	for (i = 0, j = 0; j < k; ++i, ++j) {
		ans += a[i];
	}

	maxl[i - 1].first = ans, maxl[i - 1].second = i - k;
	for (; i < n; ++i) {
		ans -= a[i - k], ans += a[i];
		if (ans > maxl[i - 1].first) maxl[i].first = ans, maxl[i].second = i - k + 1;
		else if (ans < maxl[i - 1].first) maxl[i] = maxl[i - 1];
	}

	ans = 0;
	for (i = k; i <= n - k; ++i) {
		ans = max(ans, maxl[i - 1].first + maxr[i].first);
	}

	for (i = k; i <= n - k; ++i) {
		if (maxl[i - 1].first + maxr[i].first == ans) {
			printf("%d %d\n", maxl[i - 1].second + 1, maxr[i].second + 1);
			return 0;
		}
	}
	return 0;
}





