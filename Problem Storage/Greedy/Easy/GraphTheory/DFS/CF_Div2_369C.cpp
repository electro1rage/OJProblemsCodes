#include <bits/stdc++.h>
using namespace std;

const int MN = 101010;

vector<int> ans;
vector<pair<int, int> > adj[MN];

bool dfs(int parent, int node, int bad) {
	bool ret = 0;
	for (auto &x : adj[node]) {
		if (x.first == parent) continue;
		ret |= dfs(node, x.first, x.second);
	}

	if (bad && !ret) ans.push_back(node + 1);
	return bad | ret;
}

int main() {
	int n, i;
	scanf("%d", &n);

	for (i = 0; i < n - 1; ++i) {
		int u, v, t;
		scanf("%d %d %d", &u, &v, &t);
		--u, --v, --t;
		adj[u].push_back({v, t});
		adj[v].push_back({u, t});
	}

	dfs(-1, 0, 0);

	int sz = ans.size();
	printf("%d\n", sz);
	for (i = 0; i < sz; ++i) {
		if (i) putchar(' ');
		printf("%d", ans[i]);
	}
	puts("");
	return 0;
}
