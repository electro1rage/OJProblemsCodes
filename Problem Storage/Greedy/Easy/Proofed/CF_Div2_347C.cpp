#include <bits/stdc++.h>
using namespace std;

int a[105];

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; ++i) scanf("%d", a + i);

	sort(a, a + n);

	int gcd = a[0];
	for (int i = 1; i < n; ++i) gcd = __gcd(gcd, a[i]);

	if ((n - (a[n - 1] / gcd)) % 2) {
		puts("Alice");
	} else puts("Bob");
	return 0;
}
