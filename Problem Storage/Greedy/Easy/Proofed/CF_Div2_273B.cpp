#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;

map<int, int> m;

int a[MAXN];
int p, MOD;

long long fact(int x) {
	long long ret = 1;
	for (int i = 2; i <= x; ++i) {
		if (p && i % 2 == 0) {
			--p;
			ret = (ret * i / 2) % MOD;
			continue;
		}
		ret = (ret * i) % MOD;
	}
	return ret;
}

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
		++m[a[i]];
	}

	for (int i = 0; i < n; ++i) {
		int x;
		scanf("%d", &x);
		if (x == a[i]) ++p;
		++m[x];
	}

	scanf("%d", &MOD);

	int ans = 1;
	for (auto &x : m) {
		ans = (ans * fact(x.second)) % MOD;
	}

	printf("%d\n", ans);
	return 0;
}






