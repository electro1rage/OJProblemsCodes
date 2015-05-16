#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for((i)=0;(i)<(int)(n);++(i))

const int MN = 100010;

int apples[MN];
vector<int> adj[MN];
int n;

long long get_lcm(long long a, long long b) {
	return a / __gcd(a, b) * b;
}

pair<long long, long long> get_ans(int node, int parent) {
	if (parent != -1 && adj[node].size() == 1) return {1, apples[node]};

	vector<pair<long long, long long> > a;
	for (auto &x : adj[node]) if (x != parent) a.push_back(get_ans(x, node));

	long long lcm = 1;
	for (int i = 0; i < a.size(); ++i) lcm = get_lcm(lcm, a[i].first);

	long long y = 100000000000000LL;
	for (int i = 0; i < a.size(); ++i) y = min(y, a[i].second * a[i].first / lcm);
	y *= lcm;

	if (y == 0) return {1, 0};

	for (int i = 0; i < a.size(); ++i) {
		a[i].second = y / a[i].first;
	}

	long long gcd = a[0].second;
	for (int i = 0; i < a.size(); ++i) gcd = __gcd(gcd, a[i].second);

	long long sum = 0;
	for (int i = 0; i < a.size(); ++i) sum += a[i].second / gcd * a[i].first;

	return {sum, gcd};
}

int main() {
	int i;
	scanf("%d", &n);

	REP(i, n) scanf("%d", apples + i);
	REP(i, n - 1) {
		int u, v;
		scanf("%d %d", &u, &v); --u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	long long sum = 0;
	REP(i, n) sum += apples[i];

	pair<long long, long long> ans = get_ans(0, -1);
	cout << sum - ans.first * ans.second << endl;
	return 0;
}
