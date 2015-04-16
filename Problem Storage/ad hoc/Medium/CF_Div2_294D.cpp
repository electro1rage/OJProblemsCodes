#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	int xs, ys;
	scanf("%d %d", &n, &m);

	char s[5];
	scanf("%d %d %s", &xs, &ys, s);

	int dx = -1, dy = -1;

	if (s[0] == 'D') dx = 1;
	if (s[1] == 'R') dy = 1;

	int x = xs, y = ys;

	if (x == 1) dx = 1;
	if (x == n) dx = -1;
	if (y == 1) dy = 1;
	if (y == m) dy = -1;

	int dxs = dx, dys = dy;

	set<pair<int, int> > se;
	se.insert({x, y});

	long long ans = 1;

	while (se.size() < n + m - 2) {

		int moves = 1000000;
		if (dx == 1) moves = min(moves, n - x);
		else moves = min(moves, x - 1);
		if (dy == 1) moves = min(moves, m - y);
		else moves = min(moves, y - 1);

		x += moves * dx, y += moves * dy;

		if (x == 1) dx = 1;
		if (x == n) dx = -1;
		if (y == 1) dy = 1;
		if (y == m) dy = -1;

		ans += moves;

		if (x == xs && y == ys && dx == dxs && dy == dys) {
			puts("-1");
			return 0;
		}

		se.insert({x, y});
	}

	printf("%I64d\n", ans);
	return 0;
}







