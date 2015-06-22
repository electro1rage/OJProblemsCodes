#include <bits/stdc++.h>
using namespace std;

double dp[1 << 18];
double p[18][18];

bool is_one(int mask, int i) {
	return (mask >> i) & 1;
}

int main() {
	int n, i, j, k;
	cin >> n;

	for (i = 0; i < n; ++i) for (j = 0; j < n; ++j) cin >> p[i][j];

	dp[(1 << n) - 1] = 1;

	for (i = (1 << n) - 1; i > 0; --i) {
		int sz = __builtin_popcount(i);
		double c = sz * (sz - 1) / 2; c = 1.0 / c;
		for (j = 0; j < n; ++j) {
			for (k = j + 1; k < n; ++k) {
				if (is_one(i, j) && is_one(i, k)) {
					dp[i ^ (1 << j)] += dp[i] * c * p[k][j];
					dp[i ^ (1 << k)] += dp[i] * c * p[j][k];
				}
			}
		}
	}

	for (i = 0; i < n; ++i) {
		if (i) cout << ' ';
		cout << setprecision(6) << fixed << dp[1 << i];
	}
	cout << endl;
	return 0;
}
