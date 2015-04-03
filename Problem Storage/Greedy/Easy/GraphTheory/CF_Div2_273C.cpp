#include <bits/stdc++.h>
using namespace std;

const int MAXN = 300005;

set<pair<int, int> > order;
int bad[MAXN];
bool id[MAXN];

vector<int> adj[MAXN];

void update(int node) {
	order.erase({-bad[node], node});
	bad[node] = 0;
	for (auto &child : adj[node])
		bad[node] += id[node] == id[child];
	order.insert({-bad[node], node});
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; ++i) {
		int u, v;
		scanf("%d %d", &u, &v); --u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for (int i = 0; i < n; ++i) bad[i] = adj[i].size();
	for (int i = 0; i < n; ++i) order.insert({-bad[i], i});

	while (true) {
		int node = order.begin()->second;
		if (bad[node] < 2) break;

		id[node] = !id[node];

		update(node);
		for (auto &child : adj[node]) update(child);
	}

	for (int i = 0; i < n; ++i)
		printf("%d", id[i]);puts("");
	return 0;
}




