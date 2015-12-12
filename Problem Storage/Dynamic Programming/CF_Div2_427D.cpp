/*
reality, be rent!
synapse, break!
Van!shment Th!s World !!
*/
#include <bits/stdc++.h>
using namespace std;

const int MN = 5050;

int dp[MN][MN];

void get_lcp(char a[MN], char b[MN]) {
	int n = strlen(a), m = strlen(b), i, j;
	memset(dp, 0, sizeof dp);
	for (i = n - 1; i >= 0; --i) {
		for (j = m - 1; j >= 0; --j) {
			if (a[i] == b[j]) dp[i][j] = 1 + dp[i + 1][j + 1];
		}
	}
}

char a[MN], b[MN];
int x[MN], y[MN];

int main() {
	int n, m, ans = MN, i, j;
	scanf("%s", a);
	scanf("%s", b);
	n = strlen(a), m = strlen(b);

	get_lcp(a, a);
	for (i = 0; i < n; ++i) x[i] = 1;
	for (i = 0; i < n; ++i) {
		for (j = 0; j < n; ++j) {
			if (i == j) continue;
			x[i] = max(x[i], dp[i][j] + 1);
		}
	}

	get_lcp(b, b);
	for (i = 0; i < m; ++i) y[i] = 1;
	for (i = 0; i < m; ++i) {
		for (j = 0; j < m; ++j) {
			if (i == j) continue;
			y[i] = max(y[i], dp[i][j] + 1);
		}
	}

	get_lcp(a, b);
	for (i = 0; i < n; ++i) {
		for (j = 0; j < m; ++j) {
			if (x[i] > dp[i][j] || y[j] > dp[i][j]) continue;
			ans = min(ans, max(x[i], y[j]));
		}
	}

	if (ans == MN) puts("-1");
	else printf("%d\n", ans);
	return 0;
}
