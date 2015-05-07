#include <bits/stdc++.h>
using namespace std;

const int MN = 100005;

int a[MN];

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; ++i) scanf("%d", a + i);

	sort(a, a + n);

	long long num = 0, den = n;
	for (int i = 0; i < n - 1; ++i) {
		num += 1LL * abs(a[i] - a[i + 1]) * (n - i - 1) * (i + 1);
	}

	num *= 2;
	num += accumulate(a, a + n, 0LL);

	long long gcd = __gcd(num, den);
	den /= gcd, num /= gcd;

	cout << num << ' ' << den << endl;
	return 0;
}
