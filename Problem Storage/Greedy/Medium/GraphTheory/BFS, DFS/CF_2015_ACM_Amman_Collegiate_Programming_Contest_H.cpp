#include <bits/stdc++.h>
using namespace std;

const int MN = 101010;

int low[MN], id[MN], root[MN], dpth[MN], X;
bool vst[MN];
set<int> diff;
vector<int> adj[MN];
vector<int> tree[MN];
vector<pair<int, int> > edge;

int find_next(int i) {
	if (root[i] == i) return i;
	return root[i] = find_next(root[i]);
}

void get_union(int u, int v) {
	u = find_next(u), v = find_next(v);
	root[u] = root[v];
}

void get_components(int u, int v) {
	if (id[u] > id[v]) swap(u, v);
	if (low[v] <= id[u]) get_union(u, v);
}

void dfs(int node, int parent) {
	vst[node] = true, low[node] = X, id[node] = X, ++X;

	for (auto &x : adj[node]) {
		if (x == parent) continue;
		if (!vst[x]) dfs(x, node), low[node] = min(low[node], low[x]);
		else low[node] = min(low[node], id[x]);
	}
}

void dfs(int node, int parent, int d) {
	dpth[node] = d;
	for (auto &x : tree[node]) if (x != parent) dfs(x, node, d + 1);
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int n, m, i;
		scanf("%d %d", &n, &m);
		for (i = 0; i < n; ++i) vst[i] = false, root[i] = i, adj[i].clear(), tree[i].clear();
		X = 0, edge.clear(), diff.clear();

		for (i = 0; i < m; ++i) {
			int u, v;
			scanf("%d %d", &u, &v);
			--u, --v;
			edge.push_back({u, v});
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		dfs(0, -1);

		for (i = 0; i < m; ++i) get_components(edge[i].first, edge[i].second);

		int fnode;
		for (i = 0; i < m; ++i) {
			int u = edge[i].first, v = edge[i].second;
			u = find_next(u), v = find_next(v);
			diff.insert(u), diff.insert(v), fnode = v;
			if (u != v) {
				tree[u].push_back(v);
				tree[v].push_back(u);
			}
		}

		int sz = diff.size(), maxi = -1, mnode;

		dfs(fnode, -1, 0);

		for (i = 0; i < n; ++i) {
			int u = find_next(i);
			if (dpth[u] > maxi) maxi = dpth[u], mnode = u;
		}

		dfs(mnode, -1, 0);

		maxi = -1;
		for (i = 0; i < n; ++i) {
			int u = find_next(i);
			if (dpth[u] > maxi) maxi = dpth[u];
		}

		printf("%d\n", sz - 1 - maxi);
	}
	return 0;
}
