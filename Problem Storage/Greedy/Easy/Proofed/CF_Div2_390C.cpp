/*
reality, be rent!
synapse, break!
Van!shment Th!s World !!
*/
#include <bits/stdc++.h>
using namespace std;

const int MK = 11, MN = 101010;

int a[MK][MN];
char s[MN];

int main() {
	int n, k, w, l, r, i, j;
	scanf("%d %d %d", &n, &k, &w);
	scanf("%s", s);
	for (i = 0; i < k; ++i) {
		for (j = 0; j <= n; ++j) {
			char c = s[j];
			if (j) a[i][j] = a[i][j - 1];
			if ((j - i) % k == 0) a[i][j] += c == '0';
			else a[i][j] += c == '1';
		}
	}

	for (i = 0; i < w; ++i) {
		scanf("%d %d", &l, &r);
		--l, --r;
		j = (l + k - 1) % k;
		printf("%d\n", (l ? a[j][r] - a[j][l - 1] : a[j][r]));
	}
	return 0;
}
