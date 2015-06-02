#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for((i)=0;(i)<(int)(n);++(i))

const int MN = 101010;

long long w[MN];
vector<int> adj[MN];
priority_queue<pair<long long, int> > region;
bool vst[MN];

long long dfs(int node) {
	long long ret = w[node];
	vst[node] = true;

	for (auto &x : adj[node]) {
		if (!vst[x]) ret += dfs(x);
	}

	return ret;
}

int main() {
	int n, m, p, q;
	scanf("%d %d %d %d", &n, &m, &p, &q);

	int anyu, anyv;
	int i;
	REP(i, m) {
		int u, v, l;
		scanf("%d %d %d", &u, &v, &l);
		--u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
		w[u] += l;
		w[v] += l;
		anyu = u + 1, anyv = v + 1;
	}

	REP(i, n) {
		if (!vst[i]) {
			long long cost = dfs(i) / 2;
			region.push({-cost, i});
		}
	}


	int sz = region.size();
	if (sz < q || p + q - sz < 0 || (q == n && p != 0)) {
		puts("NO");
		return 0;
	}

	puts("YES");

	REP(i, sz - q) {
		long long cost = -region.top().first;
		int node1 = region.top().second;
		region.pop();

		cost += -region.top().first;
		int node2 = region.top().second;
		region.pop();

		anyu = node1 + 1, anyv = node2 + 1;

		long long add = min(cost + 1, 1000000000LL);

		region.push({-cost - add, node1});
		printf("%d %d\n", node1 + 1, node2 + 1);
	}

	REP(i, p + q - sz) printf("%d %d\n", anyu, anyv);
	return 0;
}
