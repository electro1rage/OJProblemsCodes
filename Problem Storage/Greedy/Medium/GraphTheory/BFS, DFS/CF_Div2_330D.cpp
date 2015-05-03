#include <bits/stdc++.h>
using namespace std;

const int MN = 1005;
const int MVAL = 1000000000;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

char grid[MN][MN];
int dist[MN][MN];
bool vst[MN][MN];

int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	int xs, ys;
	int xe, ye;
	for (int i = 0; i < n; ++i) {
		scanf("%s", grid[i]);
		for (int j = 0; j < m; ++j) {
			dist[i][j] = MVAL;
			if (grid[i][j] == 'S') xs = i, ys = j;
			if (grid[i][j] == 'E') xe = i, ye = j;
		}
	}

	queue<pair<int, int> > q;
	q.push({xe, ye}), vst[xe][ye] = true;

	int level = 0;
	while (!q.empty()) {
		int sz = q.size();
		for (int i = 0; i < sz; ++i) {
			int curx = q.front().first, cury = q.front().second; q.pop();
			for (int j = 0; j < 4; ++j) {
				int nx = curx + dx[j], ny = cury + dy[j];
				if (nx >= 0 && nx < n && ny >= 0 && ny < m && !vst[nx][ny] && grid[nx][ny] != 'T') {
					dist[nx][ny] = level + 1;
					vst[nx][ny] = true;
					q.push({nx, ny});
				}
			}
		}
		++level;
	}


	int ans = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (i == xs && j == ys) continue;
			if (dist[i][j] <= dist[xs][ys]) ans += grid[i][j] - '0';
		}
	}

	printf("%d\n", ans);
	return 0;
}





