#include <bits/stdc++.h>
using namespace std;

const int MN = 101010;

vector<int> adj[MN];
bool oddcyc = false, vst[MN], dpth[MN];
int even[MN], odd[MN];
int X;

int dfs(int node, bool d) {
	vst[node] = true;
	int ret = 1, sz = adj[node].size(), i;
	even[X] += !(d&1), odd[X] += d&1, dpth[node] = d;
	for (i = 0; i < sz; ++i) {
		if (!vst[adj[node][i]]) ret += dfs(adj[node][i], !d);
		else if (dpth[node] == dpth[adj[node][i]]) oddcyc = true;
	}
	return ret;
}

int main() {
	int n, m, i;
	scanf("%d %d", &n, &m);
	if (m == 0) {
		printf("3 %I64d\n", 1LL * n * (n - 1) * (n - 2) / 6);
		return 0;
	}

	for (i = 0; i < m; ++i) {
		int x, y;
		scanf("%d %d", &x, &y);
		--x, --y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	int maxi = 0;
	for (i = 0; i < n; ++i) if (!vst[i]) maxi = max(maxi, dfs(i, 0)), ++X;

	if (oddcyc) {
		printf("0 1\n");
		return 0;
	}

	if (maxi == 2) {
		int sz2 = 0, sz1 = 0;
		for (i = 0; i < X; ++i) sz2 += (even[i] + odd[i]) == 2, sz1 += (even[i] + odd[i]) == 1;
		printf("2 %I64d\n", 1LL * sz2 * (sz1 + 2LL * sz2 - 2));
		return 0;
	}


	long long ans = 0;
	for (i = 0; i < X; ++i) ans += 1LL * even[i] * (even[i] - 1) / 2 + 1LL * odd[i] * (odd[i] - 1) / 2;

	printf("1 %I64d\n", ans);
	return 0;
}
