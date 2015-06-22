#include <bits/stdc++.h>
using namespace std;

const int MN = 2020;

int sum[MN][MN];
char grid[MN][MN];
char ngrid[MN][MN];

int get_sum(int x1, int y1, int x2, int y2) {
	if (x1 > x2 || y1 > y2) return 0;
	return sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1];
}

void paint(int x1, int y1, int x2, int y2) {
	int i, j;
	for (i = min(x1, x2); i <= max(x1, x2); ++i) {
		for (j = min(y1, y2); j <= max(y1, y2); ++j) {
			if (grid[i][j] != 'w') grid[i][j] = '+';
		}
	}
}

bool is_good(int n, int m) {
	int x1 = -1, i, j;
	for (i = 1; i <= n; ++i) {
		for (j = 1; j <= m; ++j) {
			if (grid[i][j] == 'w') x1 = i;
		}
		if (x1 != -1) break;
	}

	for (i = 1; i <= n; ++i) {
		for (j = 1; j <= m; ++j)
		sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + (grid[i][j] == 'w');
	}

	int sum1;
	for (i = 0; i < MN - 5; ++i) {
		for (j = 1; j <= m; ++j) {
			int y1 = j, x2 = x1 + i, y2 = j + i;
			if (x2 > n || y2 > m) continue;
			sum1 = get_sum(x1, y1, x2, y2);
			sum1 -= get_sum(x1 + 1, y1 + 1, x2 - 1, y2 - 1);
			if (sum1 == sum[n][m]) {
				paint(x1, y1, x1, y2);
				paint(x1, y2, x2, y2);
				paint(x2, y2, x2, y1);
				paint(x2, y1, x1, y1);
				return true;
			}
		}
	}
	return false;
}

void flip(int &n, int &m) {
	int i, j;
	for (i = 1; i <= n; ++i) {
		for (j = 1; j <= m; ++j) ngrid[m - j + 1][i] = grid[i][j];
	}
	swap(n, m);
	for (i = 1; i <= n; ++i)
		for (j = 1; j <= m; ++j) grid[i][j] = ngrid[i][j];
}

int main() {
	int n, m, i, j;

	scanf("%d %d", &n, &m);

	for (i = 1; i <= n; ++i) scanf("%s", grid[i] + 1);

	if (is_good(n, m)) {
		for (i = 1; i <= n; ++i) printf("%s\n", grid[i] + 1);
		return 0;
	}

	flip(n, m);

	if (is_good(n, m)) {
		flip(n, m), flip(n, m), flip(n, m);
		for (i = 1; i <= n; ++i) {
			for (j = 1; j <= m; ++j) putchar(grid[i][j]);puts("");
		}
		return 0;
	}

	puts("-1");
	return 0;
}
