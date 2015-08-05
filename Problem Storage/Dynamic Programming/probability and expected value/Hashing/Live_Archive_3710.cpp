#include <bits/stdc++.h>
using namespace std;

const int MN = 33;

vector<int> adj[MN];
int vst[MN], cur, n;
long long pw[31];
map<long long, double> memo;

int dfs(int node) {
	vst[node] = cur;
	int ret = 1;
	for (auto &x : adj[node]) if (vst[x] != cur) ret += dfs(x);
	return ret;
}

int nc2(int n) {
	return n * (n - 1) / 2;
}

double get_ans(vector<int> &v, long long hash) {
	if (v.size() == 1) return 0;

	if (memo.count(hash)) return memo[hash];

	int sz = v.size(), i, j, k;
	double psm = 0;
	for (i = 0; i < sz; ++i) psm += nc2(v[i]); psm /= nc2(n);

	double q = 1 - psm, &ret = memo[hash];
	ret = 0;
	for (i = 0; i < sz; ++i) {
		for (j = i + 1; j < sz; ++j) {
			vector<int> nv;
			long long nhash = 0;
			for (k = 0; k < sz; ++k) {
				if (k == i || k == j) continue;
				nv.push_back(v[k]), nhash += pw[nv.back()];
			}
			nv.push_back(v[i] + v[j]), nhash += pw[nv.back()];
			ret += ((v[i] * v[j]) / (double)nc2(n)) * (1 + get_ans(nv, nhash));
		}
	}

	ret /= q;
	ret += psm / q;

	return ret;
}

int main() {
	int m, i;
	pw[1] = 1;
	for (i = 2; i < 31; ++i) pw[i] = pw[i - 1] * 37;
	while (cin >> n >> m) {
		++cur, memo.clear();
		for (i = 0; i < n; ++i) adj[i].clear();

		for (i = 0; i < m; ++i) {
			int u, v;
			scanf("%d %d", &u, &v);
			--u, --v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		vector<int> v;
		long long hash = 0;
		for (i = 0; i < n; ++i) if (vst[i] != cur) v.push_back(dfs(i)), hash += pw[v.back()];

		cout << setprecision(6) << fixed << get_ans(v, hash) << endl;
	}
	return 0;
}
