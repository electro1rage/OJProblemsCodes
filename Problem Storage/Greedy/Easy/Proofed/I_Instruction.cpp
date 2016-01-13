#include <bits/stdc++.h>
using namespace std;

const int MN = 55, MVAL = 1000000000;

struct data {
	int t, node, g;
	bool operator<(const data &x) const {
		return t > x.t;
	}
};

int to[MN], a[MN], b[MN];
char c[MN];
map<char, int> cm;

void dfs(int node) {
	if (c[node] != 0) return ;
	if (node == 0) to[node] = a[node];
	if (node != 0) to[node] = min(a[node], b[node]);

	dfs(a[node]);
	if (node != 0) dfs(b[node]);
}

bool can_reach(int node, int goal) {
	if (c[node] != 0) return node == goal;
	if (can_reach(a[node], goal) || can_reach(b[node], goal)) return true;
	return false;
}

int main() {
	freopen("instruction.in", "r", stdin);
	freopen("instruction.out", "w", stdout);
	int n, m, p, t, node, g, i;
	char C;

	memset(a, -1, sizeof a);
	memset(b, -1, sizeof b);

	cin >> n;

	for (i = 1; i <= n; ++i) {
		cin >> C >> p;
		if (C == 'p') {
			cin >> C;
			if (a[p] == -1) a[p] = i;
			else b[p] = i;
			c[i] = C;
			cm[C] = i;
		} else {
			if (a[p] == -1) a[p] = i;
			else b[p] = i;
		}
	}

	dfs(0);

	priority_queue<data> q;

	cin >> m;
	for (i = 0; i < m; ++i) {
		cin >> p >> C;
		q.push({p, 0, cm[C]});
	}

	vector<pair<int, int> > ans;

	while (!q.empty()) {
		t = q.top().t, node = q.top().node, g = q.top().g, q.pop();
		if (node == 0) {
			if (to[node] == g) continue;
			q.push({t + 1, to[node], g});
			continue;
		}

		if (can_reach(a[node], g)) p = a[node];
		if (can_reach(b[node], g)) p = b[node];

		if (to[node] == p) {
			if (to[node] == g) continue;
			q.push({t + 1, to[node], g});
			continue;
		}

		ans.push_back({node, t});

		to[node] = p;
		if (to[node] == g) continue;
		q.push({t + 1, to[node], g});
	}

	n = ans.size();
	cout << n << endl;
	for (i = 0; i < n; ++i) {
		cout << ans[i].first << ' ' << ans[i].second << endl;
	}

	return 0;
}
