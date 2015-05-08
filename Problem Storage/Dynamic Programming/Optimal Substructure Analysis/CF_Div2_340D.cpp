#include <bits/stdc++.h>
using namespace std;

const int MN = 100005;
const int MVAL = 1000000000;

int a[MN];
int dp[MN];

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; ++i) scanf("%d", a + i), dp[i + 1] = MVAL;
	dp[0] = -MVAL;

	for (int i = 0; i < n; ++i) {
		int j = upper_bound(dp, dp + n, a[i]) - dp;
		dp[j] = min(dp[j], a[i]);
	}

	int ans = lower_bound(dp, dp + n + 1, MVAL) - dp - 1;
	printf("%d\n", ans);
	return 0;
}
