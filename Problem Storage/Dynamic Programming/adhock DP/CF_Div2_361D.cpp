#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for((i)=0;(i)<(int)(n);++(i))

const int MN = 2020;

int dp[MN];
int a[MN];
int n, k;

bool is_good(int diff) {
	int i;
	REP(i, n) dp[i] = i;

	REP(i, n) {
		for (int j = i + 1; j < n; ++j) {
			if (abs(a[i] - a[j]) <= 1LL * (j - i) * diff) dp[j] = min(dp[j], dp[i] + j - i - 1);
		}
	}

	REP(i, n) if (dp[i] + n - i - 1 <= k) return true;
	return false;
}

int main() {
	scanf("%d %d", &n, &k);

	int i;
	REP(i, n) scanf("%d", a + i);

	long long s = 0, e = 2000000010;
	int ans;
	while (s <= e) {
		long long mid = (s + e) / 2;
		if (is_good(mid)) ans = mid, e = mid - 1;
		else s = mid + 1;
	}

	printf("%d\n", ans);
	return 0;
}
