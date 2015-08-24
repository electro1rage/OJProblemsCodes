#include <bits/stdc++.h>
using namespace std;

const int MN = 10101;

int a[MN];
vector<pair<int, int> > adj[MN];

int main() {
	freopen("dwarf.in", "r", stdin);
	freopen("dwarf.out", "w", stdout);
	int n, m, i, j;
	scanf("%d %d", &n, &m);

	for (i = 1; i <= n; ++i) scanf("%d", a + i);

	for (i = 0; i < m; ++i) {
		int c, d, e;
		scanf("%d %d %d", &c, &d, &e);
		adj[c].push_back({d, e});
	}

	bool change = true;
	while (change) {
		change = false;
		for (i = 1; i <= n; ++i) {
			int sz = adj[i].size();
			for (j = 0; j < sz; ++j) {
				int c = adj[i][j].first, d = adj[i][j].second;
				if (a[c] + a[d] < a[i]) a[i] = a[c] + a[d], change = true;
			}
		}
	}

	printf("%d\n", a[1]);
	return 0;
}
