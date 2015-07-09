#include <bits/stdc++.h>
using namespace std;

const int MN = 101010;
const int LOGN = 19;

int X;
int M[LOGN][MN], id[MN], a[MN], depth[MN];
vector<int> adj[MN];

void dfs(int node, int p, int d) {
	int i;
	M[0][node] = p, id[node] = X, a[X] = node, depth[node] = d, ++X;
	for (i = 1; i < LOGN; ++i) {
		if (M[i - 1][node] != -1) M[i][node] = M[i - 1][M[i - 1][node]];
	}
	for (auto &x : adj[node]) {
		if (x == p) continue;
		dfs(x, node, d + 1);
	}
}

int get_lcm(int u, int v) {
	if (depth[u] < depth[v]) swap(u, v);
	int i;
	for (i = LOGN - 1; i >= 0; --i) {
		if (M[i][u] != -1 && depth[M[i][u]] >= depth[v]) u = M[i][u];
	}

	if (u == v) return u;

	for (i = LOGN - 1; i >= 0; --i) {
		if (M[i][u] != -1 && M[i][u] != M[i][v]) u = M[i][u], v = M[i][v];
	}

	return M[0][u];
}

int get_dist(int u, int v) {
	int lcm = get_lcm(u, v);
	return depth[u] + depth[v] - 2 * depth[lcm];
}

set<int> se;
int add(int u) {
	se.insert(id[u]);
	if (se.size() == 1) {
		return 1;
	}

	auto it1 = se.find(id[u]), it2 = it1;
	--it1, ++it2;
	int pre = *it1, nex = *it2;

	if (*(se.begin()) == id[u]) {
		it1 = se.end(), --it1;
		pre = *it1, nex = *it2;
	}

	if (it2 == se.end()) {
		it2 = se.begin();
		pre = *it2, nex = *it1;
	}

	int dist = get_dist(a[pre], u) + get_dist(u, a[nex]) - get_dist(a[pre], a[nex]);

	return dist / 2;
}

int main() {
	int n, k, ans = 0, sz = 0, i, j;
	scanf("%d %d", &n, &k);

	for (i = 0; i < n - 1; ++i) {
		int u, v;
		scanf("%d %d", &u, &v);
		--u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(0, -1, 0);

	for (i = 0, j = 0; i < n; ++i) {
		sz += add(i);
		while (sz > k) {
			sz -= add(j);
			se.erase(id[j]);
			++j;
		}
		ans = max(ans, i - j + 1);
	}

	printf("%d\n", ans);
	return 0;
}
