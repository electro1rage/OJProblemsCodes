#include <bits/stdc++.h>
using namespace std;

const int MN = 30001, X = 250;

int dp[MN][505], a[MN];

int main() {
	int n, d, x, i, j;
	scanf("%d %d", &n, &d);
	for (i = 0; i < n; ++i) scanf("%d", &x), ++a[x];
	int ans = 0;
	for (i = 0; i < MN; ++i) for (j = 0; j <= 500; ++j) dp[i][j] = -1010101;
	dp[d][X] = 0;
	for (i = d; i < MN; ++i) {
		for (j = -250; j <= 250; ++j) {
			int cur = dp[i][j + X] + a[i];
			if (d + j > 0 && i + d + j < MN) dp[i + d + j][j + X] = max(dp[i + d + j][j + X], cur);
			if (d + j - 1 > 0 && i + d + j - 1 < MN) dp[i + d + j - 1][j - 1 + X] = max(dp[i + d + j - 1][j - 1 + X], cur);
			if (d + j + 1 > 0 && i + d + j + 1 < MN) dp[i + d + j + 1][j + 1 + X] = max(dp[i + d + j + 1][j + 1 + X], cur);
			ans = max(ans, cur);
		}
	}
	printf("%d\n", ans);
	return 0;
}
