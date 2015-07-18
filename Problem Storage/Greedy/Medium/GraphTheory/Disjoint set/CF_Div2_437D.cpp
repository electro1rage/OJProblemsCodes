#include <bits/stdc++.h>
using namespace std;

const int MN = 101010;

int a[MN];
vector<pair<int, int> > adj[MN];
int id[MN], cnt[MN];

int find_root(int i) {
	if (id[i] == i) return i;
	return id[i] = find_root(id[i]);
}

void rootij(int i, int j) {
	id[i] = j, cnt[j] += cnt[i];
}

int main() {
	int n, m, i, j;
	scanf("%d %d", &n, &m);

	vector<pair<int, int> > b(n);
	for (i = 0; i < n; ++i) scanf("%d", a + i), b[i] = {a[i], i}, id[i] = i, cnt[i] = 1;

	sort(b.rbegin(), b.rend());

	for (i = 0; i < m; ++i) {
		int x, y;
		scanf("%d %d", &x, &y);
		--x, --y;
		adj[x].push_back({a[y], y});
		adj[y].push_back({a[x], x});
	}

	long long ans = 0, all = 1LL * n * (n - 1) / 2;
	for (i = 0; i < n; ++i) {
		int node = b[i].second, areasz = b[i].first, sz = adj[node].size(), sum = 0;
		vector<int> root, uroot, ucnt;

		for (j = 0; j < sz; ++j) {
			if (adj[node][j] > b[i]) root.push_back(find_root(adj[node][j].second));
		}
		if (root.empty()) continue;

		sort(root.begin(), root.end());
		sum += cnt[*root.begin()], ucnt.push_back(sum), uroot.push_back(*root.begin()), sz = root.size();
		for (j = 1; j < sz; ++j) {
			if (root[j] != root[j - 1]) sum += cnt[root[j]], ucnt.push_back(cnt[root[j]]), uroot.push_back(root[j]);
		}

		ans += 1LL * areasz * sum;
		sz = ucnt.size();

		for (j = 0; j < sz; ++j) {
			sum -= ucnt[j];
			ans += 1LL * areasz * ucnt[j] * sum;
		}

		for (j = 1; j < sz; ++j) rootij(uroot[j], *uroot.begin());
		rootij(node, *uroot.begin());
	}

	cout << setprecision(5) << fixed << (double)ans / all << endl;
	return 0;
}
