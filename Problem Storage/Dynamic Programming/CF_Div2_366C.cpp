#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for((i)=0;(i)<(int)(n);++(i))

const int MN = 101;
const int SHIFT = MN * MN * 10;
const int MVAL = 2 * SHIFT + 3;

int dp[2][MVAL];
int a[MN], b[MN];

int main() {
	int n, k, i, j;
	scanf("%d %d", &n, &k);

	REP(i, n) scanf("%d", a + i);
	REP(i, n) scanf("%d", b + i);

	REP(i, 2) REP(j, MVAL) dp[i][j] = -MVAL * 10;

	dp[0&1][SHIFT] = 0;

	REP(i, n) REP(j, MVAL) {
		dp[(i+1)&1][j] = max(dp[(i+1)&1][j], dp[i&1][j]);
		int s = j + a[i] - k * b[i];
		if (s >= 0 && s < MVAL) dp[(i+1)&1][s] = max(dp[(i+1)&1][s], dp[i&1][j] + a[i]);

		dp[i&1][j] = -MVAL * 10;
	}

	if (dp[n&1][SHIFT] == 0) {
		puts("-1");
		return 0;
	}
	printf("%d\n", dp[n&1][SHIFT]);
	return 0;
}
