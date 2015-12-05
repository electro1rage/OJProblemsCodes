/*
reality, be rent!
synapse, break!
Van!shment Th!s World !!
*/
#include <bits/stdc++.h>
using namespace std;

const int MN = 1010101, MOD = 1000000007;

bool vst[MN];

int main() {
	int p, k, ans = 1, cnt, one = 0, i, j;
	scanf("%d %d", &p, &k);

	if (k == 0) {
		for (i = 0; i < p - 1; ++i) ans = (1LL * ans * p) % MOD;
		printf("%d\n", ans);
		return 0;
	}

	for (i = 0; i < p; ++i) {
		if ((1LL * k * i) % p == i) ++one;
	}

	for (i = 0; i < p; ++i) {
		if (vst[i]) continue;
		cnt = 1;
		for (j = (1LL * k * i) % p; j != i; j = (1LL * k * j) % p) vst[j] = true, ++cnt;
		if (cnt == 1) ans = (1LL * ans * one) % MOD;
		else ans = (1LL * ans * p) % MOD;
	}

	printf("%d\n", ans);
	return 0;
}
