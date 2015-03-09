#include <bits/stdc++.h>
using namespace std;

bool vst[100005];
vector<vector<int> > adj;
vector<int> ans;
int n;

bool can_build(int fval, int sval, int tval, int dpth) {
	if (dpth == n) return 1;
	vst[tval] = 1;

	for (int i = 0; i < 4; ++i) {
		int nval = adj[tval][i];

		if (nval == fval) continue;

		if (find(adj[sval].begin(), adj[sval].end(), nval) != adj[sval].end() && !vst[nval]) {
			if (can_build(sval, tval, nval, dpth + 1)) {
				ans.push_back(nval);
				return 1;
			}
		}
	}
	return 0;
}

int main() {
	scanf("%d", &n);

	adj.resize(n + 1);
	for (int i = 0; i < 2 * n; ++i) {
		int u, v;
		scanf("%d %d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for (int i = 1; i <= n; ++i) {
		if (adj[i].size() != 4) {
			puts("-1");
			return 0;
		}
	}

	for (int sind = 0; sind < 4; ++sind) {
		for (int tind = 0; tind < 4; ++tind) {
			if (sind == tind) continue;
			int fval = 1, sval = adj[1][sind], tval = adj[1][tind];
			memset(vst, 0, sizeof vst);
			vst[fval] = vst[sval] = vst[tval] = 1;
			if (can_build(fval, sval, tval, 3)) {
				ans.push_back(tval);
				ans.push_back(sval);
				ans.push_back(fval);

				reverse(ans.begin(), ans.end());

				for (auto &x : ans)
					printf("%d ", x);printf("\n");
				return 0;
			}
		}
	}

	puts("-1");
	return 0;
}



