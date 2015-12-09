/*
reality, be rent!
synapse, break!
Van!shment Th!s World !!
*/
#include <bits/stdc++.h>
using namespace std;

const int MN = 101010, MVAL = 1010101010;

int a[MN], b[MN], dp[MN][303];
vector<int> x[MN];

int main() {
	int n, m, s, e, ans = 0, sz, y, i, j;
	scanf("%d %d %d %d", &n, &m, &s, &e);

	for (i = 1; i <= n; ++i) scanf("%d", a + i);
	for (i = 0; i < m; ++i) scanf("%d", b + i), x[b[i]].push_back(i + 1);


	for (i = 0; i <= n; ++i) {
		for (j = 0; j <= s / e; ++j) dp[i][j] = MVAL;
	}
	dp[0][0] = 0;
	for (i = 0; i < n; ++i) {
		for (j = 0; j <= s / e; ++j) {
			dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
			y = upper_bound(x[a[i + 1]].begin(), x[a[i + 1]].end(), dp[i][j]) - x[a[i + 1]].begin();
			sz = x[a[i + 1]].size();
			if (y == sz) continue;
			dp[i + 1][j + 1] = min(dp[i + 1][j + 1], x[a[i + 1]][y]);
		}
	}

	for (i = 1; i <= n; ++i) {
		for (j = 0; j <= s / e; ++j) {
			if (j * e + i + dp[i][j] <= s) ans = max(ans, j);
		}
	}

	printf("%d\n", ans);
	return 0;
}
