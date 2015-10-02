#include <bits/stdc++.h>
using namespace std;

const int MN = 505;

bool vst[MN][MN];
char grid[MN][MN];
int n, m, k;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void dfs(int x, int y) {
	vst[x][y] = true;
	int i;
	for (i = 0; i < 4; ++i) {
		int nx = x + dx[i], ny = y + dy[i];
		if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == '.' && !vst[nx][ny]) {
			dfs(nx, ny);
		}
	}
	if (k) --k, grid[x][y] = 'X';
}

int main() {
	scanf("%d %d %d", &n, &m, &k);
	int i, j;
	for (i = 0; i < n; ++i) scanf("%s", grid[i]);

	for (i = 0; i < n; ++i) {
		for (j = 0; j < m; ++j) if (grid[i][j] == '.') dfs(i, j);
	}

	for (i = 0; i < n; ++i) printf("%s\n", grid[i]);
	return 0;
}
