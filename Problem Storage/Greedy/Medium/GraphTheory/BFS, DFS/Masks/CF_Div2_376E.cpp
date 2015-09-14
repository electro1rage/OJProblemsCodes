#include <bits/stdc++.h>
using namespace std;

const int MN = 22, MVAL = 1010101010;

int n, m, o;
char grid[MN][MN];
int dx[] = {1, 0, 0, -1};
int dy[] = {0, 1, -1, 0};
vector<int> ox, oy;
vector<int> val;
int vst[MN][MN][1 << 8][1 << 8];

struct state {
	int x, y, mask1, mask2;
};

void bfs(int xs, int ys) {
	queue<state> q;
	int level = 0, sz, i, j, k;
	memset(vst, -1, sizeof vst);
	q.push({xs, ys, 0}), vst[xs][ys][0][0] = 0;
	while (!q.empty()) {
		sz = q.size();
		for (i = 0; i < sz; ++i) {
			int x = q.front().x, y = q.front().y, mask1 = q.front().mask1, mask2 = q.front().mask2; q.pop();
			for (j = 0; j < 4; ++j) {
				int nx = x + dx[j], ny = y + dy[j];
				int nmask1 = mask1, nmask2 = mask2;
				if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
					for (k = 0; k < o; ++k) {
						if (((oy[k] == ny && ox[k] > nx) || (oy[k] == y && ox[k] > x)) && x == nx) {
							int miny = min(ny, y);
							if (miny < oy[k]) nmask1 ^= 1 << k;
							else nmask2 ^= 1 << k;
						}
					}
					if (vst[nx][ny][nmask1][nmask2] != -1 || grid[nx][ny] != '.') continue;
					vst[nx][ny][nmask1][nmask2] = level + 1;
					q.push({nx, ny, nmask1, nmask2});
				}
			}
		}
		++level;
	}
}

int main() {
	int i, j, k, xs, ys;
	scanf("%d %d", &n, &m);
	for (i = 0; i < n; ++i) scanf("%s", grid[i]);

	for (i = 0; i < n; ++i) {
		for (j = 0; j < m; ++j) {
			if (grid[i][j] == 'S') xs = i, ys = j, grid[i][j] = '.';
			if ('0' <= grid[i][j] && grid[i][j] <= '9') ++o, --grid[i][j];
		}
	}

	for (i = 0; i < o; ++i) {
		int x;
		scanf("%d", &x);
		val.push_back(x);
	}

	for (i = 0; i < n; ++i) {
		for (j = 0; j < m; ++j) {
			if (grid[i][j] == 'B') grid[i][j] = '0' + o, ++o, val.push_back(-MVAL);
		}
	}

	for (k = 0; k < o; ++k) {
		for (i = 0; i < n; ++i) {
			for (j = 0; j < m; ++j) {
				if (grid[i][j] == k + '0') ox.push_back(i), oy.push_back(j);
			}
		}
	}

	bfs(xs, ys);

	int ans = 0;
	for (i = 0; i < (1 << o); ++i) {
		long long sum = 0;
		for (j = 0; j < o; ++j) if ((i >> j) & 1) sum += val[j];
		if (sum < 0 || vst[xs][ys][i][i] == -1) continue;
		ans = max(ans, (int)sum - vst[xs][ys][i][i]);
	}
	printf("%d\n", ans);
	return 0;
}
