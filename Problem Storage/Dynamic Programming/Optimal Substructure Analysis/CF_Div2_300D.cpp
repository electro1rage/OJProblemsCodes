#include <bits/stdc++.h>
using namespace std;

const int MOD = 7340033;
const int MAXK = 1005;
const int MAXN = 32;

int dp[MAXN][MAXK + 30];
int d[MAXK + 70];

void process() {
	for (int i = 0; i < MAXN; ++i) {
		dp[i][0] = 1;
		memset(d, 0, sizeof d);
		for (int j = 0; j < MAXK; ++j) {
			for (int k = 0; k < MAXK - j; ++k) {
				d[j + k] = (d[j + k] + 1LL * dp[i][j] * dp[i][k]) % MOD;
			}
		}

		for (int j = 0; j < MAXK; ++j) {
			for (int k = 0; k < MAXK - j; ++k) {
				int &state = dp[i + 1][j + k + 1];
				state = (state + 1LL * d[j] * d[k]) % MOD;
			}
		}

	}
}

int get_depth(int n) {
	int ret = 0;
	while (n % 2 && n != 1) ++ret, n /= 2;
	return ret;
}

int main() {
	process();

	int q;
	scanf("%d", &q);

	while (q--) {
		int n, k;
		scanf("%d %d", &n, &k);

		int dpth = get_depth(n);

		printf("%d\n", dp[dpth][k]);
	}
	return 0;
}









