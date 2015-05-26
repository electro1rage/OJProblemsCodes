#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for((i)=0;(i)<(int)(n);++(i))

const int MN = 300010;

int node[MN * 19];
int lazy[MN * 19];
int a[MN], b[MN], x[MN];
int l, r;
int n;

void insert(int val, int s = 0, int e = n, int p = 1) {
	if (l <= s && e <= r) {
		node[p] = val;
		if (s != e) lazy[2 * p] = lazy[2 * p + 1] = val;
		lazy[p] = 0;
		return ;
	}

	if (lazy[p]) node[p] = lazy[2 * p] = lazy[2 * p + 1] = lazy[p], lazy[p] = 0;

	int mid = (s + e) / 2;

	if (r <= mid) insert(val, s, mid, 2 * p);
	else if (l > mid) insert(val, mid + 1, e, 2 * p + 1);
	else {
		insert(val, s, mid, 2 * p);
		insert(val, mid + 1, e, 2 * p + 1);
	}

}

int query(int pos, int s = 0, int e = n, int p = 1) {
	if (s == e) {
		if (lazy[p]) node[p] = lazy[p], lazy[p] = 0;
		return node[p];
	}

	if (lazy[p]) node[p] = lazy[2 * p] = lazy[2 * p + 1] = lazy[p], lazy[p] = 0;

	int mid = (s + e) / 2;

	if (pos <= mid) return query(pos, s, mid, 2 * p);
	return query(pos, mid + 1, e, 2 * p + 1);
}

int main() {
	int m;
	scanf("%d %d", &n, &m);

	int i;
	REP(i, m) scanf("%d %d %d", a + i, b + i, x + i);
	for (i = m - 1; i >= 0; --i) {
		if (x[i] != b[i]) {
			l = x[i] + 1, r = b[i];
			insert(x[i]);
		}
		if (x[i] != a[i]) {
			l = a[i], r = x[i] - 1;
			insert(x[i]);
		}
	}

	REP(i, n + 1) if (i) printf("%d ", query(i));puts("");
	return 0;
}
