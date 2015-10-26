/*
reality, be rent!
synapse, break!
Van!shment Th!s World !!
*/
#include <bits/stdc++.h>
using namespace std;

const int MN = 505;

bool edge[MN][MN], temp[MN][MN];
vector<int> adj[MN];
bool vst[MN];
int match[MN];

bool dfs(int node) {
	vst[node] = true;
	for (auto &x : adj[node]) {
		if (match[x] == -1 || (!vst[match[x]] && dfs(match[x]))) {
			match[x] = node;
			return true;
		}
	}
	return false;
}

int get_ans(int mid, int n) {
	int ret = 0, i, j;
	for (i = 0; i < n; ++i) for (j = 0; j < n; ++j) edge[i][j] = temp[i][j];
	for (i = 0; i < n; ++i) {
		if (i == mid) continue;
		if (!edge[mid][i]) ++ret;
		if (!edge[i][mid]) ++ret;
	}
	if (!edge[mid][mid]) ++ret;

	int edgecnt = 0;
	for (i = 0; i < n; ++i) edge[mid][i] = edge[i][mid] = 0;
	for (i = 0; i < n; ++i) adj[i].clear();
	for (i = 0; i < n; ++i) for (j = 0; j < n; ++j) if (edge[i][j]) adj[i].push_back(j), ++edgecnt;

	memset(match, -1, sizeof match);
	for (i = 0; i < n; ++i) {
		if (i == mid) continue;
		memset(vst, 0, sizeof vst);
		dfs(i);
	}

	int cnt = 0;
	for (i = 0; i < n; ++i) if (match[i] != -1) ++cnt;
	ret += edgecnt + n - 2 * cnt - 1;
	return ret;
}

int main() {
	int n, m, i;
	scanf("%d %d", &n, &m);
	for (i = 0; i < m; ++i) {
		int u, v;
		scanf("%d %d", &u, &v);
		--u, --v;
		edge[u][v] = temp[u][v] = true;
	}

	int ans = 1000000000;
	for (i = 0; i < n; ++i) ans = min(ans, get_ans(i, n));
	printf("%d\n", ans);
	return 0;
}
