#include <bits/stdc++.h>
using namespace std;

const int MN = 100005;
const int MVAL = 100000000;

vector<int> adj[MN];
int maxdistdown[MN], maxdisttop[MN];
bool evil[MN];

int get_maxdistdown(int node, int parent) {
	int ret = -MVAL;
	if (evil[node]) ret = 0;

	for (auto &x : adj[node]) {
		if (x == parent) continue;
		ret = max(ret, get_maxdistdown(x, node));
	}

	maxdistdown[node] = ret;
	return ret + 1;
}

void get_maxdisttop(int node, int parent, int pdist) {
	vector<int> cur;
	for (auto &x : adj[node]) if (x != parent) cur.push_back(x);

	int sz = cur.size();
	vector<int> maxl(sz + 2, -MVAL), maxr(sz + 2, -MVAL);

	for (int i = 1; i <= sz; ++i) {
		maxl[i] = max(maxl[i - 1], maxdistdown[cur[i - 1]]);
	}
	for (int i = sz; i > 0; --i) {
		maxr[i] = max(maxr[i + 1], maxdistdown[cur[i - 1]]);
	}

	int ret = pdist;
	if (evil[node]) ret = max(ret, 0);
	for (int i = 1; i <= sz; ++i) {
		int maxi = max(maxl[i - 1], maxr[i + 1]);
		get_maxdisttop(cur[i - 1], node, max(ret + 1, maxi + 2));
	}

	maxdisttop[node] = ret;
}

int main() {
	int n, m, d;
	scanf("%d %d %d", &n, &m, &d);

	for (int i = 0; i < m; ++i) {
		int p;
		scanf("%d", &p); --p;
		evil[p] = true;
	}

	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		scanf("%d %d", &a, &b); --a, --b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	get_maxdistdown(0, -2);

	get_maxdisttop(0, -1, -MVAL);

	int ans = 0;
	for (int i = 0; i < n; ++i) {
		if (maxdistdown[i] <= d && maxdisttop[i] <= d) {
			++ans;
		}
	}

	printf("%d\n", ans);
	return 0;
}
