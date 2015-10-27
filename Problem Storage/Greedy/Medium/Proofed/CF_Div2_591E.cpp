/*
reality, be rent!
synapse, break!
Van!shment Th!s World !!
*/
#include <bits/stdc++.h>
using namespace std;

const int MN = 1010, MVAL = 1010101010;

char grid[MN][MN];
int n, m;
bool vst[MN][MN];
int dx[] = {1, 0, 0, -1};
int dy[] = {0, 1, -1, 0};

int cost[4][MN][MN];
int dist[4][4];

void dfs_flood(int x, int y) {
	vst[x][y] = true;
	int i;
	for (i = 0; i < 4; ++i) {
		int nx = x + dx[i], ny = y + dy[i];
		if (nx >= 0 && nx < n && ny >= 0 && ny < m && !vst[nx][ny] && grid[nx][ny] != '#') dfs_flood(nx, ny);
	}
}

void bfs(vector<pair<int, int> > &a, int state) {
	memset(vst, 0, sizeof vst);
	queue<pair<int, int> > q;
	int level = 0, sz, i, j;
	for (i = 0; i < n; ++i) {
		for (j = 0; j < m; ++j) {
			if (grid[i][j] == state + '0') cost[state][i][j] = 0, vst[i][j] = true;
			else cost[state][i][j] = MVAL;
		}
	}
	for (auto &x : a) q.push(x);

	while (!q.empty()) {
		sz = q.size();
		while (sz--) {
			int x = q.front().first, y = q.front().second; q.pop();
			for (i = 0; i < 4; ++i) {
				int nx = x + dx[i], ny = y + dy[i];
				if (nx >= 0 && nx < n && ny >= 0 && ny < m && !vst[nx][ny] && grid[nx][ny] != '#') {
					vst[nx][ny] = true;
					cost[state][nx][ny] = level + 1;
					q.push({nx, ny});
				}
			}
		}
		++level;
	}
}

void get_dist(int x, int y) {
	int i, j;
	for (i = 0; i < n; ++i) {
		for (j = 0; j < m; ++j) {
			if (grid[i][j] == y + '0') dist[x][y] = min(dist[x][y], cost[x][i][j]);
		}
	}
}

int main() {
	scanf("%d %d", &n, &m);
	int i, j;
	for (i = 0; i < n; ++i) scanf("%s", grid[i]);

	for (i = 0; i < n; ++i) {
		for (j = 0; j < m; ++j) {
			if (grid[i][j] == '1') {
				dfs_flood(i, j);
				goto END;
			}
		}
	}

	END:;

	for (i = 0; i < n; ++i) {
		for (j = 0; j < m; ++j) {
			if (grid[i][j] >= '1' && grid[i][j] <= '3' && !vst[i][j]) {
				puts("-1");
				return 0;
			}
		}
	}


	for (i = 1; i <= 3; ++i) for (j = 1; j <= 3; ++j) dist[i][j] = MVAL;

	vector<pair<int, int> > a;
	for (i = 0; i < n; ++i) {
		for (j = 0; j < m; ++j) {
			if (grid[i][j] == '1') a.push_back({i, j});
		}
	}
	bfs(a, 1);
	a.clear();

	for (i = 0; i < n; ++i) {
		for (j = 0; j < m; ++j) {
			if (grid[i][j] == '2') a.push_back({i, j});
		}
	}
	bfs(a, 2);
	a.clear();

	for (i = 0; i < n; ++i) {
		for (j = 0; j < m; ++j) {
			if (grid[i][j] == '3') a.push_back({i, j});
		}
	}
	bfs(a, 3);
	a.clear();

	for (i = 1; i <= 3; ++i) {
		for (j = 1; j <= 3; ++j) {
			get_dist(i, j);
		}
	}

	int ans = MVAL, sum;
	for (i = 1; i <= 3; ++i) {
		sum = 0;
		for (j = 1; j <= 3; ++j) {
			if (i == j) continue;
			sum += dist[i][j] - 1;
		}
		ans = min(ans, sum);
	}

	memset(vst, 0, sizeof vst);
	for (i = 0; i < n; ++i) {
		for (j = 0; j < m; ++j) {
			if (grid[i][j] == '1') {
				dfs_flood(i, j);
				goto END4;
			}
		}
	}
	END4:;

	for (i = 0; i < n; ++i) {
		for (j = 0; j < m; ++j) {
			if (vst[i][j] && grid[i][j] == '.') {
				ans = min(ans, cost[1][i][j] + cost[2][i][j] + cost[3][i][j] - 2);
			}
		}
	}

	printf("%d\n", ans);
	return 0;
}
