#include <bits/stdc++.h>
using namespace std;

const int MN = 20000001;

bool is_pal(int a) {
	if (a % 10 == 0) return false;
	int b = 0, ta = a;
	while (a) b = b * 10 + a % 10, a /= 10;
	a = ta;
	while (a) {
		if (a % 10 != b % 10) return false;
		a /= 10, b /= 10;
	}
	return true;
}

bool notprime[MN];

int main() {
	int p, q, i, j;
	scanf("%d %d", &p, &q);

	notprime[1] = true;
	for (i = 2; i * i < MN; ++i) {
		if (!notprime[i]) {
			for (j = i * i; j < MN; j += i) notprime[j] = true;
		}
	}

	int ctr1 = 0, ctr2 = 0, ans = -1;
	for (i = 1; i < MN; ++i) {
		ctr1 += is_pal(i);
		if (!notprime[i]) ++ctr2;
		if (1LL * ctr2 * q <= 1LL * ctr1 * p) ans = i;
	}

	if (ans != -1) printf("%d\n", ans);
	else puts("Palindromic tree is better than splay tree");
	return 0;
}
