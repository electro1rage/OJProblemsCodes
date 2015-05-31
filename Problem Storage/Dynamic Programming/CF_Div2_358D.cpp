#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for((i)=0;(i)<(int)(n);++(i))

const int MN = 3010;
const int MVAL = 1000000010;

int dp[2][2];

int a[MN], b[MN], c[MN];

int main() {
	int n, i, j;

	scanf("%d", &n);

	REP(i, n) scanf("%d", a + i);
	REP(i, n) scanf("%d", b + i);
	REP(i, n) scanf("%d", c + i);

	dp[0 & 1][0] = 0;
	dp[0 & 1][1] = -MVAL;

	REP(i, n) {
		dp[i&1^1][0] = max(dp[i&1^1][0], dp[i&1][0] + b[i]);
		dp[i&1^1][1] = max(dp[i&1^1][1], dp[i&1][0] + a[i]);

		dp[i&1^1][0] = max(dp[i&1^1][0], dp[i&1][1] + c[i]);
		dp[i&1^1][1] = max(dp[i&1^1][1], dp[i&1][1] + b[i]);
	}

	printf("%d\n", dp[n & 1][1]);
	return 0;
}
