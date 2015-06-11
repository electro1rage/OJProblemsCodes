#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for((i)=0;(i)<(int)(n);++(i))

const int MN = 5050;

int ans[MN];
int prime[15] = {2, 3, 5, 7, 11, 13};
int b[32];

int get_max(int n) {
	return 2 * n * n;
}

int main() {
	int n, i, j, k, l, r;
	scanf("%d", &n);

	vector<int> v[32];
	for (i = 0; ; ++i) {
		long long x = 1LL << i;
		if (x > get_max(n)) break;

		for (j = 0; ; ++j, x *= 3) {
			long long y = x;
			if (y > get_max(n)) break;

			for (k = 0; ; ++k, y *= 5) {
				long long z = y;
				if (z > get_max(n)) break;

				for (l = 0; ; ++l, z *= 7) {
					long long a = z;
					if (a > get_max(n)) break;

					for (r = 0; ; ++r, a *= 11) {
						if (a > get_max(n)) break;

						int c = 0;
						if (i) c |= 1;
						if (j) c |= 2;
						if (k) c |= 4;
						if (l) c |= 8;
						if (r) c |= 16;

						v[c].push_back(a);
					}
				}
			}
		}
	}

	int c;
	if (n <= 60) c = 4;
	else if (n <= 400) c = 8;
	else if (n <= 2000) c = 16;
	else c = 32;

	int m = 0;
	while (m < n) {
		for (i = 1; i < c; ++i) {
			if (b[i] == v[i].size()) continue;
			if (m < n) ans[m] = v[i][b[i]++], ++m;
		}
	}

	REP(i, n) {
		if (i) putchar(' ');
		printf("%d", ans[i]);
	}
	puts("");
	return 0;
}
