#include <bits/stdc++.h>
using namespace std;

const int MN = 2020;

char grid[MN][MN];
bool vst[MN][MN];
bool on[MN][MN];
int dp[MN][MN];

int dx(char c) {
	if (c == '^') return -1;
	if (c == 'v') return 1;
	return 0;
}

int dy(char c) {
	if (c == '>') return 1;
	if (c == '<') return -1;
	return 0;
}

bool dfs(int x, int y) {
	if (vst[x][y] || grid[x][y] == '#') return false;
	vst[x][y] = on[x][y] = true;
	char c = grid[x][y];
	if (on[x + dx(c)][y + dy(c)]) return true;
	bool ret = dfs(x + dx(c), y + dy(c));
	on[x][y] = false;
	return ret;
}

int get_len(int x, int y) {
	if (grid[x][y] == '#') return dp[x][y] = 0;
	if (dp[x][y] == -1) {
		char c = grid[x][y];
		dp[x][y] = 1 + get_len(x + dx(c), y + dy(c));
	}
	return dp[x][y];
}

bool is_good(int x, int y) {
	if (grid[x][y] == '#') return true;
	if (vst[x][y]) return false;
	vst[x][y] = true;
	char c = grid[x][y];
	return is_good(x + dx(c), y + dy(c));
}

int main() {
	int n, m, i, j;
	scanf("%d %d", &n, &m);
	for (i = 0; i < n; ++i) scanf("%s", grid[i]);
	for (i = 0; i < n; ++i) {
		for (j = 0; j < m; ++j) {
			if (!vst[i][j] && dfs(i, j)) {
				puts("-1");
				return 0;
			}
		}
	}

	memset(dp, -1, sizeof dp);
	int maxi = 0;
	for (i = 0; i < n; ++i) {
		for (j = 0; j < m; ++j) maxi = max(maxi, get_len(i, j));
	}

	memset(vst, 0, sizeof vst);
	int ctr = 0;
	for (i = 0; i < n; ++i) {
		for (j = 0; j < m; ++j) {
			if (dp[i][j] == maxi) ctr += is_good(i, j);
		}
	}

	if (ctr > 1) printf("%d\n", maxi * 2);
	else printf("%d\n", max(0, maxi * 2 - 1));
	return 0;
}
