/*
reality, be rent!
synapse, break!
Van!shment Th!s World !!
*/
#include <bits/stdc++.h>
using namespace std;

const int MN = 1010101, MOD = 1000000007;

char s[MN];
int dp[2][5], a[MN];
bool good[4][5][4];

int main() {
	scanf("%s", s);
	int n = strlen(s), i, j, k;
	map<char, int> cm;
	cm['?'] = 4, cm['*'] = 3, cm['2'] = 2, cm['1'] = 1, cm['0'] = 0;
	for (i = 0; i < n; ++i) a[i] = cm[s[i]];
	good[0][0][0] = true;
	good[3][1][0] = good[0][1][1] = true;
	good[3][2][1] = true;
	good[1][3][3] = good[3][3][3] = true;
	good[0][4][0] = good[0][4][1] = good[1][4][3] = good[3][4][3] = good[3][4][0] = good[3][4][1] = true;

	dp[1 & 1][a[0]] = 1;
	if (a[0] == 4) dp[1&1][4] = 0, dp[1&1][0] = dp[1&1][1] = dp[1&1][3] = 1;
	for (i = 1; i < n; ++i) {
		for (j = 0; j < 4; ++j) {
			for (k = 0; k < 4; ++k) {
				if (!good[j][a[i]][k]) continue;
				dp[(i + 1) & 1][k] = (dp[(i + 1) & 1][k] + dp[i&1][j]) % MOD;
			}
			dp[i&1][j] = 0;
		}
	}

	int ans = 0;
	ans = (ans + dp[n & 1][0]) % MOD;
	ans = (ans + dp[n & 1][3]) % MOD;

	printf("%d\n", ans);
	return 0;
}
