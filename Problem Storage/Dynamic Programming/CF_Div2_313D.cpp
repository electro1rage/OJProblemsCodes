#include <bits/stdc++.h>
using namespace std;

const int MAXN = 305;
const long long MAXVAL = 10000000000000000LL;

int n, m, k;

long long cost[MAXN][MAXN];
long long memo[MAXN][MAXN];

long long get_ans(int i, int k) {
	if (k >= ::k) return 0;
	if (i == n + 1) return MAXVAL;

	long long &ret = memo[i][k];
	if (ret == -1) {
		ret = get_ans(i + 1, k);
		for (int j = i; j <= n; ++j) {
			ret = min(ret, get_ans(j + 1, k + j - i + 1) + cost[i][j]);
		}
	}
	return ret;
}

int main() {
	for (int i = 0; i < MAXN; ++i) for (int j = 0; j < MAXN; ++j) cost[i][j] = MAXVAL;

	scanf("%d %d %d", &n, &m, &k);

	for (int i = 0; i < m; ++i) {
		int l, r, c;
		scanf("%d %d %d", &l, &r, &c);
		cost[l][r] = min(cost[l][r], 1LL * c);
	}

	for (int i = 1; i <= n; ++i) {
		long long mini = MAXVAL;
		for (int j = n; j >= i; --j) {
			mini = min(mini, cost[i][j]);
			cost[i][j] = mini;
		}
	}

	memset(memo, -1, sizeof memo);
	long long ans = get_ans(1, 0);
	if (ans == MAXVAL) {
		puts("-1");
		return 0;
	}

	printf("%I64d\n", ans);
	return 0;
}









