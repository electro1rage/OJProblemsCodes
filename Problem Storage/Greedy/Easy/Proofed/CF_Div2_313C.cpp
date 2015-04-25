#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2000005;

int a[MAXN];

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; ++i) scanf("%d", a + i);

	sort(a, a + n); reverse(a, a + n);

	long long ans = 0;
	int m = 1;
	while (n) {
		for (int i = 0; i < m; ++i) ans += a[i];
		m *= 4, n /= 4;
	}

	printf("%I64d", ans);
	return 0;
}
