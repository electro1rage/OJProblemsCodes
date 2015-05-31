#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for((i)=0;(i)<(int)(n);++(i))

const int MN = 101010;
const int MOD = 1000000007;

int get_pow(int x, long long p) {
	if (p == 0) return 1;
	if (p % 2) return 1LL * x * get_pow(1LL * x * x % MOD, p / 2) % MOD;
	return get_pow(1LL * x * x % MOD, p / 2);
}

int a[MN];
map<long long, int> m;

int main() {
	int n, x, i;
	scanf("%d %d", &n, &x);

	long long sum = 0;
	REP(i, n) scanf("%d", a + i), sum += a[i];

	REP(i, n) ++m[sum - a[i]];

	long long ans;
	for (auto it = m.begin(); it != m.end(); ++it) {
		if (it->second % x == 0) {
			m[it->first + 1] += it->second / x;
		} else {
			ans = it->first;
			break;
		}
	}

	printf("%d\n", get_pow(x, min(ans, sum)));
	return 0;
}
