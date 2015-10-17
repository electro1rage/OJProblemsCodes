/*
reality, be rent!
synapse, break!
Van!shment Th!s World !!
*/
#include <bits/stdc++.h>
using namespace std;

const int MN = 1001, MM = 10002, MOD = 1000000007;

int dp[MN][MM + MM];
int a[MN];

int main() {
	int n, i, j;
	scanf("%d", &n);
	for (i = 1; i <= n; ++i) scanf("%d", a + i);
	for (i = 0; i <= n; ++i) dp[i][MM] = 1;
	for (i = 1; i <= n; ++i) {
		for (j = 0; j < MM + MM; ++j) {
			if (j + a[i] < MM + MM) dp[i][j + a[i]] = (dp[i][j + a[i]] + dp[i - 1][j]) % MOD;
			if (j - a[i] >= 0) dp[i][j - a[i]] = (dp[i][j - a[i]] + dp[i - 1][j]) % MOD;
		}
	}
	int ans = 0;
	for (i = 1; i <= n; ++i) ans = (ans + (dp[i][MM] - 1 + MOD) % MOD) % MOD;
	printf("%d\n", ans);
	return 0;
}
