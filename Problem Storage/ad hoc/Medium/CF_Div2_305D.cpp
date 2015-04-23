#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000005;
const int MOD = 1000000007;

map<pair<int, int>, bool> edge;
int numberofedges[MAXN];
bool bad[MAXN];
int n, m, k;

bool have_edge(int u, int v) {
	return edge.count({u, v});
}

bool is_bad() {
	for (int i = n - 1; i > 0; --i) {
		if (numberofedges[i] > 2) return true;
		if (numberofedges[i] == 2 && !have_edge(i, i + k + 1)) return true;
		if (numberofedges[i] == 1) {
			bad[i] = bad[i + 1];
			continue;
		}
		if (bad[i + k + 1]) return true;
		bad[i] = true;
	}
	return false;
}

int get_pow(int x, int p) {
	if (p == 0) return 1;
	if (p % 2) return (1LL * x * get_pow((1LL * x * x) % MOD, p / 2)) % MOD;
	return get_pow((1LL * x * x) % MOD, p / 2);
}

int get_mini() {
	for (int i = n; i > 0; --i) {
		if (numberofedges[i] == 2) return i;
	}
	return -1;
}

int main() {
	scanf("%d %d %d", &n, &m, &k);

	for (int i = 0; i < m; ++i) {
		int u, v;
		scanf("%d %d", &u, &v);
		edge[{u, v}] = true;
		++numberofedges[u];
	}

	for (int i = 1; i < n; ++i) if (!have_edge(i, i + 1)) edge[{i, i + 1}] = true, ++numberofedges[i];

	if (is_bad()) {
		puts("0");
		return 0;
	}

	if (k >=  n - 1) {
		puts("1");
		return 0;
	}

	int mini = get_mini();

	//no node i have edge to i + k + 1
	if (mini == -1) {
		int sz = n - k - 1;
		int ans = get_pow(2, min(sz, k + 1));
		for (int i = k + 2; i <= sz; ++i) {
			ans = (ans + get_pow(2, k)) % MOD;
		}
		printf("%d\n", ans);
		return 0;
	}

	int good = 0;
	int left = max(1, mini - k), right = min(left + k, n - k - 1);
	for (int i = left; i <= right; ++i) good += numberofedges[i] == 1;
	int ans = get_pow(2, good);

	for (int i = right + 1; i <= mini + k && i < n - k; ++i) {
		if (numberofedges[left] == 2) break;
		ans = (ans + get_pow(2, good - 1)) % MOD;
		++left;
	}
	printf("%d\n", ans);
	return 0;
}
