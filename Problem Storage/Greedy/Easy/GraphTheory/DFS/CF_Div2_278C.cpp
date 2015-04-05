#include <bits/stdc++.h>
using namespace std;

const int MAXN = 105;

vector<int> adj[MAXN];
bool know[MAXN][MAXN];
bool vst[MAXN];

void DFS(int node) {
	vst[node] = true;

	for (auto &child : adj[node]) {
		if (!vst[child]) DFS(child);
	}
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	bool allempty = true;
	for (int i = 0; i < n; ++i) {
		int k;
		scanf("%d", &k);
		for (int j = 0; j < k; ++j) {
			int x;
			scanf("%d", &x);
			know[i][x - 1] = true;
		}
		allempty &= !k;
	}

	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			for (int k = 0; k < m; ++k) {
				if (know[i][k] && know[j][k]) {
					adj[i].push_back(j);
					adj[j].push_back(i);
				}
			}
		}
	}

	int ans = -1 + allempty;
	for (int i = 0; i < n; ++i) {
		if (!vst[i]) {
			++ans;
			DFS(i);
		}
	}

	printf("%d\n", ans);
	return 0;
}





