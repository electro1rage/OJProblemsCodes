#include <bits/stdc++.h>
using namespace std;

const int MN = 1010;

int dx[] = {1, 0, 0, -1, 1, 1, -1, -1};
int dy[] = {0, 1, -1, 0, 1, -1, 1, -1};

char grid[MN][MN], temp[MN][MN];
int n, m;

void flip() {
	int i, j;
	for (i = 0; i < n; ++i) {
		for (j = 0; j < m; ++j) temp[j][n - i - 1] = grid[i][j];
	}

	swap(n, m);

	for (i = 0; i < n; ++i) for (j = 0; j < m; ++j) grid[i][j] = temp[i][j];
}

bool is_good() {
	int i, j, k;

	for (i = 0; i < n; ++i) for (j = 0; j < m; ++j) temp[i][j] = grid[i][j];

	for (i = 0; i < n; ++i) {
		for (j = m - 1; j >= 0; j -= 2) {
			if (grid[i][j] != '0') {
				for (k = j; k >= 0; k -= 2) {
					if (grid[i][k] != '0' && grid[i][k] != grid[i][j]) return false;
					else grid[i][k] = grid[i][j];
				}
				break;
			}
		}
		for (j = m - 2; j >= 0; j -= 2) {
			if (grid[i][j] != '0') {
				for (k = j; k >= 0; k -= 2) {
					if (grid[i][k] != '0' && grid[i][k] != grid[i][j]) return false;
					else grid[i][k] = grid[i][j];
				}
				break;
			}
		}
	}

	bool have[2][5] = {};

	for (i = 0; i < n; ++i) {
		for (j = 0; j < 2; ++j) if (grid[i][j] != '0') have[i % 2][grid[i][j] - '0'] = true;
	}

	for (i = 0; i < 2; ++i) if (count(have[i] + 1, have[i] + 5, true) > 2) return false;

	for (i = 1; i < 5; ++i) if (have[0][i] == true && have[1][i] == have[0][i]) return false;

	for (k = 0; k < 2; ++k)
	for (i = 0; i < 2; ++i) {
		if (count(have[i] + 1, have[i] + 5, true) < 2) {
			for (j = 1; j < 5; ++j) if (!have[i][j] && !have[!i][j]) {have[i][j] = true; break;}
		}
	}

	for (i = 0; i < n; ++i) {
		if (grid[i][0] != '0' && grid[i][0] == grid[i][1]) return false;
		bool t[5] = {};
		for (j = 0; j < 5; ++j) t[j] = have[i % 2][j];
		t[grid[i][0] - '0'] = false, t[grid[i][1] - '0'] = false;

		if (grid[i][0] == '0') for (j = 1; j < 5; ++j) if (t[j]) {
			grid[i][0] = j + '0', t[j] = false;
			break;
		}

		if (grid[i][1] == '0') for (j = 1; j < 5; ++j) if (t[j]) {
			grid[i][1] = j + '0', t[j] = false;
			break;
		}

		for (j = 2; j < m; ++j) {
			grid[i][j] = grid[i][j % 2];
		}
	}

	return true;
}

int main() {
	int i, j, k;
	scanf("%d %d", &n, &m);

	for (i = 0; i < n; ++i) scanf("%s", grid[i]);

	for (i = 0; i < n; ++i) {
		for (j = 0; j < m; ++j) {
			if (grid[i][j] != '0')
			for (k = 0; k < 8; ++k) {
				int nx = i + dx[k], ny = j + dy[k];
				if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == grid[i][j]) {
					puts("0");
					return 0;
				}
			}
		}
	}

	if (is_good()) {
		for (i = 0; i < n; ++i) {
			for (j = 0; j < m; ++j) printf("%c", grid[i][j]);puts("");
		}
		return 0;
	}

	for (i = 0; i < n; ++i) for (j = 0; j < m; ++j) grid[i][j] = temp[i][j];

	flip();
	if (is_good()) {
		flip(), flip(), flip();
		for (i = 0; i < n; ++i) {
			for (j = 0; j < m; ++j) printf("%c", grid[i][j]);puts("");
		}
		return 0;
	}

	puts("0");
	return 0;
}
