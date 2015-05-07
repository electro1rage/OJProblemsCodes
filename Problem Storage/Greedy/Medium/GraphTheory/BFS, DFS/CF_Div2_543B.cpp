#include <bits/stdc++.h>
using namespace std;

const int MN = 3005;

int edge[MN][MN];
bool vst[MN];
int dist[MN][MN];
vector<vector<int> > adj;

void BFS(int s) {
	memset(vst, 0, sizeof vst);

	queue<int> q;
	int level = 0;

	q.push(s), vst[s] = 1;

	while (!q.empty()) {
		int sz = q.size();
		for (int i = 0; i < sz; ++i) {
			int cur = q.front(); q.pop(); dist[s][cur] = level;
			for (int j = 0; j < adj[cur].size(); ++j) {
				if (!vst[adj[cur][j]]) {
					vst[adj[cur][j]] = true;
					q.push(adj[cur][j]);
				}
			}
		}
		++level;
	}
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	adj.resize(n);
	for (int i = 0; i < m; ++i) {
		int u, v;
		scanf("%d %d", &u, &v); --u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	int s1, t1, l1;
	scanf("%d %d %d", &s1, &t1, &l1);
	int s2, t2, l2;
	scanf("%d %d %d", &s2, &t2, &l2);

	--s1, --t1, --s2, --t2;

	for (int i = 0; i < n; ++i) BFS(i);

	int ans = dist[s1][t1] + dist[s2][t2];

	if (dist[s1][t1] > l1 || dist[s2][t2] > l2) {
		puts("-1");
		return 0;
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			for (int k = 0; k < 2; ++k) {
				swap(s1, t1);
				if (dist[s1][i] + dist[i][j] + dist[j][t1] > l1) continue;
				if (dist[s2][i] + dist[i][j] + dist[j][t2] > l2) continue;
				ans = min(ans, dist[s1][i] + dist[i][j] + dist[j][t1] + dist[s2][i] + dist[j][t2]);
			}
		}
	}

	printf("%d\n", m - ans);
	return 0;
}





