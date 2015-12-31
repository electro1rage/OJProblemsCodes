/*
reality, be rent!
synapse, break!
Van!shment Th!s World !!
*/
#include <bits/stdc++.h>
using namespace std;

const int MN = 505;

char grid[MN][MN];
int sum[MN][MN];

bool can_right(int x1, int y1) {
	if (grid[x1][y1] == '.' && grid[x1][y1 + 1] == '.') return true;
	return false;
}

bool can_bot(int x1, int y1) {
	if (grid[x1][y1] == '.' && grid[x1 + 1][y1] == '.') return true;
	return false;
}

int main() {
	int n, m, q, i, j, x1, y1, x2, y2;
	scanf("%d %d", &n, &m);

	for (i = 0; i <= n + 1; ++i) {
		for (j = 0; j <= m + 1; ++j) grid[i][j] = '#';
	}

	for (i = 1; i <= n; ++i) scanf("%s", grid[i] + 1);
	for (i = 1; i <= n; ++i) {
		for (j = 1; j <= m; ++j) sum[i][j] = can_bot(i, j) + can_right(i, j);
	}

	for (i = n; i > 0; --i) {
		for (j = m; j > 0; --j) sum[i][j] += sum[i + 1][j] + sum[i][j + 1] - sum[i + 1][j + 1];
	}

	scanf("%d", &q);
	for (i = 0; i < q; ++i) {
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		int ans = sum[x1][y1] - sum[x2 + 1][y1] - sum[x1][y2 + 1] + sum[x2 + 1][y2 + 1];
		for (j = x1; j <= x2; ++j) if (can_right(j, y2)) --ans;
		for (j = y1; j <= y2; ++j) if (can_bot(x2, j)) --ans;
		printf("%d\n", ans);
	}
	return 0;
}
