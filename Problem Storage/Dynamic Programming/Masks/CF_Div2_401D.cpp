/*
reality, be rent!
synapse, break!
Van!shment Th!s World !!
*/
#include <bits/stdc++.h>
using namespace std;

const int MN = 18, MM = 101;

long long dp[1 << MN][MM];
long long fact[MN + 3];

int digit(char c) {
	return c - '0';
}

int main() {
	char n[20];
	int m, sz, i, j, k;
	scanf("%s %d", n, &m);
	sz = strlen(n);
	dp[0][0] = 1;

	for (i = 0; i < (1 << sz); ++i) {
		for (j = 0; j < m; ++j) {
			for (k = 0; k < sz; ++k) {
				if ((i >> k) & 1) continue;
				if (i || (!i && digit(n[k]))) dp[i | (1 << k)][(j * 10 + digit(n[k])) % m] += dp[i][j];
			}
		}
	}

	fact[0] = 1;
	for (i = 1; i <= sz; ++i) fact[i] = i * fact[i - 1];

	for (i = '0'; i <= '9'; ++i) {
		for (j = 0, k = 0; j < sz; ++j) if (n[j] == i) ++k;
		dp[(1 << sz) - 1][0] /= fact[k];
	}

	printf("%I64d\n", dp[(1 << sz) - 1][0]);
	return 0;
}
