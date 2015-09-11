#include <bits/stdc++.h>
using namespace std;

const int MN = 1000006;

int a[MN];
bool dp[1010];

int main() {
	int n, m, i, j;
	scanf("%d %d", &n, &m);
	for (i = 0; i < n; ++i) scanf("%d", a + i);
	for (i = 0; i < n; ++i) {
		if (a[i] % m == 0) {
			puts("YES");
			return 0;
		}
		a[i] %= m;
	}
	dp[0] = true;
	for (i = 0; i < n; ++i) {
		bool temp[1010] = {};
		for (j = m; j >= 0; --j) {
			if (dp[j]) {
				if (j + a[i] == m) {
					puts("YES");
					return 0;
				}
				temp[(j + a[i]) % m] = true;
			}
		}
		for (j = 0; j < m; ++j) dp[j] |= temp[j];
	}
	puts("NO");
	return 0;
}
