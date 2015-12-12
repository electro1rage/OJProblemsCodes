/*
reality, be rent!
synapse, break!
Van!shment Th!s World !!
*/
#include <bits/stdc++.h>
using namespace std;

const int MN = 1010101;

long long x[MN], y[MN];
int a[MN];

int main() {
	int n, m, len, i, j;
	scanf("%d %d", &n, &m);
	for (i = 0; i < n; ++i) scanf("%d", a + i);

	for (i = 0; i < n; ++i) {
		if (i - m < 0) x[i] = a[i] - a[0];
		else {
			len = i;
			if (len % m != 0) j = i - len % m, len = len / m;
			else j = i - m, len = len / m - 1;
			x[i] = x[j] + 1LL * (a[i] - a[j]) * (len + 1);
		}
	}

	for (i = n - 1; i >= 0; --i) {
		if (i + m >= n) y[i] = a[n - 1] - a[i];
		else {
			len = n - 1 - i;
			if (len % m != 0) j = i + len % m, len = len / m;
			else j = i + m, len = len / m - 1;
			y[i] = y[j] + 1LL * (a[j] - a[i]) * (len + 1);
		}
	}

	long long ans = 404040404040404040;
	for (i = 0; i < n; ++i) ans = min(ans, x[i] + y[i]);

	printf("%I64d\n", 2 * ans);
	return 0;
}
