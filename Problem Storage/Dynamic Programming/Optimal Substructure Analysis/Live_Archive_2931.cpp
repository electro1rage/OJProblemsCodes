#include <bits/stdc++.h>
using namespace std;

const int MN = 40404, MVAL = 1010101010;
int a[MN], dp[MN];

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int n, i, j;
		scanf("%d", &n);

		for (i = 0; i < n; ++i) scanf("%d", a + i), dp[i + 1] = MVAL;
		dp[0] = -MVAL;

		for (i = 0; i < n; ++i) {
			j = upper_bound(dp, dp + n + 1, a[i]) - dp;
			dp[j] = min(dp[j], a[i]);
		}

		j = lower_bound(dp, dp + n + 1, MVAL) - dp;
		printf("%d\n", j - 1);
	}
	return 0;
}
