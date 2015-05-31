#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for((i)=0;(i)<(int)(n);++(i))

const int MN = 1010;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int grid[2 * MN][2 * MN];
int sum[2 * MN][2 * MN];
bool vst[MN][MN];
vector<pair<int, int> > degree[5];
int n, m;

void DFS(int x, int y) {
	if (x < 0 || x >= n || y < 0 || y >= m || grid[x][y] != 1 || vst[x][y]) return;
	vst[x][y] = true;

	for (int i = 0; i < 4; ++i) DFS(x + dx[i], y + dy[i]);
}

int get_sum(int x1, int y1, int x2, int y2) {
	if (x1 < 0) x1 = 0;
	if (y1 < 0) y1 = 0;
	if (x2 < 0) x2 = 0;
	if (y2 < 0) y2 = 0;
	int xmax = max(x1, x2), xmin = min(x1, x2), ymax = max(y1, y2), ymin = min(y1, y2);
	x1 = xmin, x2 = xmax;
	y1 = ymin, y2 = ymax;

	int sum1 = 0, sum2 = 0, sum3 = 0;
	if (x1) sum1 = sum[x1 - 1][y2];
	if (y1) sum2 = sum[x2][y1 - 1];
	if (x1 && y1) sum3 = sum[x1 - 1][y1 - 1];

	return sum[x2][y2] - sum1 - sum2 + sum3;
}

bool valid(int x1, int y1, int x2, int y2, int k) {
	int sum = get_sum(x1, y1, x2, y2);
	if (x2 < 0 || y2 < 0) return sum == 1;
	if (grid[x2][y2]) return sum == 2 || sum == k + 1;
	return sum == 1;
}

int main() {
	scanf("%d %d", &n, &m);

	int i, j, k;
	REP(i, n) REP(j, m) scanf("%d", &grid[i][j]);

	REP(i, n) REP(j, m) if (grid[i][j]) {
		DFS(i, j);
		goto FINISH;
	}

	FINISH:

	REP(i, n) REP(j, m) if (grid[i][j] && !vst[i][j]) {
		puts("-1");
		return 0;
	}

	REP(i, n) REP(j, m) if (grid[i][j]) {
		int ctr = 0;
		REP(k, 4) {
			int ni = i + dx[k], nj = j + dy[k];
			if (ni >= 0 && nj >= 0 && grid[ni][nj]) ++ctr;
		}
		if (ctr != 2) degree[ctr].push_back({i, j});
		else if ((i && (!grid[i - 1][j] || !grid[i + 1][j])) || !i) {
			if ((j && (!grid[i][j - 1] || !grid[i][j + 1])) || !j) degree[ctr].push_back({i, j});
		}
	}

	if (!degree[0].empty()) {
		puts("-1");
		return 0;
	}

	int startsum = degree[1].size() + degree[3].size();
	if (startsum != 0 && startsum != 2) {
		puts("-1");
		return 0;
	}

	int si, sj;
	REP(i, 5) {
		if (!degree[i].empty()) {
			si = degree[i][0].first, sj = degree[i][0].second;
			break;
		}
	}

	REP(i, 2 * n + 1) REP(j, 2 * m + 1) {
		int sum1 = 0, sum2 = 0, sum3 = 0;
		if (i) sum1 = sum[i - 1][j];
		if (j) sum2 = sum[i][j - 1];
		if (i && j) sum3 = sum[i - 1][j - 1];
		sum[i][j] = grid[i][j] + sum1 + sum2 - sum3;
	}


	vector<int> ans;
	for (k = 2; k < n; ++k) {
		bool bad = false;
		for (i = si % k; i < n; i += k) {
			for (j = sj % k; j < m; j += k) {
				if (get_sum(i + 1, j + 1, i + k - 1, j + k - 1)) bad = true;
				if (grid[i][j]) {
					int ni, nj;
					ni = i + k, nj = j;
					if (!valid(i, j, ni, nj, k)) bad = true;
					ni = i - k, nj = j;
					if (!valid(i, j, ni, nj, k)) bad = true;
					ni = i, nj = j + k;
					if (!valid(i, j, ni, nj, k)) bad = true;
					ni = i, nj = j - k;
					if (!valid(i, j, ni, nj, k)) bad = true;
				} else {
					int ni, nj;
					ni = i + k - 1, nj = j;
					if (get_sum(i, j, ni, nj) != 0) bad = true;
					ni = i - k + 1, nj = j;
					if (get_sum(i, j, ni, nj) != 0) bad = true;
					ni = i, nj = j + k - 1;
					if (get_sum(i, j, ni, nj) != 0) bad = true;
					ni = i, nj = j - k + 1;
					if (get_sum(i, j, ni, nj) != 0) bad = true;
				}
			}
		}
		if (!bad) ans.push_back(k);
	}

	if (ans.empty()) {
		puts("-1");
		return 0;
	}

	REP(i, ans.size()) {
		if (i) printf(" ");
		printf("%d", ans[i]);
	}
	puts("");
	return 0;
}
