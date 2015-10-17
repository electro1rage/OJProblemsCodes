/*
reality, be rent!
synapse, break!
Van!shment Th!s World !!
*/
#include <bits/stdc++.h>
using namespace std;

const int MN = 202020;
int a[MN];
int acum[MN];

int main() {
	int n, i;
	scanf("%d", &n);
	for (i = 1; i <= n; ++i) scanf("%d", a + i);
	for (i = 1; i <= n; ++i) acum[i] = a[i] + acum[i - 1];
	long long ans = 0;
	for (i = n; i > 0; --i) if (a[i] == 0) ans += acum[i];
	printf("%I64d\n", ans);
	return 0;
}
