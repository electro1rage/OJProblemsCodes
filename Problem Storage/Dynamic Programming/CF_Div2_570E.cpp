#include <bits/stdc++.h>
using namespace std;

const int MN = 505, MOD = 1000000007;

char grid[MN][MN];
int dp[2][MN][MN], n, m;

bool valid(int i, int j) {
	return i >= 0 && i < n && j >= 0 && j < m;
}

bool valid_top(int d, int id) {
	int i = id, j = d - i;
	return valid(i, j);
}

bool valid_bot(int d, int id) {
	int i = id, j = n + m - i - 2 - d;
	return valid(i, j);
}

bool same(int d, int id1, int id2) {
	int i1 = id1, j1 = d - i1;
	int i2 = id2, j2 = n + m - i2 - 2 - d;
	return grid[i1][j1] == grid[i2][j2];
}

int main() {
	int i, j, k;
	scanf("%d %d", &n, &m);

	for (i = 0; i < n; ++i) scanf("%s", grid[i]);

	dp[0][0][n - 1] = grid[0][0] == grid[n - 1][m - 1];
	for (k = 0; k + 1 < (n + m) / 2; ++k) {
		for (i = 0; i < n; ++i) {
			for (j = 0; j < n; ++j) {
				int &cur = dp[k&1][i][j];
				if (!valid_top(k, i) || !valid_bot(k, j)) {
					cur = 0;
					continue;
				}
				int di1 = i, di2 = i + 1;
				int dj1 = j, dj2 = j - 1;

				if (valid_top(k + 1, di1) && valid_bot(k + 1, dj1) && same(k + 1, di1, dj1)) {
					dp[(k+1)&1][di1][dj1] += cur, dp[(k+1)&1][di1][dj1] %= MOD;
				}
				if (valid_top(k + 1, di1) && valid_bot(k + 1, dj2) && same(k + 1, di1, dj2)) {
					dp[(k+1)&1][di1][dj2] += cur, dp[(k+1)&1][di1][dj2] %= MOD;
				}
				if (valid_top(k + 1, di2) && valid_bot(k + 1, dj1) && same(k + 1, di2, dj1)) {
					dp[(k+1)&1][di2][dj1] += cur, dp[(k+1)&1][di2][dj1] %= MOD;
				}
				if (valid_top(k + 1, di2) && valid_bot(k + 1, dj2) && same(k + 1, di2, dj2)) {
					dp[(k+1)&1][di2][dj2] += cur, dp[(k+1)&1][di2][dj2] %= MOD;
				}
				cur = 0;
			}
		}
	}

	int ans = 0;
	k = (n + m) / 2 - 1;
	for (i = 0; i < n; ++i) {
		if (!valid_top(k, i)) continue;
		if ((n + m) % 2 && valid_bot(k, i + 1)) ans = (ans + dp[k&1][i][i + 1]) % MOD;
		if (valid_bot(k, i)) ans = (ans + dp[k&1][i][i]) % MOD;
	}

	printf("%d\n", ans);
	return 0;
}
