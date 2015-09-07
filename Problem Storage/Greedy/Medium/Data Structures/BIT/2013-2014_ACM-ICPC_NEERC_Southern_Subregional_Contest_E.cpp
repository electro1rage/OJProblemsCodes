#include <bits/stdc++.h>
using namespace std;

#define lp p + p
#define rp p + p + 1

const int MN = 500003, MA = 1000003, MVAL = MA * 3;

int a[MN], n, m;
int treemax[MA], b[MN];
long long val[MN];
vector<pair<int, long long> > tree[500003];
pair<int, int> treemin[1048979];

void insert_smaller(int pos) {
	while (pos < MA) {
		++treemax[pos];
		pos += pos & -pos;
	}
}

int get_smaller(int pos) {
	int ret = 0;
	while (pos > 0) {
		ret += treemax[pos];
		pos -= pos & -pos;
	}
	return ret;
}

void insert(int x, int i, int val) {
	x = n - x;
	for (; x < MN; x += (x & -x)) tree[x].push_back({i, val});
}

void acum(vector<pair<int, long long > > &temp) {
	int sz = temp.size(), i;
	for (i = 1; i < sz; ++i) temp[i].second += temp[i - 1].second;
}

void build_tree() {
	int i;
	for (i = 0; i < MN; ++i) sort(tree[i].begin(), tree[i].end()), acum(tree[i]);
}

long long get_diff(int x, int val1, int val2) {
	long long ret = 0;
	x = n - x;
	for (; x > 0; x -= (x & -x)) {
		auto it1 = upper_bound(tree[x].begin(), tree[x].end(), pair<int, long long> {val2, 1LL * MN * MN});
		if (it1 == tree[x].begin()) continue;
		--it1;
		auto it2 = lower_bound(tree[x].begin(), tree[x].end(), pair<int, long long> {val1, -101});
		if (it2 == tree[x].begin()) ret += it1->second;
		else --it2, ret += it1->second - it2->second;
	}
	return ret;
}

void insert_max(int x, int val) {
	++x;
	for (; x < MN; x += (x & -x)) treemax[x] = max(treemax[x], val);
}

int get_max(int x) {
	++x;
	int ret = 0;
	for (; x > 0; x -= (x & -x)) ret = max(ret, treemax[x]);
	return ret;
}

pair<int, int> get_min(int l, int r, int s = 0, int e = MN - 3, int p = 1) {
	if (l <= s && e <= r) return treemin[p];
	int mid = (s + e) / 2;
	if (r <= mid) return get_min(l, r, s, mid, lp);
	if (l > mid) return get_min(l, r, mid + 1, e, rp);
	return min(get_min(l, r, s, mid, lp), get_min(l, r, mid + 1, e, rp));
}

void remove_min(int i, int s = 0, int e = MN - 3, int p = 1) {
	if (s == e) {
		treemin[p] = {MVAL, 0.0};
		return ;
	}
	int mid = (s + e) / 2;
	if (i <= mid) remove_min(i, s, mid, lp);
	else remove_min(i, mid + 1, e, rp);
	treemin[p] = min(treemin[lp], treemin[rp]);
}

void insert_min(int val, int i, int s = 0, int e = MN - 3, int p = 1) {
	if (s == e) {
		treemin[p] = {val, i};
		return ;
	}
	int mid = (s + e) / 2;
	if (i <= mid) insert_min(val, i, s, mid, lp);
	else insert_min(val, i, mid + 1, e, rp);
	treemin[p] = min(treemin[lp], treemin[rp]);
}

int main() {
	int i;
	scanf("%d %d", &n, &m);

	long long ans = 0;

	for (i = 0; i < n; ++i) scanf("%d", a + i);
	for (i = n - 1; i >= 0; --i) b[i] = get_smaller(a[i] - 1), insert_smaller(a[i]), ans += b[i];

	for (i = 0; i < n; ++i) insert(i, a[i], b[i]);
	build_tree();

	memset(treemax, 0, sizeof treemax);
	for (i = 0; i < 1048976; ++i) treemin[i] = {MVAL, 0.0};

	printf("%I64d\n", ans);
	for (i = 0; i < m; ++i) {
		int x;
		scanf("%d", &x);
		--x;
		int pre = get_max(x);
		if (pre >= a[x]) {
			printf("%I64d\n", ans);
			continue;
		}
		insert_max(x, a[x]);
		pair<int, int> it;
		while (true) {
			it = get_min(x, n);
			if (it.first <= a[x]) remove_min(it.second), ans += val[it.second], val[it.second] = 0;
			else break;
		}
		if (it.first != MVAL) ans += val[it.second], val[it.second] = 0;
		long long diff = get_diff(x, pre + 1, a[x]);
		ans -= diff, val[x] = diff;
		if (it.first != MVAL) {
			diff = get_diff(it.second, a[x] + 1, it.first);
			ans -= diff, val[it.second] = diff;
		}
		insert_min(a[x], x);
		printf("%I64d\n", ans);
	}
	return 0;
}
