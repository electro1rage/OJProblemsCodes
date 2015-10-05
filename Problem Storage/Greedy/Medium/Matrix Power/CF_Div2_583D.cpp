#include <bits/stdc++.h>
using namespace std;

const int MN = 101, MM = 301, MVAL = 1000000000;

int a[MN];
vector<vector<int> > cost;
int dp[MN];

int get_cost(vector<int> &v) {
	int n = v.size(), i, j;
	for (i = 0; i < n + 1; ++i) dp[i] = MVAL;
	dp[0] = -MVAL;
	for (i = 0; i < n; ++i) {
		j = upper_bound(dp, dp + n + 1, v[i]) - dp;
		dp[j] = v[i];
	}
	return lower_bound(dp, dp + n + 1, MVAL) - dp - 1;
}

vector<vector<int> > multi(vector<vector<int> > a, vector<vector<int> > b) {
	int i, j, k;
	vector<vector<int> > ret(MM, vector<int> (MM, -MVAL));
	for (i = 1; i < MM; ++i) for (j = i; j < MM; ++j) for (k = i; k <= j; ++k) {
		ret[i][j] = max(ret[i][j], a[i][k] + b[k][j]);
	}
	return ret;
}

vector<vector<int> > get_ans(vector<vector<int> > x, int p) {
	if (p == 0) return vector<vector<int> > (MM, vector<int> (MM));
	if (p % 2) return multi(x, get_ans(x, p - 1));
	return get_ans(multi(x, x), p / 2);
}

int main() {
	int n, i, j, k, t;
	scanf("%d %d", &n, &t);
	for (i = 0; i < n; ++i) scanf("%d", a + i);

	cost = vector<vector<int> > (MM, vector<int> (MM, -MVAL));
	for (i = 1; i <= 300; ++i) {
		for (j = i; j <= 300; ++j) {
			vector<int> v;
			for (k = 0; k < n; ++k) if (i <= a[k] && a[k] <= j) v.push_back(a[k]);
			cost[i][j] = get_cost(v);
		}
	}

	vector<vector<int> > ans = get_ans(cost, t);
	printf("%d\n", ans[1][300]);
	return 0;
}
