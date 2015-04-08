#include <bits/stdc++.h>
using namespace std;

const int MAXN = 300005;

int a[MAXN];

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; ++i) scanf("%d", a + i);

	sort(a + 1, a + n + 1);

	long long ans = 0;
	for (int i = 1; i <= n; ++i) {
		ans += abs(i - a[i]);
	}

	cout << ans << endl;
	return 0;
}





