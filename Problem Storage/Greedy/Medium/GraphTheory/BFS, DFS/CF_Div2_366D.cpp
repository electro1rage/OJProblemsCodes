#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for((i)=0;(i)<(int)(n);++(i))

const int MN = 1010;

struct edge {
	int u, l, r;
};

vector<edge> adj[MN];
int vst[MN];
bool have[MN * MN];
int n, clr;

bool dfs(int parent, int node, int l, int r) {
	if (node == n - 1) return true;
	int i, sz = adj[node].size();
	vst[node] = clr;
	REP(i, sz) {
		if (adj[node][i].l <= l && r <= adj[node][i].r && vst[adj[node][i].u] != clr)
			if (dfs(node, adj[node][i].u, l, r)) return true;
	}
	return false;
}

int get_ans(int l) {
	int s = 0, e = 1000000, ret = l - 1;
	while (s <= e) {
		++clr;
		int mid = (s + e) / 2;
		if (dfs(-1, 0, l, l + mid)) ret = l + mid, s = mid + 1;
		else e = mid - 1;
	}
	return ret - l + 1;
}

int main() {
	int m;
	scanf("%d %d", &n, &m);

	int i;
	REP(i, m) {
		int a, b, l, r;
		scanf("%d %d %d %d", &a, &b, &l, &r);
		--a, --b;
		adj[a].push_back({b, l, r});
		adj[b].push_back({a, l, r});
		have[l] = true;
	}

	int ans = 0;
	REP(i, MN * MN) if (have[i]) ans = max(ans, get_ans(i));

	if (ans == 0) {
		puts("Nice work, Dima!");
		return 0;
	}

	printf("%d\n", ans);
	return 0;
}
