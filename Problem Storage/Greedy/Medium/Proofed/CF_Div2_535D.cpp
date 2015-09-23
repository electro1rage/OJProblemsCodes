#include <bits/stdc++.h>
using namespace std;

const int MN = 1010101, MOD = 1000000007;

char s[MN];
char p[MN];
int a[MN];

bool valid(int n, int m, int sz) {
	if (!m) return true;
	int i, j, k;
	vector<int> pre(sz);
	for (i = 1, k = 0; i < sz; ++i) {
		while (k && p[k] != p[i]) k = pre[k - 1];
		if (p[k] == p[i]) ++k;
		pre[i] = k;
	}

	for (i = 0, j = 0, k = 0; i < n; ++i) {
		while (k && p[k] != s[i]) k = pre[k - 1];
		if (p[k] == s[i]) ++k;
		if (k == sz) {
			if (i - sz + 1 == a[j]) ++j;
			k = pre[k - 1];
		}
		if (j == m) return true;
	}

	return false;
}

int main() {
	int n, m, sz, i, j, k;
	scanf("%d %d", &n, &m);
	scanf("%s", p);
	sz = strlen(p);
	for (i = 0; i < m; ++i) scanf("%d", a + i), --a[i];

	for (i = 0, j = 0, k = 0; i < n; ++i) {
		if (k < m && i == a[k]) ++k, j = sz;
		if (j) s[i] = p[sz - j], --j;
		else s[i] = 'X';
	}

	if (!valid(n, m, sz)) {
		puts("0");
		return 0;
	}

	int ans = 1;
	for (i = 0; i < n; ++i) if (s[i] == 'X') ans = (ans * 26LL) % MOD;
	printf("%d\n", ans);
	return 0;
}
