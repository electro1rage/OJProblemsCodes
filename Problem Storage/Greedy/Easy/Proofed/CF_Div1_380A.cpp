#include <bits/stdc++.h>
using namespace std;

const int MN = 101010;

unordered_map<long long, int> memo;
long long a[MN];
int op[MN], l[MN], c[MN];
vector<pair<long long, int> > v;
int ans[MN];
priority_queue<pair<long long, int> > q;

int main() {
	int m, n, i;
	scanf("%d", &m);
	for (i = 0; i < m; ++i) {
		int x;
		scanf("%d", &x);
		op[i] = x;
		if (x == 1) scanf("%d", l + i);
		else scanf("%d %d", l + i, c + i);
	}
	scanf("%d", &n);
	for (i = 0; i < n; ++i) scanf("%I64d", a + i), --a[i], q.push({a[i], i});

	long long sz = 0;
	for (i = 0; i < m; ++i) {
		if (op[i] == 1) {
			memo[sz] = l[i], ++sz;
		} else {
			v.push_back({sz - 1, l[i]});
			if (sz + 1LL * l[i] * c[i] > a[n - 1]) break;
			sz += 1LL * l[i] * c[i];
		}
	}

	while (true) {
		while (!q.empty() && memo.count(q.top().first)) ans[q.top().second] = memo[q.top().first], q.pop();
		if (q.empty()) break;
		while (q.top().first > v.back().first) {
			long long x = q.top().first;
			i = q.top().second, q.pop();
			x = (x - v.back().first - 1) % v.back().second;
			q.push({x, i});
		}
		v.pop_back();
	}

	for (i = 0; i < n; ++i) {
		if (i) putchar(' ');
		printf("%d", ans[i]);
	}
	puts("");
	return 0;
}
