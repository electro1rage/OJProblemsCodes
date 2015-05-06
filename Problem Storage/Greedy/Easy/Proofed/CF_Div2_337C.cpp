#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000009;

int get_pow(int x, int p) {
	if (p == 0) return 1;
	if (p % 2) return (1LL * x * get_pow(1LL * x * x % MOD, p / 2)) % MOD;
	return get_pow(1LL * x * x % MOD, p / 2);
}

int main() {
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);

	int bm = n / k * (k - 1) + n % k;
	if (bm >= m) {
		printf("%d\n", m);
		return 0;
	}

	int d = m - bm;
	int ans = (bm - 1LL * d * (k - 1) % MOD + MOD) % MOD + (2LL * k % MOD) * ((get_pow(2, d) - 1 + MOD) % MOD) % MOD;

	printf("%d\n", ans % MOD);
	return 0;
}
