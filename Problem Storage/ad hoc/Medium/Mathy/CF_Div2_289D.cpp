#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

long long a[] = {1, 2, 9, 64, 625, 7776, 117649, 2097152};

int get_power(int n, int p) {
	int ret = 1;
	for (int i = 0; i < p; ++i)
		ret = (1LL * ret * n) % MOD;
	return ret;
}

int main() {
	int n, k;
	scanf("%d %d", &n, &k);

	int ans = (get_power(n - k, n - k) * a[k - 1]) % MOD;
	printf("%d\n", ans);
	return 0;
}

