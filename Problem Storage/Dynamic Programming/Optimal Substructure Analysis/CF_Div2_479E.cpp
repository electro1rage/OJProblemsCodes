#include <bits/stdc++.h>
using namespace std;

const int MN = 5050, MOD = 1000000007;

int dp[MN][MN];

int main() {
	int n, a, b, k, i, j;
	scanf("%d %d %d %d", &n, &a, &b, &k);
	dp[a][0] = 1;
	for (i = 1; i <= k; ++i) {
		for (j = 1; j <= n; ++j) dp[j][i - 1] = (dp[j - 1][i - 1] + dp[j][i - 1]) % MOD;
		for (j = 1; j <= n; ++j) {
			if (j == b) continue;
			if (j < b) {
				int diff = (b - j - 1) / 2;
				int up1 = j + 1, up2 = j + diff;
				int dn1 = 1, dn2 = j - 1;
				if (up1 <= up2) {
					dp[j][i] += (dp[up2][i - 1] - dp[up1 - 1][i - 1] + MOD) % MOD, dp[j][i] %= MOD;
				}
				if (dn1 <= dn2) {
					dp[j][i] += (dp[dn2][i - 1] - dp[dn1 - 1][i - 1] + MOD) % MOD, dp[j][i] %= MOD;
				}
			} else {
				int diff = (j - b - 1) / 2;
				int up1 = j + 1, up2 = n;
				int dn1 = j - diff, dn2 = j - 1;
				if (up1 <= up2) {
					dp[j][i] += (dp[up2][i - 1] - dp[up1 - 1][i - 1] + MOD) % MOD, dp[j][i] %= MOD;
				}
				if (dn1 <= dn2) {
					dp[j][i] += (dp[dn2][i - 1] - dp[dn1 - 1][i - 1] + MOD) % MOD, dp[j][i] %= MOD;
				}
			}
		}
	}

	int ans = 0;
	for (i = 1; i <= n; ++i) ans = (ans + dp[i][k]) % MOD;
	printf("%d\n", ans);
	return 0;
}
