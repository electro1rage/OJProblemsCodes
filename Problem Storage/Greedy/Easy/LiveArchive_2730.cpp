/*
reality, be rent!
synapse, break!
Van!shment Th!s World !!
*/
#include <bits/stdc++.h>
using namespace std;

const int MN = 55, MVAL = 1010101010;

int get_num(char c) {
	if (c <= 'Z') return c - 'A';
	return c - 'a' + 26;
}

bool is_town(int x) {
	return x < 26;
}

vector<int> adj[MN];
int dist[MN];

void dij(int u, int p) {
	int v, c, nc, sz, i;
	for (i = 0; i < MN; ++i) dist[i] = MVAL;
	priority_queue<pair<int, int> > q;
	q.push({-p, u});
	dist[u] = p;

	while (!q.empty()) {
		u = q.top().second, c = -q.top().first, q.pop();
		if (c != dist[u]) continue;
		sz = adj[u].size();
		for (i = 0; i < sz; ++i) {
			if (is_town(u)) nc = (20 * c + 18) / 19;
			else nc = c + 1;
			v = adj[u][i];
			if (dist[v] > nc) dist[v] = nc, q.push({-nc, v});
		}
	}
}

int main() {
	int n, K = 1;
	while (true) {
		scanf("%d", &n);
		if (n == -1) break;
		char u, v;
		int p, i;
		for (i = 0; i < MN; ++i) adj[i].clear();
		for (i = 0; i < n; ++i) {
			scanf(" %c %c", &u, &v);
			adj[get_num(u)].push_back(get_num(v));
			adj[get_num(v)].push_back(get_num(u));
		}

		scanf("%d %c %c", &p, &u, &v);
		dij(get_num(v), p);
		printf("Case %d: %d\n", K, dist[get_num(u)]);
		++K;
	}
	return 0;
}
