#include <bits/stdc++.h>
using namespace std;

bool good[1 << 23];
int i2j[23][23];
int a[23];

int ones(int mask) {
	int res = 0;
	while (mask) {
		mask = mask & (mask - 1);
		++res;
	}
	return res;
}

int one(int mask, int i) {
	return (mask >> i) & 1;
}

bool is_good(int &mask, int j) {
	for (int i = 0; i < 22; ++i) {
		if (one(mask, i) && one(mask, i2j[j][i])) return true;
	}
	return false;
}

int main() {
	for (int i = 0; i < 23; ++i)
		for (int j = 0; j < 23; ++j)
			i2j[i][j] = 30;

	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d", a + i);

	if (n == 1) {
		puts("1");
		return 0;
	}

	for (int k = 0; k < n; ++k) {
		for (int i = 0; i < k; ++i) {
			for (int j = 0; j < k; ++j) {
				if (a[i] + a[j] == a[k]) {
					i2j[k][i] = j, i2j[k][j] = i;
				}
			}
		}
	}

	int ans = 25;
	good[1] = true;
	for (int mask = 1; mask < (1 << (n - 1)); ++mask) {
		if (!good[mask]) continue;
		int i;
		for (i = 21; i >= 0; --i) {
			if ((mask >> i) & 1) break;
		}
		++i;

		if (is_good(mask, i)) {
			if (i == n - 1) {
				ans = min(ans, ones(mask));
			}
			int tempmask = mask | (1 << i);
			good[tempmask] = true;
			for (int j = 0; j < i; ++j) {
				if ((tempmask >> j) & 1) {
					good[tempmask ^ (1 << j)] = true;
				}
			}
		}
	}

	if (ans == 25) ans = -1;
	printf("%d\n", ans);
	return 0;
}






