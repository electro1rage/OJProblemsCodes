#include <cstdio>
#include <iostream>

const int MN = 202020;

int a[MN], b[MN], next[MN];
int n;

int find(int i, int rem) {
	if (i == n) return i;
	int nrem = b[i] + rem - a[i];
	b[i] = std::min(a[i], b[i] + rem);

	if (nrem <= 0) return i;
	return next[i] = find(next[i], nrem);
}

int main() {
	int m, i;
	scanf("%d", &n);

	for (i = 0; i < n; ++i) scanf("%d", a + i);
	for (i = 0; i < n; ++i) next[i] = i + 1;

	scanf("%d", &m);
	for (i = 0; i < m; ++i) {
		int k;
		scanf("%d", &k);
		if (k == 1) {
			int p, x;
			scanf("%d %d", &p, &x);
			--p;
			find(p, x);
		} else {
			int p;
			scanf("%d", &p);
			--p;
			printf("%d\n", b[p]);
		}
	}

	return 0;
}
