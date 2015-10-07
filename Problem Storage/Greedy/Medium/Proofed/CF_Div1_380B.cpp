#include <bits/stdc++.h>
using namespace std;

const int MN = 7001;

int get_count(int x) {
	int i;
	for (i = 0; (1 << i) <= x; ++i);
	return i;
}

int get_l(int x) {
	int ret = get_count(x - 1);
	ret += x - 1;
	return ret + 1;
}

int get_r(int x) {
	int ret = get_count(x - 1);
	ret += x - 1;
	if (__builtin_popcount(x) != 1) return ret + 1;
	return ret + 2;
}

struct data {
	int s, e, val;
};

int cnt[MN], vst[1000001];
vector<data> a[MN];

int main() {
	int n, m, op, t, l, r, x, i, j, k;
	scanf("%d %d", &n, &m);
	for (i = 0; i < m; ++i) {
		scanf("%d", &op);
		if (op == 2) {
			scanf("%d %d", &t, &x);
			int ln = x, rn = x, ans = 0, sz;
			for (j = t; j <= n; ++j) {
				sz = a[j].size();
				for (k = 0; k < sz; ++k) {
					bool A = a[j][k].s <= ln && ln <= a[j][k].e;
					bool B = a[j][k].s <= rn && rn <= a[j][k].e;
					bool C = ln <= a[j][k].s && a[j][k].e <= rn;
					if ((A || B || C) && vst[a[j][k].val] != i + 1) ++ans, vst[a[j][k].val] = i + 1;
				}
				ln = get_l(ln), rn = get_r(rn);
			}
			printf("%d\n", ans);
		} else {
			scanf("%d %d %d %d", &t, &l, &r, &x);
			a[t].push_back({l, r, x});
		}
	}

	return 0;
}
