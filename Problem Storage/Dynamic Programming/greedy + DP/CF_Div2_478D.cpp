#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

int main() {
	int r, g;
	cin >> r >> g;

	int h, lowest = 0;
	for (int i = 1; i <= 900; ++i) {
		bool can = 1;
		int tempr = r, tempg = g;
		for (int j = i; j >= 1; --j) {
			if (tempg >= j) {
				tempg -= j;
			} else if (tempr >= j) {
				tempr -= j;
			} else {
				can = 0;
				break;
			}
		}
		if (can) {
			h = i;
			lowest = r - tempr;
		}
	}

	int dp[2][200005] = {};
	dp[0][0] = 1;

	for (int i = 1; i <= h; ++i) {
		for (int used = 0; used <= r; ++used) {
			dp[i & 1][used] = dp[(i + 1) & 1][used];
			if (used >= i) {
				dp[i & 1][used] = ((long long)dp[i & 1][used] + dp[(i + 1) & 1][used - i]) % MOD;
			}
		}
	}

	int res = 0;
	for (int i = lowest; i <= r; ++i) {
		res = ((long long)res + dp[h & 1][i]) % MOD;
	}

	cout << res << endl;
	return 0;
}


