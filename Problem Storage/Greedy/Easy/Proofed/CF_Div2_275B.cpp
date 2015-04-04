#include <bits/stdc++.h>
using namespace std;

int n, m;
char grid[55][55];
int sum[55][55];

bool all_black(int x1, int y1, int x2, int y2) {
	if (x1 > x2) {
		swap(x1, x2);
		swap(y1, y2);
	}
	if (y1 > y2) {
		swap(x1, x2);
		swap(y1, y2);
	}

	++x1, ++y1, ++x2, ++y2;

	int count = abs(x1 - x2) + abs(y1 - y2) + 1;
	int realcount = sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1];

	if (realcount != count) return false;

	return true;
}



int main() {
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> grid[i][j];

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + (grid[i - 1][j - 1] == 'B');
		}
	}

	for (int x1 = 0; x1 < n; ++x1) {
		for (int y1 = 0; y1 < m; ++y1) {
			for (int x2 = 0; x2 < n; ++x2) {
				for (int y2 = 0; y2 < m; ++y2) {
					if (grid[x1][y1] == 'B' && grid[x2][y2] == 'B') {
						if ((all_black(x1, y1, x2, y1) && all_black(x2, y1, x2, y2)) || (all_black(x1, y1, x1, y2) && all_black(x2, y2, x1, y2))) continue;
						cout << "NO" << endl;
						return 0;
					}
				}
			}
		}
	}

	cout << "YES" << endl;
	return 0;
}




