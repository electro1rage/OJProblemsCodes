#include <bits/stdc++.h>
using namespace std;

#define F 0
#define S 1
#define D 2

#define REP(i,n) for((i)=0;(i)<(int)(n);++(i))

const int MN = 20;
const int MVAL = 1000000000;

int dp[2 * MN][1 << MN];
char grid[MN][MN];
int a[2 * MN][26];
int n;

int dfs(int d, int mask) {
	if (dp[d][mask] != MVAL) return dp[d][mask];

	int ans = 0, i;
	REP(i, n) {
		if ((mask >> i) & 1) {
			if (grid[i][d - i] == 'a') ++ans;
			if (grid[i][d - i] == 'b') --ans;
			break;
		}
	}

	if (d == 2 * n - 2) return dp[d][mask] = ans;

	if (d % 2) {
		dp[d][mask] = -MVAL;
		REP(i, 26) {
			int nmask = a[d + 1][i] & (mask | (mask << 1));

			if (nmask == 0) continue;

			dp[d][mask] = max(dp[d][mask], dfs(d + 1, nmask) + ans);
		}
	} else {
		REP(i, 26) {
			int nmask = a[d + 1][i] & (mask | (mask << 1));

			if (nmask == 0) continue;

			dp[d][mask] = min(dp[d][mask], dfs(d + 1, nmask) + ans);
		}
	}

	return dp[d][mask];
}

int main() {
	int i, j;
	scanf("%d", &n);

	REP(i, n) scanf("%s", grid[i]);

	REP(i, 2 * n) REP(j, n) {
		if (i - j < 0 || i - j >= n) continue;
		a[i][grid[j][i - j] - 'a'] |= 1 << j;
	}

	REP(i, 2 * n) REP(j, 1 << n) dp[i][j] = MVAL;

	dfs(0, 1);

	if (dp[0][1] > 0) puts("FIRST");
	else if (dp[0][1] < 0) puts("SECOND");
	else puts("DRAW");
	return 0;
}
