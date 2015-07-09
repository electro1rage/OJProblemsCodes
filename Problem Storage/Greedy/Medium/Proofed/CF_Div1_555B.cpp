#include <bits/stdc++.h>
using namespace std;

const int MN = 202020;

set<pair<long long, int> > se;
vector<pair<long long, pair<long long, int> > > a;
int ans[MN];

int main() {
	int n, m, i, j;
	scanf("%d %d", &n, &m);

	long long pl, pr, l, r;
	cin >> pl >> pr;
	for (i = 1; i < n; ++i) {
		cin >> l >> r;
		a.push_back({r - pl, {l - pr, i - 1}});
		pl = l, pr = r;
	}

	sort(a.begin(), a.end());

	for (i = 0; i < m; ++i) {
		long long x;
		cin >> x;
		se.insert({x, i + 1});
	}

	for (i = 0; i < n - 1; ++i) {
		r = a[i].first, l = a[i].second.first, j = a[i].second.second;
		auto it = se.lower_bound({l, -50});
		if (it == se.end() || it->first > r) {
			puts("No");
			return 0;
		}
		ans[j] = it->second;
		se.erase(it);
	}

	puts("Yes");
	for (i = 0; i < n - 1; ++i) {
		if (i) putchar(' ');
		printf("%d", ans[i]);
	}
	puts("");
	return 0;
}
