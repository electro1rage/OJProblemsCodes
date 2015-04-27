#include <bits/stdc++.h>
using namespace std;

const int MAXM = 100005;

int d[MAXM], h[MAXM];

int get_max(int s, int e, int cur, int he) {
	int ret = he;
	while (s <= e) {
		if (cur + (e - s) >= he && cur - (e - s) <= he) ret = max(ret, cur);
		++cur, ++s;
	}
	return ret;
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; ++i) scanf("%d %d", d + i, h + i);

	for (int i = 0; i < m - 1; ++i) {
		int diff = d[i + 1] - d[i];
		if (!(h[i] + diff >= h[i + 1] && h[i] - diff <= h[i + 1])) {
			puts("IMPOSSIBLE");
			return 0;
		}
	}

	int ans = h[0] + (d[0] - 1);
	ans = max(ans, h[m - 1] + (n - d[m - 1]));

	for (int i = 0; i < m - 1; ++i)
		ans = max(ans, get_max(d[i], d[i + 1], h[i], h[i + 1]));

	printf("%d\n", ans);
	return 0;
}






