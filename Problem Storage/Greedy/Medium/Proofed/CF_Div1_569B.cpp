#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007, MN = 4040;

int dp[MN][MN];
vector<vector<int> > b;

int main() {
	int n, i, j;
	scanf("%d", &n);

	b.push_back({1}), b.push_back({1});
	for (i = 2; i <= n; ++i) {
		for (j = 0; j < i; ++j) {
			if (!j) b.push_back({b[i - 1].back()});
			else b[i].push_back((b[i].back() + b[i - 1][j - 1]) % MOD);
		}
	}

	dp[0][0] = 1;
	for (i = 1; i <= n; ++i) {
		for (j = 0; j <= i; ++j) {
			if (!j) dp[i][j] = 1;
			else dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) % MOD;
		}
	}

	int ans = 0;
	for (i = 0; i < n; ++i) ans = (ans + (1LL * dp[n][i] * b[i].back()) % MOD) % MOD;

	printf("%d\n", ans);
	return 0;
}
