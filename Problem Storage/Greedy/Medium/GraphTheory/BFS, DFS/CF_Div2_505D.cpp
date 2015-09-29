#include <bits/stdc++.h>
using namespace std;

const int MN = 101010;

vector<int> adj[MN], radj[MN];
int id[MN], on[MN], low[MN], disc[MN], cmp[MN], X;
bool vst[MN];
stack<int> st;

int dfs(int node) {
	vst[node] = true, low[node] = disc[node] = X, ++X, st.push(node);
	on[node] = true;
	for (auto &x : adj[node]) {
		if (!vst[x]) low[node] = min(low[node], dfs(x));
		else if (on[x]) low[node] = min(low[node], disc[x]);
	}
	on[node] = false;
	if (low[node] == disc[node]) {
		while (true) {
			int t = st.top(); st.pop();
			id[t] = node;
			++cmp[node];
			if (t == node) break;
		}
	}
	return low[node];
}

int get_count(int node) {
	vst[node] = true;
	bool ret = cmp[id[node]] == 1;
	for (auto &x : adj[node]) {
		if (!vst[x]) ret &= get_count(x);
	}
	for (auto &x : radj[node]) {
		if (!vst[x]) ret &= get_count(x);
	}
	return ret;
}

int main() {
	int n, m, i;
	scanf("%d %d", &n, &m);
	for (i = 0; i < m; ++i) {
		int u, v;
		scanf("%d %d", &u, &v);
		--u, --v;
		adj[u].push_back(v);
		radj[v].push_back(u);
	}
	for (i = 0; i < n; ++i) if (!vst[i]) dfs(i);
	memset(vst, 0, sizeof vst);
	int ans = n;
	for (i = 0; i < n; ++i) if (!vst[i]) ans -= get_count(i);
	printf("%d\n", ans);
	return 0;
}
