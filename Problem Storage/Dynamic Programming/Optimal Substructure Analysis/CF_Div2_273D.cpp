#include <bits/stdc++.h>
using namespace std;

#define IDLE 0
#define LESS 1

const int MAXN = 155;
const int STATES = 2;
const int MOD = 1000000007;

long long dp[MAXN][MAXN][MAXN][STATES][STATES], sum[MAXN][MAXN][STATES][STATES];

long long get_sum(int x1, int y1, int x2, int y2, int ls, int rs) {
	if (y2 < y1 || x2 < x1) return 0;
	return sum[x2][y2][ls][rs] + sum[x1 - 1][y1 - 1][ls][rs] - sum[x1 - 1][y2][ls][rs] - sum[x2][y1 - 1][ls][rs];
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	int ans = 0;

	for (int i = n; i >= 1; --i) {
		memset(sum, 0, sizeof sum);
		for (int l = 1; l <= m; ++l) {
			for (int r = 1; r <= m; ++r) {
				for (int ls = 0; ls < 2; ++ls) {
					for (int rs = 0; rs < 2; ++rs) {
						sum[l][r][ls][rs] = sum[l - 1][r][ls][rs] + sum[l][r - 1][ls][rs]
														- sum[l - 1][r - 1][ls][rs] + dp[i + 1][l][r][ls][rs];
						sum[l][r][ls][rs] %= MOD;
						if (sum[l][r][ls][rs] < 0) sum[l][r][ls][rs] += MOD;
					}
				}
			}
		}
		for (int l = 1; l <= m; ++l) {
			for (int r = l; r <= m; ++r) {
				for (int ls = 0; ls < 2; ++ls) {
					for (int rs = 0; rs < 2; ++rs) {
						long long &cur = dp[i][l][r][ls][rs];
						cur = 1;

						//start = l, finish = r
						if (ls == LESS && rs == LESS) {
							int x1 = l, x2 = r;
							int y1 = l, y2 = r;
							cur += get_sum(x1, y1, x2, y2, LESS, LESS);
							cur %= MOD;
							if (cur < 0) cur += MOD;
						}

						//start = l, finish = m
						if (ls == LESS && rs == IDLE) {
							int x1 = l, x2 = r;
							int y1 = l, y2 = r - 1;
							cur += get_sum(x1, y1, x2, y2, LESS, LESS);
							cur %= MOD;
							if (cur < 0) cur += MOD;

							y1 = r, y2 = m;
							cur += get_sum(x1, y1, x2, y2, LESS, IDLE);
							cur %= MOD;
							if (cur < 0) cur += MOD;
						}

						//start = 1, finish = r
						if (ls == IDLE && rs == LESS) {
							int x1 = l + 1, x2 = r;
							int y1 = l, y2 = r;
							cur += get_sum(x1, y1, x2, y2, LESS, LESS);
							cur %= MOD;
							if (cur < 0) cur += MOD;

							x1 = 1, x2 = l;
							cur += get_sum(x1, y1, x2, y2, IDLE, LESS);
							cur %= MOD;
							if (cur < 0) cur += MOD;
						}

						//start = 1, finish = m
						if (ls == IDLE && rs == IDLE) {
							int x1 = l + 1, x2 = r;
							int y1 = l, y2 = r - 1;
							cur += get_sum(x1, y1, x2, y2, LESS, LESS);
							cur %= MOD;
							if (cur < 0) cur += MOD;

							x1 = 1, x2 = l;
							y1 = l, y2 = r - 1;
							cur += get_sum(x1, y1, x2, y2, IDLE, LESS);
							cur %= MOD;
							if (cur < 0) cur += MOD;

							x1 = l + 1, x2 = r;
							y1 = r, y2 = m;
							cur += get_sum(x1, y1, x2, y2, LESS, IDLE);
							cur %= MOD;
							if (cur < 0) cur += MOD;

							x1 = 1, x2 = l;
							y1 = r, y2 = m;
							cur += get_sum(x1, y1, x2, y2, IDLE, IDLE);
							cur %= MOD;
							if (cur < 0) cur += MOD;
						}
					}
				}
				ans = (ans + dp[i][l][r][IDLE][IDLE]) % MOD;
			}
		}
	}

	printf("%d\n", ans);
	return 0;
}







