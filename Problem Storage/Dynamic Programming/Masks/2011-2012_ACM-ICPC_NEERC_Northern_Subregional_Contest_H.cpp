#include <bits/stdc++.h>
using namespace std;

const int MN = 50505;

char s[MN][7];
int ans[6], dp[1 << 5];

int ones(int x) {
	return __builtin_popcount(x);
}

void utf(int a[], int s, int e) {
	if (s + 1 == e) return;
	int mid = (s + e) / 2, len = mid - s, i;
	for (i = 0; i < len; ++i) a[mid + i] -= a[s + i];
	utf(a, s, mid), utf(a, mid, e);
}

int main() {
	freopen("high.in", "r", stdin);
	freopen("high.out", "w", stdout);
	int n, i, j, k;
	scanf("%d", &n);
	for (i = 0; i < n; ++i) scanf("%s", s[i]);

	for (i = 0; i < (1 << 5); ++i) {
		vector<string> a;
		int curmask = i, sz = 1, cursum = 0;
		for (j = 0; j < n; ++j) {
			string temp = "";
			for (k = 0; k < 5; ++k) {
				if ((curmask >> k) & 1) continue;
				temp += s[j][k];
			}
			a.push_back(temp);
		}
		sort(a.begin(), a.end());
		for (j = 1; j < n; ++j) {
			if (a[j] != a[j - 1]) {
				cursum += 1LL * sz * (sz - 1) / 2, sz = 1;
			} else ++sz;
		}
		cursum += 1LL * sz * (sz - 1) / 2;

		dp[i] = cursum;
	}

	utf(dp, 0, 1 << 5);

	for (i = 0; i < (1 << 5); ++i) ans[ones(i)] += dp[i];

	for (i = 0; i < 6; ++i) {
		if (i) putchar(' ');
		printf("%d", ans[i]);
	}
	puts("");
	return 0;
}
