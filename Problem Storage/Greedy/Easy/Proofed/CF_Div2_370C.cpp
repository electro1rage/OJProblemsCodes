#include <bits/stdc++.h>
using namespace std;

const int MN = 5050;

pair<int, int> a[MN];

int main() {
	int n, m, i, j;
	scanf("%d %d", &n, &m);

	for (i = 0; i < n; ++i) scanf("%d", &a[i].first), a[i].second = a[i].first;

	for (i = 0; i < n; ++i) {
		for (j = 0; j < n; ++j) {
			if (a[i].second != a[j].first && a[j].second != a[i].first) swap(a[i].second, a[j].second);
		}
	}

	int ans = 0;
	for (i = 0; i < n; ++i) ans += a[i].first != a[i].second;

	printf("%d\n", ans);
	for (i = 0; i < n; ++i) printf("%d %d\n", a[i].first, a[i].second);

	return 0;
}
