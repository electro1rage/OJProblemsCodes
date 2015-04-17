#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;

int a[MAXN], b[MAXN];
int all[2 * MAXN];

int main() {
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);

	int i, j;

	for (i = 0; i < n; ++i) scanf("%d", a + i);
	for (i = 0; i < m; ++i) scanf("%d", b + i);

	sort(a, a + n);
	sort(b, b + m);

	for (i = 0; i < n; ++i) all[i] = a[i];
	for (j = 0; j < m; ++j, ++i) all[i] = b[j];

	sort(all, all + n + m);

	for (i = 0; i < n + m; ++i) {
		int countalice = lower_bound(a, a + n, all[i]) - a;
		countalice = n - countalice;
		int countbob = lower_bound(b, b + m, all[i]) - b;
		countbob = m - countbob;

		if (countalice > countbob) {
			puts("YES");
			return 0;
		}
	}
	puts("NO");
	return 0;
}




