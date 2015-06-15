#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for((i)=0;(i)<(int)(n);++(i))

const int MN = 1010101;
const int MVAL = 1010101010;

int dp[MN];
int a[MN];

int main() {
	int n, m, i;
	scanf("%d %d", &n, &m);

	for (i = 0; i < MN; ++i) dp[i] = MVAL;
	dp[0] = 0, dp[1] = 1;
	for (i = 2; ; ++i) {
		dp[i] = i + (i - 1) / 2 + (i - 2) / 2 + dp[i - 2] - i % 2;
		if (dp[i] > n) break;
	}

	int maxi = i - 1;
	maxi = min(maxi, m);

	for (i = 0; i < m; ++i) scanf("%d %d", a + i, a + i);
	sort(a, a + m);
	reverse(a, a + m);

	int ans = 0;
	for (i = 0; i < maxi; ++i) ans += a[i];

	printf("%d\n", ans);
	return 0;
}
