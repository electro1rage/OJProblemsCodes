/*
reality, be rent!
synapse, break!
Van!shment Th!s World !!
*/
#include <bits/stdc++.h>
using namespace std;

const int MN = 1010;

int a[MN][MN], x[MN][MN], y[MN][MN], z[MN][MN], c[MN][MN];

int main() {
	int n, m, i, j;
	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; ++i) {
		for (j = 1; j <= m; ++j) scanf("%d", &a[i][j]);
	}

	for (i = 1; i <= n; ++i) {
		for (j = 1; j <= m; ++j) {
			x[i][j] = a[i][j] + max(x[i - 1][j], x[i][j - 1]);
		}
	}

	for (i = 1; i <= n; ++i) {
		for (j = m; j > 0; --j) {
			y[i][j] = a[i][j] + max(y[i - 1][j], y[i][j + 1]);
		}
	}

	for (i = n; i > 0; --i) {
		for (j = 1; j <= m; ++j) {
			z[i][j] = a[i][j] + max(z[i + 1][j], z[i][j - 1]);
		}
	}

	for (i = n; i > 0; --i) {
		for (j = m; j > 0; --j) {
			c[i][j] = a[i][j] + max(c[i + 1][j], c[i][j + 1]);
		}
	}

	int ans = 0;
	for (i = 2; i < n; ++i) {
		for (j = 2; j < m; ++j) {
			ans = max(ans, x[i - 1][j] + c[i + 1][j] + y[i][j + 1] + z[i][j - 1]);
			ans = max(ans, x[i][j - 1] + c[i][j + 1] + y[i - 1][j] + z[i + 1][j]);
		}
	}

	printf("%d\n", ans);
	return 0;
}
