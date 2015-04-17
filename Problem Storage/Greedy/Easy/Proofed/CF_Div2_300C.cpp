#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
const int MAXN = 1000006;

int fact[MAXN];

bool is_good(int a, int b, int n) {
	while (n) {
		if (n % 10 != a && n % 10 != b) return false;
		n /= 10;
	}
	return true;
}

int Pow(int x, int p) {
	if (p == 0) return 1;

	if (p % 2) return (1LL * x * Pow((1LL * x * x) % MOD, p / 2)) % MOD;

	return Pow((1LL * x * x) % MOD, p / 2);
}

int main() {
	int a, b, n;
	scanf("%d %d %d", &a, &b, &n);

	int ans = 0;

	fact[0] = 1;
	for (int i = 1; i <= n; ++i) {
		fact[i] = (1LL * i * fact[i - 1]) % MOD;
	}

	for (int i = 0; i <= n; ++i) {
		int asum = a * i, bsum = b * (n - i);
		if (is_good(a, b, asum + bsum)) {
			ans = (ans + (1LL * fact[n] * Pow(fact[i], MOD - 2) % MOD) * Pow(fact[n - i], MOD - 2)) % MOD;
		}
	}

	printf("%d\n", ans);
	return 0;
}



