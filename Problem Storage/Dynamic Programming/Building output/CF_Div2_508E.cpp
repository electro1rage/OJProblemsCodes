#include <bits/stdc++.h>
using namespace std;

const int MN = 606;

int dp[MN][MN];
int l[MN], r[MN], n;
char ans[MN * 2];

bool dfs(int i, int rem, int pos) {
	if (rem == 0) return true;
	if (i == n) return dp[i][rem] = false;
	if (dp[i][rem] != -1) return dp[i][rem];
	int j;
	for (j = l[i] + !(l[i]&1); j <= r[i]; j += 2) {
		int nrem = j / 2;
		if (rem - nrem - 1 < 0 || i + nrem + 1 > n) continue;
		if (dfs(i + 1, nrem, pos + 1) && dfs(i + nrem + 1, rem - nrem - 1, pos + 2 * nrem + 2)) {
			return dp[i][rem] = true;
		}
	}
	return dp[i][rem] = false;
}

void build(int i, int rem, int pos) {
	int j;
	for (j = l[i] + !(l[i]&1); j <= r[i]; j += 2) {
		int nrem = j / 2;
		if (rem - nrem - 1 < 0 || i + nrem + 1 > n) continue;
		if (dfs(i + 1, nrem, pos + 1) && dfs(i + nrem + 1, rem - nrem - 1, pos + 2 * nrem + 2)) {
			ans[pos] = '(', ans[pos + 2 * nrem + 1] = ')';
			build(i + 1, nrem, pos + 1), build(i + nrem + 1, rem - nrem - 1, pos + 2 * nrem + 2);
			return ;
		}
	}
}

int main() {
	scanf("%d", &n);
	int i;
	for (i = 0; i < n; ++i) scanf("%d %d", l + i, r + i);
	memset(dp, -1, sizeof dp);
	if (!dfs(0, n, 0)) puts("IMPOSSIBLE");
	else build(0, n, 0), printf("%s\n", ans);
	return 0;
}
