#include <bits/stdc++.h>
using namespace std;

const int MN = 500005;

vector<vector<int> > dpthL;
vector<vector<pair<int, vector<int> > > > acum;
int L[MN], R[MN];
vector<vector<int> > adj;
char s[MN];
int X, maxid = -1;

void dfs(int node, int d) {
	maxid = max(maxid, d);
	int lsz = dpthL.size(), i, j;
	if (lsz == d) {
		dpthL.push_back(vector<int> ());
		acum.push_back(vector<pair<int, vector<int> > > ());
	}

	int sz = acum[d].size();
	bool found = false;
	lsz = dpthL[d].size() + 1;
	for (i = 0; i < sz; ++i) {
		int csz = acum[d][i].second.size();
		if (acum[d][i].first != s[node] - 'a') {
			for (j = 0; j < lsz - csz; ++j) acum[d][i].second.push_back(acum[d][i].second.back());
		} else {
			found = true;
			for (j = 0; j < lsz - csz - 1; ++j) acum[d][i].second.push_back(acum[d][i].second.back());
			acum[d][i].second.push_back(acum[d][i].second.back() + 1);
		}
	}
	if (!found) {
		acum[d].push_back({s[node] - 'a', vector<int> ()});
		for (i = 0; i < lsz; ++i) acum[d].back().second.push_back(0);
		acum[d].back().second.back() = 1;
	}
	L[node] = X, dpthL[d].push_back(L[node]), ++X;

	for (auto &x : adj[node]) dfs(x, d + 1);

	R[node] = X, ++X;
}

inline int get_sum(int st, int ed, int k, int h) {
	if (st == 0) return acum[h][k].second[ed];
	return acum[h][k].second[ed] - acum[h][k].second[st - 1];
}

inline void get_ans(int node, int h) {
	int sz = dpthL[h].size();
	int st = lower_bound(dpthL[h].begin(), dpthL[h].end(), L[node]) - dpthL[h].begin();
	int ed = lower_bound(dpthL[h].begin(), dpthL[h].end(), R[node]) - dpthL[h].begin(); --ed;
	if (st == sz) {
		puts("Yes");
		return ;
	}
	if (dpthL[h][st] > R[node]) {
		puts("Yes");
		return ;
	}

	sz = acum[h].size();
	int odd = 0, i;
	for (i = 0; i < sz; ++i) {
		odd += get_sum(st, ed, i, h) % 2;
	}

	if (odd <= 1) {
		puts("Yes");
		return ;
	}

	puts("No");
}

int main() {
	int n, m, i;
	scanf("%d %d", &n, &m);

	adj.resize(n);

	for (i = 0; i < n - 1; ++i) {
		int x;
		scanf("%d", &x);
		--x;
		adj[x].push_back(i + 1);
	}

	scanf("%s", s);
	dfs(0, 0);

	for (i = 0; i < m; ++i) {
		int vi, hi;
		scanf("%d %d", &vi, &hi);
		--vi, --hi;
		if (hi > maxid) {
			puts("Yes");
			continue;
		} else get_ans(vi, hi);
	}
	return 0;
}
