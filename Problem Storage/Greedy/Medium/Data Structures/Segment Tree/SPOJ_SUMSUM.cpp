#include <bits/stdc++.h>
using namespace std;

const int MM = 27, MN = 100003;

int a[MN];

struct data {
	int ones[MM] = {}, sz;
	data& operator=(const data &x) {
		int i;
		this->sz = x.sz;
		for (i = 0; i < MM; ++i) this->ones[i] = x.ones[i];
		return *this;
	}
};

long long treeor[MN * 3], treexor[MN * 3], treeand[MN * 3];
data tree[MN * 3];

void build_tree(int s = 0, int e = MN - 3, int p = 1) {
	if (s == e) {
		tree[p].sz = 1;
		treeor[p] = treexor[p] = treeand[p] = 0;
		int i;
		for (i = 0; i < MM; ++i) tree[p].ones[i] = (a[s] >> i) & 1;
		return ;
	}

	int mid = (s + e) / 2, i;

	build_tree(s, mid, p * 2);
	build_tree(mid + 1, e, p * 2 + 1);

	treeor[p] = treeor[p * 2] + treeor[p * 2 + 1];
	treexor[p] = treexor[p * 2] + treexor[p * 2 + 1];
	treeand[p] = treeand[p * 2] + treeand[p * 2 + 1];

	tree[p].sz = tree[p * 2].sz + tree[p * 2 + 1].sz;

	for (i = 0; i < MM; ++i) {
		tree[p].ones[i] = tree[p * 2].ones[i] + tree[p * 2 + 1].ones[i];

		treeor[p] += ((long long)tree[p * 2].ones[i] * tree[p * 2 + 1].sz
								+ ((long long)tree[p * 2].sz - tree[p * 2].ones[i]) * tree[p * 2 + 1].ones[i]) * (1LL << i);

		treexor[p] += ((long long)tree[p * 2].ones[i] * (tree[p * 2 + 1].sz - tree[p * 2 + 1].ones[i])
									+ ((long long)tree[p * 2].sz - tree[p * 2].ones[i]) * tree[p * 2 + 1].ones[i]) * (1LL << i);

		treeand[p] += ((long long)tree[p * 2].ones[i] * tree[p * 2 + 1].ones[i]) * (1LL << i);
	}
}

void insert(int val, int pos, int s = 0, int e = MN - 3, int p = 1) {
	if (s == e) {
		tree[p].sz = 1;
		treeor[p] = treexor[p] = treeand[p] = 0;
		int i;
		for (i = 0; i < MM; ++i) tree[p].ones[i] = (val >> i) & 1;
		return ;
	}

	int mid = (s + e) / 2, i;
	if (pos <= mid) insert(val, pos, s, mid, p * 2);
	else insert(val, pos, mid + 1, e, p * 2 + 1);

	treeor[p] = treeor[p * 2] + treeor[p * 2 + 1];
	treexor[p] = treexor[p * 2] + treexor[p * 2 + 1];
	treeand[p] = treeand[p * 2] + treeand[p * 2 + 1];

	tree[p].sz = tree[p * 2].sz + tree[p * 2 + 1].sz;

	for (i = 0; i < MM; ++i) {
		tree[p].ones[i] = tree[p * 2].ones[i] + tree[p * 2 + 1].ones[i];

		treeor[p] += ((long long)tree[p * 2].ones[i] * tree[p * 2 + 1].sz
								+ ((long long)tree[p * 2].sz - tree[p * 2].ones[i]) * tree[p * 2 + 1].ones[i]) * (1LL << i);

		treexor[p] += ((long long)tree[p * 2].ones[i] * (tree[p * 2 + 1].sz - tree[p * 2 + 1].ones[i])
									+ ((long long)tree[p * 2].sz - tree[p * 2].ones[i]) * tree[p * 2 + 1].ones[i]) * (1LL << i);

		treeand[p] += ((long long)tree[p * 2].ones[i] * tree[p * 2 + 1].ones[i]) * (1LL << i);
	}
}

pair<long long, data> get_ans(long long treeop[], char op, int l, int r, int s = 0, int e = MN - 3, int p = 1) {
	if (l <= s && e <= r) return {treeop[p], tree[p]};

	int mid = (s + e) / 2, i;
	if (r <= mid) return get_ans(treeop, op, l, r, s, mid, p * 2);
	else if (l > mid) return get_ans(treeop, op, l, r, mid + 1, e, p * 2 + 1);
	else {
		pair<long long, data> lnode = get_ans(treeop, op, l, r, s, mid, p * 2);
		pair<long long, data> rnode = get_ans(treeop, op, l, r, mid + 1, e, p * 2 + 1);
		pair<long long, data> ret;
		ret.first = lnode.first + rnode.first;
		ret.second.sz = lnode.second.sz + rnode.second.sz;

		for (i = 0; i < MM; ++i) {
			ret.second.ones[i] = lnode.second.ones[i] + rnode.second.ones[i];
			if (op == 'O') ret.first += ((long long)lnode.second.ones[i] * rnode.second.sz + (long long)(lnode.second.sz - lnode.second.ones[i]) * rnode.second.ones[i]) * (1LL << i);
			if (op == 'X') ret.first += ((long long)lnode.second.ones[i] * (rnode.second.sz - rnode.second.ones[i]) + (long long)(lnode.second.sz - lnode.second.ones[i]) * rnode.second.ones[i]) * (1LL << i);
			if (op == 'A') ret.first += ((long long)lnode.second.ones[i] * rnode.second.ones[i]) * (1LL << i);
		}
		return ret;
	}
}

int main() {
	int n, m, i;
	scanf("%d %d", &n, &m);

	for (i = 0; i < n; ++i) scanf("%d", a + i);
	build_tree();

	for (i = 0; i < m; ++i) {
		int x;
		scanf("%d", &x);
		if (x == 1) {
			int val, pos;
			scanf("%d %d", &val, &pos);
			--pos;
			insert(val, pos);
		} else {
			char op[4];
			int l, r;
			scanf("%s %d %d", op, &l, &r);
			--l, --r;
			long long ans;
			if (op[0] == 'O') {
				ans = get_ans(treeor, op[0], l, r).first;
			} else if (op[0] == 'X') {
				ans = get_ans(treexor, op[0], l, r).first;
			} else {
				ans = get_ans(treeand, op[0], l, r).first;
			}

			printf("%lld\n", ans);
		}
	}
	return 0;
}
