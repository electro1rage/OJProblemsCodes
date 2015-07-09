#include <bits/stdc++.h>
using namespace std;

const int MN = 49;

char s[MN][MN];
int good[MN][MN][MN][MN];
int zeros[MN][MN];

bool is_good(int a[MN][MN], int x1, int y1, int x2, int y2) {
	return (a[x2][y2]  - a[x1 - 1][y2] - a[x2][y1 - 1] + a[x1 - 1][y1 - 1] == (x2 - x1 + 1) * (y2 - y1 + 1));
}

void get_sum(int n, int m, int x, int y) {
	int i, j;
	for (i = x; i <= n; ++i) {
		for (j = y; j <= m; ++j) {
			good[x][y][i][j] = good[x][y][i - 1][j] + good[x][y][i][j - 1] - good[x][y][i - 1][j - 1] + good[x][y][i][j];
		}
	}
}


int main() {
	int n, m, q, i, j, k, l;
	scanf("%d %d %d", &n, &m, &q);

	for (i = 1; i <= n; ++i) scanf("%s", s[i] + 1);

	for (i = 1; i <= n; ++i) {
		for (j = 1; j <= m; ++j) zeros[i][j] = zeros[i - 1][j] + zeros[i][j - 1] - zeros[i - 1][j - 1] + (s[i][j] == '0');
	}

	for (i = 1; i <= n; ++i) {
		for (j = 1; j <= m; ++j) {
			for (k = i; k <= n; ++k) {
				for (l = j; l <= m; ++l) good[i][j][k][l] = is_good(zeros, i, j, k, l);
			}
		}
	}

	for (i = 1; i <= n; ++i) {
		for (j = 1; j <= m; ++j) get_sum(n, m, i, j);
	}

	for (i = n; i > 0; --i) {
		for (j = m; j > 0; --j) {
			for (k = 1; k <= n; ++k) {
				for (l = 1; l <= m; ++l)
					good[i][j][k][l] = good[i][j][k][l] + good[i + 1][j][k][l] + good[i][j + 1][k][l] - good[i + 1][j + 1][k][l];
			}
		}
	}


	for (i = 0; i < q; ++i) {
		int x1, y1, x2, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		printf("%d\n", good[x1][y1][x2][y2]);
	}
	return 0;
}
