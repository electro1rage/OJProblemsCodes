#include <bits/stdc++.h>
using namespace std;

const int MN = 505;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int n, m;

struct state {
	char move;
	int x, y;
};

bool vst[MN][MN];
char grid[MN][MN];
int xs, ys;

queue<state> ans;

void DFS(int x, int y) {
	vst[x][y] = true;

	ans.push({'B', x, y});

	for (int i = 0; i < 4; ++i) {
		int nx = x + dx[i], ny = y + dy[i];
		if (nx >= 0 && nx < n && ny >= 0 && ny < m && !vst[nx][ny] && grid[nx][ny] == '.') {
			DFS(nx, ny);
		}
	}

	if (x == xs && y == ys) return;
	ans.push({'D', x, y});
	ans.push({'R', x, y});
}

int main() {
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; ++i) scanf("%s", grid[i]);

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (grid[i][j] == '#' || vst[i][j]) continue;
			xs = i, ys = j;
			DFS(i, j);
		}
	}

	printf("%d\n", (int)ans.size());
	while (!ans.empty()) {
		printf("%c %d %d\n", ans.front().move, ans.front().x + 1, ans.front().y + 1);
		ans.pop();
	}
	return 0;
}







