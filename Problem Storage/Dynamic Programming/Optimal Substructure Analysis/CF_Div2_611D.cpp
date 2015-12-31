/*
reality, be rent!
synapse, break!
Van!shment Th!s World !!
*/
#include <bits/stdc++.h>
using namespace std;

const int MN = 5050, MOD = 1000000007;

int d[MN][MN];
int sum[MN][MN];
char s[MN];

int main() {
	int n, len, i, j, k;
	scanf("%d", &n);
	scanf("%s", s + 1);

	for (i = n; i > 0; --i) {
		for (j = n; j > 0; --j) if (s[i] == s[j]) d[i][j] = 1 + d[i + 1][j + 1];
	}

	for (j = 1; j <= n; ++j) {
		for (i = j; i >= 1; --i) {
			if (s[i] == '0') {
				sum[i][j] = sum[i + 1][j];
				continue;
			}
			if (i == 1) {
				sum[i][j] = (sum[i + 1][j] + 1) % MOD;
				continue;
			}

			k = i - 1 - (j - i);
			if (k >= 1) {
				len = d[i][k];
				if (len >= (j - i + 1)) ++k;
				else if (s[k + len] > s[i + len]) ++k;
			} else k = 1;

			sum[i][j] = (sum[k][i - 1] + sum[i + 1][j]) % MOD;
		}
	}

	printf("%d\n", sum[1][n]);
	return 0;
}
