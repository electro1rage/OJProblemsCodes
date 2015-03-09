#include <bits/stdc++.h>
using namespace std;

int dpth[100005];
int node[100005];
vector<int> adj[100005];

int main() {
	int n, m, t;
	scanf("%d %d %d", &n, &m, &t);

	for (int i = 0; i < m; ++i) {
		int u, v;
		scanf("%d %d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	memset(dpth, -1, sizeof dpth);

	int curdpth = 0;
	dpth[1] = curdpth;
	node[curdpth] = 1;

	while (true) {
		bool allgood = true;
		for (auto &curnode : adj[node[curdpth]]) {
			if (dpth[curnode] == -1) {
				allgood = false;
				dpth[curnode] = curdpth + 1;
				node[curdpth + 1] = curnode;
				break;
			}
		}

		if (allgood) {
			for (int i = 0; i < adj[node[curdpth]].size(); ++i) {
				if (curdpth - dpth[adj[node[curdpth]][i]] >= t) {
					printf("%d\n", curdpth - dpth[adj[node[curdpth]][i]] + 1);
					for (int j = dpth[adj[node[curdpth]][i]]; j <= curdpth; ++j) {
						if (j > dpth[adj[node[curdpth]][i]]) printf(" ");
						printf("%d", node[j]);
					}
					puts("");
					return 0;
				}
			}
		}

		++curdpth;
	}

	return 0;
}



