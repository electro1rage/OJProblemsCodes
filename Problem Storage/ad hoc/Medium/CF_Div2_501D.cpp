#include <bits/stdc++.h>
using namespace std;

const int MN = 202020;

int tree[MN];

void add(int x, int val) {
	++x;
	for (; x < MN; x += (x & -x)) tree[x] += val;
}

int get_val(int x) {
	++x;
	int ret = 0;
	for (; x > 0; x -= (x & -x)) ret += tree[x];
	return ret;
}

int get_kth(int x) {
	++x;
	int ret = -5;
	int s = 0, e = MN - 100, mid;
	while (s <= e) {
		mid = (s + e) / 2;
		if (get_val(mid) >= x) ret = mid, e = mid - 1;
		else s = mid + 1;
	}
	return ret;
}

int a[MN], b[MN], c[MN], d[MN], e[MN];

int main() {
	int n, i;
	scanf("%d", &n);
	for (i = 0; i < n; ++i) scanf("%d", a + i);
	for (i = 0; i < n; ++i) scanf("%d", b + i);

	for (i = 0; i < n; ++i) add(i, 1);
	for (i = 0; i < n; ++i) {
		c[i] = get_val(a[i] - 1);
		add(a[i], -1);
	}
	for (i = 0; i < n; ++i) add(i, 1);
	for (i = 0; i < n; ++i) {
		d[i] = get_val(b[i] - 1);
		add(b[i], -1);
	}

	for (i = n - 1; i >= 0; --i) {
		e[i] += d[i] + c[i];
		if (e[i] >= n - i) {
			e[i] -= n - i;
			if (i) ++e[i - 1];
		}
	}

	for (i = 0; i < n; ++i) add(i, 1);

	for (i = 0; i < n; ++i) {
		int x = get_kth(e[i]);
		add(x, -1);
		if (i) putchar(' ');
		printf("%d", x);
	}
	puts("");
	return 0;
}
