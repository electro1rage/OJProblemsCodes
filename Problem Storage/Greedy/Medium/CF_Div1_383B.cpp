/*
reality, be rent!
synapse, break!
Van!shment Th!s World !!
*/
#include <bits/stdc++.h>
using namespace std;

unordered_map<int, set<int> > xy, yx;
queue<pair<int, int> > q;
bool side[4];

void bfs(int &n) {
	int i, sz;
	while (!q.empty()) {
		sz = q.size();
		for (i = 0; i < sz; ++i) {
			int x = q.front().first, y = q.front().second; q.pop();
			side[0] |= x == 1;
			side[1] |= y == 1;
			side[2] |= x == n;
			side[3] |= y == n;
			++x, --y;
			auto it = xy[x].lower_bound(y);
			while (it != xy[x].end()) {
				q.push({x, *it});
				yx[*it].erase(-x);
				xy[x].erase(it);
				it = xy[x].lower_bound(y);
			}
			it = yx[y].lower_bound(-x);
			while (it != yx[y].end()) {
				q.push({-*it, y});
				xy[-*it].erase(y);
				yx[y].erase(it);
				it = yx[y].lower_bound(-x);
			}
		}
	}
}

int main() {
	int n, m, i;
	scanf("%d %d", &n, &m);
	for (i = 0; i < m; ++i) {
		int x, y;
		scanf("%d %d", &x, &y);
		xy[x].insert(y), yx[y].insert(-x);
		if (x == 1 || y == n) q.push({x, y});
	}

	bfs(n);

	if ((side[0] && side[1]) || (side[0] && side[2]) || (side[1] && side[3]) || (side[2] && side[3])) {
		puts("-1");
		return 0;
	}

	printf("%d\n", 2 * n - 2);
	return 0;
}
