/*
reality, be rent!
synapse, break!
Van!shment Th!s World !!
*/
#include <bits/stdc++.h>
using namespace std;

const int MN = 505, MVAL = 101010101;

int dp[MN][MN];
bool pal[MN][MN];
int a[MN];

int main() {
	int n, i, j, k, l;
	scanf("%d", &n);

	for (i = 0; i < n; ++i) scanf("%d", a + i);

	for (i = 0; i < n; ++i) {
		for (j = i; j < n; ++j) {
			for (k = i, l = j; k <= j; ++k, --l) if (a[k] != a[l]) break;
			if (k > j) pal[i][j] = true;
		}
	}


	for (i = 0; i < n; ++i) {
		for (j = 0; j < n; ++j) dp[i][j] = MVAL;
	}

	for (i = 0; i < n; ++i) dp[i][i] = 1;
	for (i = 0; i < n - 1; ++i) dp[i][i + 1] = (pal[i][i + 1] ? 1 : 2);

	for (i = n - 1; i >= 0; --i) {
		for (j = i + 2; j < n; ++j) {
			if (pal[i][j]) {
				dp[i][j] = 1;
				continue;
			}
			if (a[i] != a[j]) {
				dp[i][j] = min(dp[i][j], 2 + dp[i + 1][j - 1]);
			} else {
				dp[i][j] = min(dp[i][j], dp[i + 1][j - 1]);
			}
			for (k = i; k < j; ++k) dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
		}
	}

	printf("%d\n", dp[0][n - 1]);
	return 0;
}
