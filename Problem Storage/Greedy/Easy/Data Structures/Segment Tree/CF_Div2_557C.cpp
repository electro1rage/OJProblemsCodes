#include <bits/stdc++.h>
using namespace std;

#define lp p + p
#define rp p + p + 1

const int MN = 101010;

struct node {
	int cnt, sum;
};

node tree[MN * 3];

void insert(int val, int i, int s = 0, int e = MN - 3, int p = 1) {
	if (s == e) {
		tree[p] = {1, val};
		return ;
	}
	int mid = (s + e) / 2;
	if (i <= mid) insert(val, i, s, mid, lp);
	else insert(val, i, mid + 1, e, rp);
	tree[p].cnt = tree[lp].cnt + tree[rp].cnt;
	tree[p].sum = tree[lp].sum + tree[rp].sum;
}

int get_cost(int k, int s = 0, int e = MN - 3, int p = 1) {
	if (k >= tree[p].cnt) return tree[p].sum;
	int mid = (s + e) / 2;
	if (tree[lp].cnt >= k) return get_cost(k, s, mid, lp);
	else return get_cost(k, s, mid, lp) + get_cost(k - tree[lp].cnt, mid + 1, e, rp);
}

struct data {
	int l, d, ind;
	data () {
		l = d = ind = 0;
	}
};

vector<data> a;

bool cmpd(data a, data b) {
	if (a.d != b.d) return a.d < b.d;
	return a.l < b.l;
}

bool cmpl(data a, data b) {
	if (a.l != b.l) return a.l < b.l;
	if (a.d != b.d) return a.d < b.d;
	return a.ind < b.ind;
}

int main() {
	int n, sumr = 0, i, j, k;
	scanf("%d", &n);
	a.resize(n);
	for (i = 0; i < n; ++i) scanf("%d", &a[i].l);
	for (i = 0; i < n; ++i) scanf("%d", &a[i].d), sumr += a[i].d;

	sort(a.begin(), a.end(), cmpd);
	for (i = 0; i < n; ++i) a[i].ind = i;
	sort(a.begin(), a.end(), cmpl);

	int ans = sumr;
	for (i = 0; i < n; i = j) {
		for (j = i; j < n; ++j) {
			if (a[j].l != a[i].l) break;
			sumr -= a[j].d;
		}
		int sz = j - i;
		if (sz > i) ans = min(ans, sumr);
		else {
			int rem = i - sz + 1;
			int diff = get_cost(rem);
			ans = min(ans, sumr + diff);
		}
		for (k = i; k < j; ++k) insert(a[k].d, a[k].ind);
	}

	printf("%d\n", ans);
	return 0;
}
