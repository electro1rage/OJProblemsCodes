#include <bits/stdc++.h>
using namespace std;

int n;
string name[100005];

bool used[100005];

vector<vector<int> > adj;
int nameid[100005];
vector<int> dpth[100005];
int ndpth[100005];
vector<int> accum[100005];

int X;
int L[100005], R[100005];

void dfs(int node, int d) {
	ndpth[node] = d;
	dpth[d].push_back(node);
	L[node] = X;++X;
	for (auto &x : adj[node])
		dfs(x, d + 1);
	R[node] = X;++X;
}

int count_smaller(int d, int bound, int arr[]) {
	int sz = dpth[d].size();
	int s = 0, e = sz - 1;
	int res = -1;
	while (s <= e) {
		int mid = (s + e) / 2;
		if (arr[dpth[d][mid]] < bound) {
			s = mid + 1;
			res = mid;
		} else e = mid - 1;
	}
	return res;
}

map<pair<pair<int, int>, int>, int> cashe;

int main() {
	scanf("%d", &n);
	adj.resize(n + 1);

	map<string, int> mname;
	for (int i = 1; i <= n; ++i) {
		int parent;
		cin >> name[i] >> parent;
		mname[name[i]] = 0;
		adj[parent].push_back(i);
	}

	int ind = 0;
	for (auto &x : mname) x.second = ind, ++ind;

	for (int i = 1; i <= n; ++i)
		nameid[i] = mname[name[i]];


	dfs(0, 0);

	int q;
	scanf("%d", &q);
	for (int i = 0; i < q; ++i) {
		int v, k;
		scanf("%d %d", &v, &k);
		int reldpth = ndpth[v] + k;

		if (reldpth >= 100005) {
			printf("%d\n", 0);
			continue;
		}

		int low, high, sz = dpth[reldpth].size();
		low = count_smaller(reldpth, L[v], L) + 1;
		high = count_smaller(reldpth, R[v], R);

		if (low == sz || high == -1) {
			printf("%d\n", 0);
			continue;
		}

		pair<pair<int, int>, int> state = make_pair(make_pair(low, high), reldpth);
		if (cashe.count(state)) {
			printf("%d\n", cashe[state]);
			continue;
		}

		int res = 0;
		for (int j = low; j <= high; ++j) {
			int x = nameid[dpth[reldpth][j]];
			if (!used[x]) {
				used[x] = true;
				++res;
			}
		}
		for (int j = low; j <= high; ++j) {
			int x = nameid[dpth[reldpth][j]];
			used[x] = false;
		}

		cashe[state] = res;
		printf("%d\n", res);
	}
	return 0;
}
