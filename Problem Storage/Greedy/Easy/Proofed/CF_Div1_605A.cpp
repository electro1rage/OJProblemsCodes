/*
reality, be rent!
synapse, break!
Van!shment Th!s World !!
*/
#include <bits/stdc++.h>
using namespace std;

const int MN = 101010;

int a[MN], b[MN];

int main() {
	int n, i;
	memset(b, -1, sizeof b);

	scanf("%d", &n);
	for (i = 0; i < n; ++i) scanf("%d", a + i);

	for (i = 0; i < n; ++i) {
		if (b[a[i] - 1] == -1) b[a[i]] = 1;
		else b[a[i]] = b[a[i] - 1] + 1;
	}

	int ans = 0;
	for (i = 1; i <= n; ++i) ans = max(ans, b[i]);

	printf("%d\n", n - ans);
	return 0;
}
