#include <bits/stdc++.h>
using namespace std;

int numOfNodes[100005];
vector<vector<int> > adj;

int rootTheTree(int node, int parent) {
	numOfNodes[node] = 1;

	int sz = adj[node].size();
	for (int i = 0; i < sz; ++i) {
		int x = adj[node][i];
		if (x == parent) continue;
		numOfNodes[node] += rootTheTree(x, node);
	}

	return numOfNodes[node];
}

int main() {
	int n;
	cin >> n;

	adj.resize(n + 1);
	int u[100005];
	int v[100005];
	int c[100005];

	for (int i = 1; i < n; ++i) {
		cin >> u[i] >> v[i] >> c[i];
		adj[u[i]].push_back(v[i]);
		adj[v[i]].push_back(u[i]);
	}

	rootTheTree(1, 1);

	long long deno = 1LL * n * (n - 1) * (n - 2) / 6;
	double res = 0;

	long long e[100005];
	for (int i = 1; i < n; ++i) {
		int a = min(numOfNodes[u[i]], numOfNodes[v[i]]);
		e[i] = 1LL * a * (n - a) * (n - 2);
		res += c[i] * 1.0 * e[i] / deno;
	}

	int q;
	cin >> q;

	for (int i = 0; i < q; ++i) {
		int j, val;
		cin >> j >> val;

		res += (val - c[j]) * 1.0 * e[j] / deno;
		c[j] = val;

		cout << setprecision(6) << fixed << res << endl;
	}

	return 0;
}
