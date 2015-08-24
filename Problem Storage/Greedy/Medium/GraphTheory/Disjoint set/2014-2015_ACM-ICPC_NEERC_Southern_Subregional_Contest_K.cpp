#include <bits/stdc++.h>
using namespace std;

const int MN = 2020;

vector<vector<int> > grid;
int dist[MN][MN];
int root[MN];
int b[MN];
int place[MN];
vector<int> edge;
vector<int> component[MN];

int find_root(int i) {
	if (i == root[i]) return i;
	return root[i] = find_root(root[i]);
}

void join(int u, int v) {
	int tu = u, tv = v;
	u = find_root(u), v = find_root(v);
	root[u] = root[v];
	printf("%d %d\n", tu + 1, tv + 1);
}

bool same_tree(int u, int v) {
	return find_root(u) == find_root(v);
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int n, i, j, k;
		scanf("%d", &n);
		edge.clear();
		grid.clear();
		grid.resize(n);
		for (i = 0; i < n; ++i) {
			component[i].clear(), component[i].push_back(i), root[i] = i, grid[i].resize(n), b[i] = 0, place[i] = i;
		}

		for (i = 0; i < n; ++i) {
			for (j = 0; j < n; ++j) {
				scanf("%d", &grid[i][j]), --grid[i][j];
			}
		}

		sort(grid.begin(), grid.end());
		for (i = 0; i < n; ++i) {
			for (j = 0; j < n; ++j) dist[i][grid[i][j]] = j;
		}

		for (k = 0; k < n - 1; ++k) {
			for (i = 0; i < n; ++i) {
				int sz = component[i].size(), bestu = -1, bestv, maxi = MN;;
				for (j = 0; j < sz; ++j) {
					int u = component[i][j], v = component[i][0];
					while (b[u] < n && same_tree(u, grid[u][b[u]])) ++b[u];
					if (b[u] == n) break;
					if (bestu == -1 || grid[u][b[u]] == grid[v][b[v]]) bestu = grid[u][b[u]];
					else {
						bestu = -1;
						break;
					}
					if (maxi > dist[bestu][component[i][j]]) maxi = dist[bestu][component[i][j]], bestv = component[i][j];
				}
				if (bestu == -1) continue;
				join(bestu, bestv); // you may kiss the pride xD.
				for (j = 0; j < sz; ++j) {
					component[place[bestu]].push_back(component[i][j]), place[component[i][j]] = place[bestu];
				}
				component[i].clear();
			}
		}

		puts("");
	}
	return 0;
}
