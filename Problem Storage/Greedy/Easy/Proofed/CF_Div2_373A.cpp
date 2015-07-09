#include <bits/stdc++.h>
using namespace std;

const int MVAL = 2020202020;

int xs, ys, n, m, a, b;

bool valid(int x, int y) {
	return x >= 1 && x <= n && y >= 1 && y <= m;
}

int dir(int xg, int x) {
	return xg > x ? 1 : -1;
}

int get_ans(int x,int y, int xg, int yg) {
	int ret = 0;
	set<pair<int, int> > vst;
	while (x != xg || y != yg) {
		++ret;
		int dx, dy;
		if (x == 1) {
			dx = 1, dy = dir(yg, y);
		} else if (x == n) {
			dx = -1, dy = dir(yg, y);
		} else if (y == 1) {
			dx = dir(xg, x), dy = 1;
		} else if (y == m) {
			dx = dir(xg, x), dy = -1;
		} else {
			dx = dir(xg, x), dy = dir(yg, y);
		}
		x = x + dx * a, y = y + dy * b;
		if (vst.find({x, y}) != vst.end()) return MVAL;
		if (!valid(x, y)) return MVAL;
		vst.insert({x, y});
	}
	return ret;
}

int main() {
	scanf("%d %d %d %d %d %d", &n, &m, &xs, &ys, &a, &b);

	if (xs == 1 || xs == n) {
		if (ys == 1 || ys == m) {
			puts("0");
			return 0;
		}
	}

	int ans = MVAL;
	ans = min(ans, get_ans(xs, ys, 1, 1));
	ans = min(ans, get_ans(xs, ys, 1, m));
	ans = min(ans, get_ans(xs, ys, n, 1));
	ans = min(ans, get_ans(xs, ys, n, m));

	if (ans == MVAL) {
		puts("Poor Inna and pony!");
		return 0;
	}

	printf("%d\n", ans);
	return 0;
}
