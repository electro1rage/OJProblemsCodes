#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
const int MN = 100005;

int fact[2 * MN];

int get_pow(int x, int p) {
	if (p == 0) return 1;
	if (p % 2) return (1LL * x * get_pow(1LL * x * x % MOD, p / 2)) % MOD;
	return get_pow(1LL * x * x % MOD, p / 2);
}


int nCr(int n, int r) {
	if (r < 0) return 0;
	return (1LL * fact[n] * get_pow(fact[r], MOD - 2) % MOD) * get_pow(fact[n - r], MOD - 2) % MOD;
}

int solve(int n, int m, bool g) {
	if (n < 0) return 0;
	if (m + n == 1) {
		if (n && !g) return 1;
		if (m && g) return 1;
		return 0;
	}

	if (g) {
		return solve(n - 1, m, 0);
	} else {
		return (nCr(n + m - 1, m - 1) + solve(n - 1, m, 1)) % MOD;
	}
}

int main() {
	int n, m, g;
	scanf("%d %d %d", &n, &m, &g);

	fact[0] = 1;
	for (int i = 1; i <= n + m + 3; ++i) {
		fact[i] = (1LL * i * fact[i - 1]) % MOD;
	}

	printf("%d\n", solve(n, m, g));
	return 0;
}
