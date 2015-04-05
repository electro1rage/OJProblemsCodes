#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;

int a[MAXN];
int b[MAXN];

int main() {
	int n, q;
	scanf("%d %d", &n, &q);

	for (int i = 0; i < n; ++i) scanf("%d", a + i);

	sort(a, a + n);
	reverse(a, a + n);

	for (int i = 0; i < q; ++i) {
		int l, r;
		scanf("%d %d", &l, &r);
		++b[l - 1], --b[r];
	}

	int sum = 0;
	for (int i = 0; i < n; ++i) {
		sum += b[i];
		b[i] = sum;
	}

	sort(b, b + n);
	reverse(b, b + n);

	long long ans = 0;
	for (int i = 0; i < n; ++i) {
		ans += 1LL * a[i] * b[i];
	}

	cout << ans << endl;
	return 0;
}





