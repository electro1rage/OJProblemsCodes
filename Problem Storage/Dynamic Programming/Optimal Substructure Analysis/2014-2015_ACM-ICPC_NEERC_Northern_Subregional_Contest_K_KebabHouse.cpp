/*
reality, be rent!
synapse, break!
Van!shment Th!s World !!
*/
#include <bits/stdc++.h>
using namespace std;

const int MN = 1010, MM = 256, MT = 123, MOD = 1000000007;

int dp[MT][MM];
int id[MN * MM + MT];
int a[MN], b[MN];

void add(int &a, int &b) {
	a += b;
	if (a >= MOD) a -= MOD;
}

int main() {
	freopen("kebab.in", "r", stdin);
	freopen("kebab.out", "w", stdout);

	int n, t, x, y;

	scanf("%d %d", &n, &t);
	for (x = 0; x < n; ++x) scanf("%d %d", a + x, b + x), b[x] = a[x] - b[x], a[x] += (x ? a[x - 1] : 0);

	memset(id, -1, sizeof id);
	for (x = 0, y = 0; x < a[n - 1]; ++x) {
		if (x == a[y]) ++y;
		id[x] = y;
	}

	dp[0][0] = 1;
	for (x = 0; x < a[n - 1]; ++x) {
		for (y = 0; y <= b[id[x]]; ++y) {
			if (id[x] != id[x + 1]) add(dp[(x + 1) % MT][0], dp[x % MT][y]);
			else add(dp[(x + 1) % MT][y], dp[x % MT][y]);

			if (y + 1 <= b[id[x]]) {
				if (id[x] != id[x + t + 1]) add(dp[(x + t + 1) % MT][0], dp[x % MT][y]);
				else add(dp[(x + t + 1) % MT][y + 1], dp[x % MT][y]);
			}
		}
		for (y = 0; y < MM; ++y) dp[x % MT][y] = 0;
	}

	int ans = 0;
	for (x = a[n - 1]; x <= a[n - 1] + t; ++x) add(ans, dp[x % MT][0]);

	printf("%d\n", ans);
	return 0;
}
