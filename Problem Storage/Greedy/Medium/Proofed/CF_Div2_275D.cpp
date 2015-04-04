#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;

int val[MAXN];
vector<int> adj[MAXN];

pair<long long, long long> DFS(int node, int parent) {
	pair<long long, long long> ret{0, 0};

	for (auto &child : adj[node]) {
		if (child == parent) continue;
		pair<long long, long long> temp = DFS(child, node);
		ret.first = min(ret.first, temp.first);
		ret.second = max(ret.second, temp.second);
	}

	val[node] += ret.first + ret.second;
	if (val[node] > 0) ret.first -= val[node];
	else ret.second -= val[node];
	return ret;
}

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		scanf("%d %d", &u, &v); --u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for (int i = 0; i < n; ++i)
		scanf("%d", val + i);

	pair<long long, long long> ans = DFS(0, -1);
	cout << abs(ans.first) + abs(ans.second) << endl;
	return 0;
}




