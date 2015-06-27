#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
const int MN = 101010;

int memo[MN][2];
bool black[MN];
vector<int> adj[MN];

int get_count(int node, bool pblack) {
	int &ret = memo[node][pblack];
	if (ret != -1) return ret;

	ret = 0;
	if (black[node] || pblack) {
		ret = 1;
		for (auto &x : adj[node]) ret = 1LL * ret * get_count(x, true) % MOD;
	}
	if (!black[node]) {
		int dp[2]; dp[0] = 1, dp[1] = 0;
		int a, b;
		for (auto &x : adj[node]) {
				a = get_count(x, false);
				b = get_count(x, true);
				dp[1] = (1LL * dp[1] * b % MOD + 1LL * a * dp[0] % MOD) % MOD;
				dp[0] = 1LL * dp[0] * b % MOD;
		}
		ret += dp[1];
	}

	return ret;
}

int main() {
	int n, x, i;
	scanf("%d", &n);

	for (i = 0; i < n - 1; ++i) {
		int x;
		scanf("%d", &x);
		adj[x].push_back(i + 1);
	}

	for (i = 0; i < n; ++i) scanf("%d", &x), black[i] = x;

	memset(memo, -1, sizeof memo);
	printf("%d\n", get_count(0, false));
	return 0;
}
