/*
reality, be rent!
synapse, break!
Van!shment Th!s World !!
*/
#include <bits/stdc++.h>
using namespace std;

#define lp p + p
#define rp p + p + 1

const int MN = 202020, MM = 200005;

int L[MN], R[MN], dpth[MN], a[MN];
int tree[2][3 * MM], lazy[2][3 * MM];
vector<int> l[2], adj[MN];
int X;

void dfs(int node, int parent, int d) {
	dpth[node] = d, L[node] = X, l[d % 2].push_back(X), ++X;
	for (auto &x : adj[node]) {
		if (x == parent) continue;
		dfs(x, node, d + 1);
	}
	R[node] = X, ++X;
}

void push_down(int p, int tree[3 * MM], int lazy[3 * MM]) {
	tree[lp] += lazy[p], tree[rp] += lazy[p];
	lazy[lp] += lazy[p], lazy[rp] += lazy[p];
	lazy[p] = 0;
}


void update(int l, int r, int val, int tree[3 * MM], int lazy[3 * MM], int s = 0, int e = MM - 3, int p = 1) {
	if (l <= s && e <= r) {
		if (s != e) push_down(p, tree, lazy);
		tree[p] += val, lazy[p] += val;
		return ;
	}
	push_down(p, tree, lazy);
	int mid = (s + e) / 2;
	if (r <= mid) update(l, r, val, tree, lazy, s, mid, lp);
	else if (l > mid) update(l, r, val, tree, lazy, mid + 1, e, rp);
	else {
		update(l, r, val, tree, lazy, s, mid, lp);
		update(l, r, val, tree, lazy, mid + 1, e, rp);
	}
}

int get_val(int i, int tree[3 * MM], int lazy[3 * MM], int s = 0, int e = MM - 3, int p = 1) {
	if (s == e) return tree[p];
	push_down(p, tree, lazy);
	int mid = (s + e) / 2;
	if (i <= mid) return get_val(i, tree, lazy, s, mid, lp);
	return get_val(i, tree, lazy, mid + 1, e, rp);
}

int main() {
	int n, m, i;
	scanf("%d %d", &n, &m);
	for (i = 0; i < n; ++i) scanf("%d", a + i);
	for (i = 0; i < n - 1; ++i) {
		int u, v;
		scanf("%d %d", &u, &v);
		--u, --v;
		adj[u].push_back(v), adj[v].push_back(u);
	}

	dfs(0, -1, 0);
	for (i = 0; i < n; ++i) {
		int p = dpth[i] % 2;
		int l1 = lower_bound(l[p].begin(), l[p].end(), L[i]) - l[p].begin();
		update(l1, l1, a[i], tree[p], lazy[p]);
	}

	for (i = 0; i < m; ++i) {
		int op, x, val;
		scanf("%d", &op);
		if (op == 1) {
			scanf("%d %d", &x, &val);
			--x;
			int p = dpth[x] % 2;
			int l1 = lower_bound(l[p].begin(), l[p].end(), L[x]) - l[p].begin();
			int r1 = lower_bound(l[p].begin(), l[p].end(), R[x]) - l[p].begin() - 1;
			int l2 = lower_bound(l[!p].begin(), l[!p].end(), L[x]) - l[!p].begin();
			int r2 = lower_bound(l[!p].begin(), l[!p].end(), R[x]) - l[!p].begin() - 1;
			if (l1 <= r1) update(l1, r1, val, tree[p], lazy[p]);
			if (l2 <= r2) update(l2, r2, -val, tree[!p], lazy[!p]);
		} else {
			scanf("%d", &x);
			--x;
			int p = dpth[x] % 2;
			int ind = lower_bound(l[p].begin(), l[p].end(), L[x]) - l[p].begin();
			printf("%d\n", get_val(ind, tree[p], lazy[p]));
		}
	}
	return 0;
}
