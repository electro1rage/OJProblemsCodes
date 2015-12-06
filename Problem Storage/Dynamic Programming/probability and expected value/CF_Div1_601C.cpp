/*
reality, be rent!
synapse, break!
Van!shment Th!s World !!
*/
#include <bits/stdc++.h>
using namespace std;

int a[101];
double dp[101][100005];

double get_sum(int i, int l, int r) {
	if (r < 0) return 0;
	l = max(l, 0);
	if (l == 0) return dp[i][r];
	return dp[i][r] - dp[i][l - 1];
}

int main() {
	int n, m, sum = 0, i, j;
	scanf("%d %d", &n, &m);

	for (i = 0; i < n; ++i) scanf("%d", a + i), sum += a[i];
	if (m == 1) {
		puts("1");
		return 0;
	}

	for (i = 0; i <= n * m; ++i) dp[0][i] = 0;
	dp[0][0] = m - 1;

	for (i = 1; i <= n; ++i) {
		for (j = 1; j <= n * m; ++j) dp[i - 1][j] += dp[i - 1][j - 1];
		for (j = 1; j <= n * m; ++j) {
			double take = 0;
			if (j - a[i - 1] >= j - m && j - a[i - 1] <= j - 1) take = get_sum(i - 1, j - a[i - 1], j - a[i - 1]);
			dp[i][j] = (get_sum(i - 1, j - m, j - 1) - take) / ((double)m - 1);
		}
	}

	double ans = 0;
	for (i = 0; i < sum; ++i) ans += dp[n][i];
	printf("%.10lf\n", ans + 1);

	return 0;
}
