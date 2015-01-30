#include <bits/stdc++.h>
using namespace std;

//D = 0, R = 1, L = 2, U = 3.
int dx[] = {1, 0, 0, -1};
int dy[] = {0, 1, -1, 0};
struct rec {
	int x1, y1, x2, y2;
};

vector<rec> R;

int clr[2005][2005];
int X, Y;

map<int, int> mx, my;
int xm[2005], ym[2005];

void DFS(int x, int y) {
	if (x < 0 || x >= X || y < 0 || y >= Y || clr[x][y]) return;
	clr[x][y] = 1;
	for (int i = 0; i < 4; ++i)
		DFS(x + dx[i], y + dy[i]);
}

int main() {
	int n;
	cin >> n;

	int x = 0, y = 0;

	for (int i = 0; i < n; ++i) {
		char c;
		int step;
		cin >> c >> step;
		if (c == 'L') {
			rec temp{x, y - step, x + 1, y + 1};
			R.push_back(temp);
			y -= step;
		}
		if (c == 'R') {
			rec temp{x, y, x + 1, y + step + 1};
			R.push_back(temp);
			y += step;
		}
		if (c == 'U') {
			rec temp{x - step, y, x + 1, y + 1};
			R.push_back(temp);
			x -= step;
		}
		if (c == 'D') {
			rec temp{x, y, x + step + 1, y + 1};
			R.push_back(temp);
			x += step;
		}
	}

	for (int i = 0; i < n; ++i) {
		mx[R[i].x1] = mx[R[i].x2] = -1;
		my[R[i].y1] = my[R[i].y2] = -1;
	}

	for (auto &x : mx) {
		x.second = X;
		xm[X] = x.first;
		++X;
	}

	for (auto &x : my) {
		x.second = Y;
		ym[Y] = x.first;
		++Y;
	}
	--X, --Y;

	for (int i = 0; i < n; ++i) {
		int x1 = mx[R[i].x1], x2 = mx[R[i].x2], y1 = my[R[i].y1], y2 = my[R[i].y2];
		for (int j = x1; j < x2; ++j)
			for (int l = y1; l < y2; ++l)
				clr[j][l] = 2;
	}

	for (int i = 0; i < X; ++i)
		for (int j = 0; j < Y; ++j)
			if (i == 0 || j == 0 || i == X - 1 || j == Y - 1) DFS(i, j);

	long long res = 0;

	for (int i = 0; i < X; ++i) {
		for (int j = 0; j < Y; ++j) {
			if (clr[i][j] != 1) {
				int dx = xm[i + 1] - xm[i], dy = ym[j + 1] - ym[j];
				res += 1LL * dx * dy;
			}
		}
	}

	cout << res << endl;
	return 0;
}



