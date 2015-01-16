#include <bits/stdc++.h>
using namespace std;

int n;

int tree[524288 + 1];

void insert(int ind, int val, int s = 0, int e = n - 1, int p = 1) {
	if (s == e) {
		tree[p] = val;
		return;
	}
	int mid = (s + e) >> 1;
	if (ind <= mid) insert(ind, val, s, mid, p + p);
	else insert(ind, val, mid + 1, e, p + p + 1);

	tree[p] = max(tree[p + p], tree[p + p + 1]);
}

int query(int l, int r, int s = 0, int e = n - 1, int p = 1) {
	if (s > r || e < l || l > r) return -1;
	if (l <= s && e <= r) return tree[p];
	int mid = (s + e) >> 1;
	return max(query(l, r, s, mid, p + p), query(l, r, mid + 1, e, p + p + 1));
}

int R[200005], P[200005], Len[200005];

int jump[200005][19], cost[200005][19];

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		--x;
		P[i] = x;
		Len[i] = y;
	}

	for (int i = n - 1; i >= 0;--i) {
		int last = upper_bound(P, P + n, P[i] + Len[i]) - P - 1;
		R[i] = max(P[i] + Len[i], query(i + 1, last));
		insert(i, R[i]);
	}

	for (int i = n - 1; i >= 0; --i) {
		int U = upper_bound(P, P + n, R[i]) - P;

		jump[i][0] = min(U, n - 1);
		cost[i][0] = max(P[U] - R[i], 0);
	}

	for (int j = 1; j < 19; ++j) {
		for (int i = 0; i < n; ++i) {
			jump[i][j] = jump[jump[i][j - 1]][j - 1];
			cost[i][j] = cost[i][j - 1] + cost[jump[i][j - 1]][j - 1];
		}
	}

	int q;
	cin >> q;
	while (q--) {
		int l, r;
		cin >> l >> r;
		--l, --r;
		int ans = 0;
		for (int j = 18; j >= 0; --j) {
			if (jump[l][j] <= r) {
				ans += cost[l][j];
				l = jump[l][j];
			}
		}

		cout << ans << endl;
	}
	return 0;
}



