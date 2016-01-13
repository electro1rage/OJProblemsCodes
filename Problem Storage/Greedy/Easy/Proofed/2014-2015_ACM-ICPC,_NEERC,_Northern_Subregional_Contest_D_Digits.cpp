/*
reality, be rent!
synapse, break!
Van!shment Th!s World !!
*/
#include <bits/stdc++.h>
using namespace std;

int get_sum(int x) {
	int ret = 0;
	while (x) ret += x % 10, x /= 10;
	return ret;
}

int cnt[7654322];
long long sum[7654322];

int main() {
	freopen("digits.in", "r", stdin);
	freopen("digits.out", "w", stdout);
	int n, i;
	scanf("%d", &n);

	long long ans = 1000000000;
	for (i = 1; i <= 7654321; ++i) {
		int res = get_sum(i);
		++cnt[res];
		sum[res] += i;
		if (cnt[res] == n) {
			ans = min(ans, sum[res]);
		}
	}
	printf("%I64d\n", ans);
	return 0;
}
