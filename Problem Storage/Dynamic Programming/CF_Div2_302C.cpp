#include <bits/stdc++.h>
using namespace std;

const int MAXN = 205;
const int MAXVAL = 1000000000;

int a[MAXN];
int dp[MAXN][MAXN * MAXN];

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < 2 * n - 1; ++i) scanf("%d", a + i);

	for (int i = 0; i < MAXN; ++i) for (int j = 0; j < MAXN * MAXN; ++j) dp[i][j] = -MAXVAL;

	dp[0][0] = 0;
	for (int i = 0; i < 2 * n - 1; ++i) {
		for (int j = 0; j < 2 * n * n; ++j) {
			dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + a[i]);
			dp[i + 1][j + n - 1] = max(dp[i + 1][j + n - 1], dp[i][j] - a[i]);
			if (j) dp[i + 1][j - 1] = max(dp[i + 1][j - 1], dp[i][j] - a[i]);
		}
	}

	int ans = -MAXVAL;
	for (int i = 0; i < 2 * n * n; i += 2) ans = max(ans, dp[2 * n - 1][i]);

	printf("%d\n", ans);
	return 0;
}






