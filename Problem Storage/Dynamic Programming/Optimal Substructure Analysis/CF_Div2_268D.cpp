#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000009;
const int MAXN = 2;
const int MAXH = 32;
const int CHOICES = 2;

int dp[MAXN][MAXH][MAXH][MAXH][CHOICES];

int main() {
	int n, h;
	scanf("%d %d", &n, &h);

	dp[1 & 1][1][1][1][1] = 1;
	for (int i = 1; i <= n; ++i) {
		for (int h1 = 1; h1 <= h + 1; ++h1) {
			for (int h2 = 1; h2 <= h + 1; ++h2) {
				for (int h3 = 1; h3 <= h + 1; ++h3) {
					for (int alive = 0; alive < 2; ++alive) {
						int cur = dp[i & 1][h1][h2][h3][alive];
						dp[i & 1][h1][h2][h3][alive] = 0;

						int nh1 = min(h1 + 1, h + 1), nh2 = min(h2 + 1, h + 1), nh3 = min(h3 + 1, h + 1), h4 = h + 1;
						if (alive) h4 = 2;

						dp[i & 1 ^ 1][h4][nh2][nh3][h1 <= h] = (cur + dp[i & 1 ^ 1][h4][nh2][nh3][h1 <= h]) % MOD;

						dp[i & 1 ^ 1][nh1][h4][nh3][h2 <= h] = (cur + dp[i & 1 ^ 1][nh1][h4][nh3][h2 <= h]) % MOD;

						dp[i & 1 ^ 1][nh1][nh2][h4][h3 <= h] = (cur + dp[i & 1 ^ 1][nh1][nh2][h4][h3 <= h]) % MOD;

						dp[i & 1 ^ 1][nh1][nh2][nh3][alive] = (cur + dp[i & 1 ^ 1][nh1][nh2][nh3][alive]) % MOD;
					}
				}
			}
		}
	}

	int ans = 0;
	for (int h1 = 1; h1 <= h + 1; ++h1)
		for (int h2 = 1; h2 <= h + 1; ++h2)
			for (int h3 = 1; h3 <= h + 1; ++h3)
				for (int alive = 0; alive < 2; ++alive) {
					if (h1 == h + 1 && h2 == h + 1 && h3 == h + 1 && !alive) continue;
					ans = (ans + dp[(n + 1) & 1][h1][h2][h3][alive]) % MOD;
				}

	cout << ans << endl;
	return 0;
}
