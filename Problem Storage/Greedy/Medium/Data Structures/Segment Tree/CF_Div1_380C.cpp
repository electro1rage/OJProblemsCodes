#include <bits/stdc++.h>
using namespace std;

#define lp p + p
#define rp p + p + 1

const int MN = 1000003;

vector<int> tree[3 * MN];
char s[MN];

void insert(int val, int i, int s = 0, int e = MN - 3, int p = 1) {
	if (s == e) {
		tree[p].push_back(val);
		return ;
	}
	int mid = (s + e) / 2;
	if (i <= mid) insert(val, i, s, mid, lp);
	else insert(val, i, mid + 1, e, rp);
}

void build_tree(int s = 0, int e = MN - 3, int p = 1) {
	if (s == e) {
		sort(tree[p].begin(), tree[p].end());
		return ;
	}
	int mid = (s + e) / 2;
	build_tree(s, mid, lp), build_tree(mid + 1, e, rp);
	merge(tree[lp].begin(), tree[lp].end(), tree[rp].begin(), tree[rp].end(), back_inserter(tree[p]));
}

int get_ans(int l, int r, int s = 0, int e = MN - 3, int p = 1) {
	if (l <= s && e <= r) return upper_bound(tree[p].begin(), tree[p].end(), r) - tree[p].begin();
	int mid = (s + e) / 2;
	if (r <= mid) return get_ans(l, r, s, mid, lp);
	if (l > mid) return get_ans(l, r, mid + 1, e, rp);
	return get_ans(l, r, s, mid, lp) + get_ans(l, r, mid + 1, e, rp);
}

int main() {
	scanf("%s", s);
	int n = strlen(s), m, l, r, i;
	stack<int> st;
	for (i = 0; i < n; ++i) {
		if (s[i] == '(') st.push(i);
		else if (st.empty()) continue;
		else insert(i, st.top()), st.pop();
	}
	build_tree();
	scanf("%d", &m);
	for (i = 0; i < m; ++i) {
		scanf("%d %d", &l, &r);
		--l, --r;
		printf("%d\n", get_ans(l, r) * 2);
	}
	return 0;
}
