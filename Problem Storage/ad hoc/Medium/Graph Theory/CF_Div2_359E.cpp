#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for((i)=0;(i)<(int)(n);++(i))

const int MN = 501;

int di[] = {1, 0, 0, -1};
int dj[] = {0, 1, -1, 0};

char dir[] = {'D', 'R', 'L', 'U'};
char revdir[] = {'U', 'L', 'R', 'D'};

int n;

bool vst[MN][MN];
bool light[MN][MN];
int grid[MN][MN];

vector<char> ans;

bool is_good(int i, int j) {
	return i >= 0 && i < n && j >= 0 && j < n;
}

void dfs(int i, int j) {
	int k;
	vst[i][j] = true;
	if (!light[i][j]) ans.push_back('1');
	light[i][j] = true;

	REP(k, 4) {
		int ni = i + di[k], nj = j + dj[k];
		if (!is_good(ni, nj) || vst[ni][nj]) continue;

		bool gooddir = false;
		for (int m = 1; is_good(i + m * di[k], j + m * dj[k]); ++m) {
			if (light[i + m * di[k]][j + m * dj[k]]) {
				gooddir = true;
				break;
			}
		}
		if (gooddir) {
			ans.push_back(dir[k]);
			dfs(ni, nj);
			ans.push_back(revdir[k]);
		}
	}
}

void get_path(int i, int j) {
	int k;
	vst[i][j] = true;

	REP(k, 4) {
		int ni = i + di[k], nj = j + dj[k];
		if (is_good(ni, nj) && !vst[ni][nj] && light[ni][nj]) {
			ans.push_back(dir[k]);
			get_path(ni, nj);
			ans.push_back(revdir[k]);
		}
	}

	ans.push_back('2');
}

int main() {
	int x0, y0, i, j;
	scanf("%d %d %d", &n, &x0, &y0);
	--x0, --y0;

	REP(i, n) REP(j, n) scanf("%d", &grid[i][j]), light[i][j] = grid[i][j];

	dfs(x0, y0);

	REP(i, n) REP(j, n) {
		if (grid[i][j] && !vst[i][j]) {
			puts("NO");
			return 0;
		}
	}

	memset(vst, 0, sizeof vst);
	get_path(x0, y0);

	puts("YES");
	REP(i, ans.size()) printf("%c", ans[i]);puts("");
	return 0;
}
