#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for((i)=0;(i)<(int)(n);++(i))

const int MN = 2020;
const int MOD = 1000000007;

int dp[MN][MN];
int sum[MN][MN];
char s[MN];

int main() {
	int n, k;
	scanf("%d %d", &n, &k);

	scanf("%s", s);

	dp[0][0] = 1;
	sum[0][0] = 1;

	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j <= k; ++j) {
			dp[i][j] += 1LL * sum[i - 1][j] * (s[i - 1] - 'a') % MOD;
			dp[i][j] %= MOD;

			for (int pre = 1; i - pre >= 0; ++pre) {
				if (j - pre * (n - i + 1) < 0) break;
				dp[i][j] += 1LL * dp[i - pre][j - pre * (n - i + 1)] * ('z' - s[i - 1]) % MOD;
				dp[i][j] %= MOD;
			}

			sum[i][j] += (dp[i][j] + sum[i - 1][j]) % MOD;
			sum[i][j] %= MOD;
		}
	}

	int ans = 0;
	for (int i = 0; i <= n; ++i) ans = (ans + dp[i][k]) % MOD;

	printf("%d\n", ans);
	return 0;
}
