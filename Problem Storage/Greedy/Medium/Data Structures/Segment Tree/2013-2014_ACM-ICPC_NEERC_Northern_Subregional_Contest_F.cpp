#include <bits/stdc++.h>
using namespace std;

#define lp p + p
#define rp p + p + 1

const int MN = 1010, MVAL = 1010101010;

vector<int> tree[3 * MN];
vector<int> adj[MN];
int dp[MN][55];

void insert(int pos, vector<int> &v, int s = 0, int e = MN - 3, int p = 1) {
	if (s == e) {
		tree[p] = v;
		return;
	}

	int mid = (s + e) / 2;
	if (pos <= mid) insert(pos, v, s, mid, lp);
	else insert(pos, v, mid + 1, e, rp);
}

void build_tree(int s = 0, int e = MN - 3, int p = 1) {
	if (s == e) return ;

	int mid = (s + e) / 2;
	build_tree(s, mid, lp);
	build_tree(mid + 1, e, rp);

	merge(tree[lp].begin(), tree[lp].end(), tree[rp].begin(), tree[rp].end(), back_inserter(tree[p]));
}

int get_cost(int val, int l, int r, int s = 0, int e = MN - 3, int p = 1) {
	if (l <= s && e <= r) {
		vector<int> &a = tree[p];
		return upper_bound(a.begin(), a.end(), val) - a.begin();
	}

	int mid = (s + e) / 2;
	if (r <= mid) return get_cost(val, l, r, s, mid, lp);
	if (l > mid) return get_cost(val, l, r, mid + 1, e, rp);

	return get_cost(val, l, r, s, mid, lp) + get_cost(val, l, r, mid + 1, e, rp);
}

int main() {
	freopen("flight.in", "r", stdin);
	freopen("flight.out", "w", stdout);
	int n, s, k, i, j, l;
	scanf("%d %d %d", &n, &s, &k);

	for (i = 0; i < n; ++i) {
		int x;
		scanf("%d", &x);
		adj[x - 1].push_back(i);
	}

	for (i = 0; i < s; ++i) insert(i, adj[i]);
	build_tree();

	for (i = 0; i <= s; ++i) for (l = 0; l <= k; ++l) dp[i][l] = MVAL;
	dp[0][0] = 0;

	for (i = 0; i < s; ++i) {
		int cost = 0, sz;
		for (j = i; j < s; ++j) {
			sz = adj[j].size();
			for (l = 0; l < sz; ++l) {
				if (i != j) cost += get_cost(adj[j][l], i, j - 1);
				else continue;
			}
			for (l = 0; l < k; ++l) dp[j + 1][l + 1] = min(dp[j + 1][l + 1], dp[i][l] + cost);
		}
	}

	printf("%d\n", dp[s][k]);
	return 0;
}
