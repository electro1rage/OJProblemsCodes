#include <bits/stdc++.h>
using namespace std;

const int MAXN = 105;
const int MAXVAL = 2000000000;

int a[MAXN], x[MAXN], y[MAXN];
int n, d;

int cost[MAXN];

int get_dist(int i, int j) {
	return abs(x[i] - x[j]) + abs(y[i] - y[j]);
}

int get_shortest_path() {
	for (int i = 0; i < MAXN; ++i) cost[i] = MAXVAL;
	priority_queue<pair<int, int> > q;
	q.push({0, 0});
	cost[0] = 0;

	while (!q.empty()) {
		int curnode = q.top().second, curcost = -q.top().first; q.pop();
		if (curnode == n - 1) return curcost;
		for (int i = 0; i < n; ++i) {
			if (i == curnode) continue;
			int totalcost = curcost + d * get_dist(curnode, i) - a[curnode];
			if (totalcost < cost[i]) {
				cost[i] = totalcost;
				q.push({-totalcost, i});
			}
		}
	}
}

int main() {
	scanf("%d %d", &n, &d);

	for (int i = 1; i < n - 1; ++i) scanf("%d", a + i);

	for (int i = 0; i < n; ++i) scanf("%d %d", x + i, y + i);

	printf("%d\n", get_shortest_path());
	return 0;
}






