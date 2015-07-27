#include <bits/stdc++.h>
using namespace std;

const int MN = 404;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int sum[MN * 2][MN * 2], sumdag[MN * 2][MN * 2];
char grid[MN][MN];

inline bool good(int sum[MN * 2][MN * 2], int x1, int y1, int x2, int y2) {
	if (make_pair(x1, y1) > make_pair(x2, y2)) swap(x1, x2), swap(y1, y2);
	--x1, --y1;
	return sum[x2][y2] - sum[x1][y2] - sum[x2][y1] + sum[x1][y1] == 0;
}

inline bool valid(int x1, int y1, int x2, int y2) {
	if (x1 == x2 || y1 == y2) return good(sum, x1, y1, x2, y2);
	return good(sumdag, x1 + y1, x1 - y1 + MN, x2 + y2, x2 - y2 + MN);
}

inline void get_sum(int sum[MN * 2][MN * 2]) {
	int i, j;
	for (i = 1; i < MN * 2; ++i) {
		for (j = 1; j < MN * 2; ++j) sum[i][j] = sum[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
	}
}

int n, m;

inline bool valid_p(int x, int y) {
	return x > 0 && x <= n && y > 0 && y <= m;
}

inline bool is_good(int x1, int y1, int x2, int y2, int x3, int y3) {
	if (valid_p(x1, y1) && valid_p(x2, y2) && valid_p(x3, y3)) {
		if (valid(x1, y1, x2, y2) && valid(x2, y2, x3, y3) && valid(x3, y3, x1, y1)) return true;
	}
	return false;
}

int main() {
	int i, j, k;
	scanf("%d %d", &n, &m);

	for (i = 1; i <= n; ++i) scanf("%s", grid[i] + 1);

	for (i = 1; i <= n; ++i) {
		for (j = 1; j <= m; ++j) sum[i][j] = grid[i][j] - '0', sumdag[i + j][i - j + MN] = grid[i][j] - '0';
	}

	get_sum(sum), get_sum(sumdag);

	int ans = 0;
	for (k = 1; k < MN - 2; ++k) {
		for (i = 1; i <= n; ++i) {
			for (j = 1; j <= m; ++j) {
				ans += is_good(i, j, i + k * dx[0], j + k * dy[0], i + k * dx[1], j + k * dy[1]);
				ans += is_good(i, j, i + k * dx[2], j + k * dy[2], i + k * dx[1], j + k * dy[1]);
				ans += is_good(i, j, i + k * dx[2], j + k * dy[2], i + k * dx[3], j + k * dy[3]);
				ans += is_good(i, j, i + k * dx[0], j + k * dy[0], i + k * dx[3], j + k * dy[3]);

				ans += is_good(i + k * dx[0], j + k * dy[0], i + k * dx[1], j + k * dy[1], i + k * dx[2], j + k * dy[2]);
				ans += is_good(i + k * dx[3], j + k * dy[3], i + k * dx[1], j + k * dy[1], i + k * dx[2], j + k * dy[2]);
				ans += is_good(i + k * dx[3], j + k * dy[3], i + k * dx[0], j + k * dy[0], i + k * dx[2], j + k * dy[2]);
				ans += is_good(i + k * dx[3], j + k * dy[3], i + k * dx[0], j + k * dy[0], i + k * dx[1], j + k * dy[1]);
			}
		}
	}

	printf("%d\n", ans);
	return 0;
}
