#include <bits/stdc++.h>
using namespace std;

const int MN = 503;

int MOD;
int dp[2][MN][MN];
int a[MN];
int n, m, b;

int main() {
	scanf("%d %d %d %d", &n, &m, &b, &MOD);

	for (int i = 0; i < n; ++i) scanf("%d", a + i);

	int ans = 0;

	dp[0 & 1][0][0] = 1;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j <= m; ++j) {
			for (int k = 0; k <= b; ++k) {
				int cur = dp[i & 1][j][k];

				dp[i & 1][j][k] = 0;

				dp[(i + 1) & 1][j][k] = (cur + dp[(i + 1) & 1][j][k]) % MOD;
				if (k + a[i] <= b && j + 1 <= m) dp[i & 1][j + 1][k + a[i]] = (cur + dp[i & 1][j + 1][k + a[i]]) % MOD;
			}
		}
	}

	for (int k = 0; k <= b; ++k) ans = (ans + dp[n & 1][m][k]) % MOD;

	printf("%d\n", ans);
	return 0;
}
