/*
reality, be rent!
synapse, break!
Van!shment Th!s World !!
*/
#include <bits/stdc++.h>
using namespace std;

const int MN = 50505;

int head[MN], nex[2 * MN], to[2 * MN], parent[MN];
int X;
bool vst[MN];
bool good[MN];
vector<vector<int> > ans;

void add_edge(int u, int v) {
	nex[X] = head[u], to[X] = v, head[u] = X, ++X;
}

void add_ans(int u, int v, int c) {
	vector<int> a, b;
	while (u != c) a.push_back(u), u = parent[u];
	while (v != c) b.push_back(v), v = parent[v];
	a.push_back(c);
	a.insert(a.end(), b.rbegin(), b.rend());
	ans.push_back(a);
}

int dfs(int node, int p) {
	int sz, pre = -1, cur, i, j;
	vst[node] = true, parent[node] = p;
	vector<int> temp1, temp2;
	for (i = head[node]; i != -1; i = nex[i]) {
		int v = to[i];
		if (vst[v]) continue;
		cur = dfs(v, node);
		if (cur != -1) {
			if (pre == -1) pre = cur;
			else add_ans(pre, cur, node), pre = -1;
		}
	}
	if (!good[node]) return pre;
	if (pre == -1) return node;
	add_ans(pre, node, node);
	return -1;
}

int main() {
	int n, m, k, i, j;
	memset(head, -1, sizeof head);
	scanf("%d %d %d", &n, &m, &k);
	for (i = 0; i < m; ++i) {
		int u, v;
		scanf("%d %d", &u, &v);
		--u, --v;
		add_edge(u, v), add_edge(v, u);
	}

	for (i = 0; i < k; ++i) {
		int x;
		scanf("%d", &x);
		--x, good[x] = true;
	}

	vector<int> temp;
	for (i = 0; i < n; ++i) {
		if (good[i] && !vst[i]) dfs(i, -1);
	}

	int sz1 = ans.size(), sz2;
	printf("%d\n", sz1);
	for (i = 0; i < sz1; ++i) {
		sz2 = ans[i].size();
		printf("%d", sz2 - 1);
		for (j = 0; j < sz2; ++j) {
			printf(" %d", ans[i][j] + 1);
		}
		puts("");
	}
	return 0;
}
