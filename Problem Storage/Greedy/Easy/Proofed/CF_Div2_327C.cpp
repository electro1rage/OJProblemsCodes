#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
const int MOD = 1000000007;


int get_pow(long long x, long long p) {
	if (p == 0) return 1;
	if (p % 2) return (1LL * x * get_pow(1LL * x * x % MOD, p / 2)) % MOD;
	return get_pow(1LL * x * x % MOD, p / 2);
}

int F(long long k, long long l) {
	if (k == 0) return 0;
	if (k % 2) return (get_pow(2, l * (k - 1)) + F(k - 1, l)) % MOD;
	long long ret = F(k / 2, l);
	return ret * (1 + get_pow(2, (k / 2) * l)) % MOD;
}

char a[MAXN];

int main() {
	scanf("%s", a);

	int k; scanf("%d", &k);
	int n = strlen(a);

	int ans = 0;

	int fact = F(k, n);

	for (int i = 0; i < n; ++i) {
		if (a[i] == '0' || a[i] == '5') {
			ans = (ans + 1LL * fact * get_pow(2, i) % MOD) % MOD;
		}
	}

	printf("%d\n", ans);
	return 0;
}







