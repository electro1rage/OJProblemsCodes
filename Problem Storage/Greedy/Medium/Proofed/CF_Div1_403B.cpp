/*
reality, be rent!
synapse, break!
Van!shment Th!s World !!
*/
#include <bits/stdc++.h>
using namespace std;

int b[5050];
int a[5050];
int g[5050];
int n, m;
map<int, int> xm;

int get_change(int x) {
	if (xm.count(x)) return xm[x];
	int ret = 0, tx = x, i;
	for (i = 2; 1LL * i * i <= x; ++i) {
		while (x % i == 0) {
			if (*lower_bound(b, b + m, i) == i) --ret;
			else ++ret;
			x /= i;
		}
	}
	if (x > 1) {
		if (*lower_bound(b, b + m, x) == x) --ret;
		else ++ret;
	}
	return xm[tx] = ret;
}

int main() {
	int i;
	scanf("%d %d", &n, &m);
	for (i = 0; i < n; ++i) scanf("%d", a + i);
	for (i = 0; i < m; ++i) scanf("%d", b + i);

	int ans = 0;
	for (i = 0; i < n; ++i) ans += get_change(a[i]);

	g[0] = a[0];
	for (i = 1; i < n; ++i) {
		g[i] = __gcd(g[i - 1], a[i]);
	}

	int mul = 1;
	for (i = n - 1; i >= 0; --i) {
		int change = get_change(g[i] / mul);
		if (change < 0) {
			ans -= change * (i + 1);
			mul = g[i];
		}
	}

	printf("%d\n", ans);
	return 0;
}
