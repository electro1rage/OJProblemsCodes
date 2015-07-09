#include <bits/stdc++.h>
using namespace std;

const int MN = 1010, MVAL = 101010101;

int dx[] = {1, 0, 0, -1};
int dy[] = {0, 1, -1, 0};

char s[] = "DIMA";

int dp[MN][MN];
char grid[MN][MN];
int n, m;

int get_ans(int x, int y, int p) {
	if (dp[x][y] == -2) return MVAL;
	if (dp[x][y] != -1) return dp[x][y];

	dp[x][y] = -2;
	int maxi = 0, i, j = (p + 1) % 4;
	for (i = 0; i < 4; ++i) {
		int nx = x + dx[i], ny = y + dy[i];
		if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == s[j]) {
			maxi = max(maxi, get_ans(nx, ny, j));
		}
	}
	dp[x][y] = maxi + (p == 3);
	return dp[x][y];
}

int main() {
	int i, j;
	scanf("%d %d", &n, &m);

	for (i = 0; i < n; ++i) scanf("%s", grid[i]);

	int ans = 0;
	memset(dp, -1, sizeof dp);
	for (i = 0; i < n; ++i) {
		for (j = 0; j < m; ++j) {
			if (grid[i][j] == 'D') ans = max(ans, get_ans(i, j, 0));
		}
	}

	if (ans >= MVAL) {
		puts("Poor Inna!");
		return 0;
	}

	if (ans == 0) {
		puts("Poor Dima!");
		return 0;
	}

	printf("%d\n", ans);
	return 0;
}
