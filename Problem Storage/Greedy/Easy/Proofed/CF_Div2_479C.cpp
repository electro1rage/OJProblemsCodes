#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, i, j;
	scanf("%d", &n);
	vector<pair<int, int> > a(n);
	for (i = 0; i < n; ++i) scanf("%d %d", &a[i].first, &a[i].second);

	int ans = 0;
	sort(a.begin(), a.end());
	for (i = 0; i < n; i = j) {
		for (j = i; j < n; ++j) if (a[j].first != a[i].first) break;
		if (a[i].second >= ans) ans = a[j - 1].second;
		else ans = a[i].first;
	}

	printf("%d\n", ans);
	return 0;
}
