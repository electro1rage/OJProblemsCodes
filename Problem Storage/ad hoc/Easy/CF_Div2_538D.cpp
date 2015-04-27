#include <bits/stdc++.h>
using namespace std;

const int MAXN = 55;

char grid[MAXN][MAXN], ans[2 * MAXN][2 * MAXN], valid[MAXN][MAXN];

int n, xc, yc;

void get_ans() {
	for (int i = 0; i < 2 * n - 1; ++i) for (int j = 0; j < 2 * n - 1; ++j) ans[i][j] = 'x';
	ans[xc][yc] = 'o';

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (grid[i][j] == 'o') {
				for (int k = 0; k < n; ++k) {
					for (int l = 0; l < n; ++l) {
						if (grid[k][l] == '.') {
							int dx = k - i, dy = l - j;
							ans[xc + dx][yc + dy] = '.';
						}
					}
				}
			}
		}
	}
}

bool is_good() {
	for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) valid[i][j] = '.';
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (grid[i][j] == 'o') {
				for (int k = 0; k < n; ++k) {
					for (int l = 0; l < n; ++l) {
						int dx = k - i, dy = l - j;
						if (ans[xc + dx][yc + dy] == 'x') valid[k][l] = 'x';
					}
				}
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (grid[i][j] == 'x' && valid[i][j] != 'x') return false;
			if (grid[i][j] == '.' && valid[i][j] != '.') return false;
		}
	}

	return true;
}

int main() {
	cin >> n;
	xc = yc = n - 1;

	for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) cin >> grid[i][j];

	get_ans();

	if (!is_good()) {
		puts("NO");
		return 0;
	}

	puts("YES");
	for (int i = 0; i < 2 * n - 1; ++i) {
		for (int j = 0; j < 2 * n - 1; ++j)
			cout << ans[i][j];cout << endl;
	}
	return 0;
}









