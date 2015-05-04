#include <bits/stdc++.h>
using namespace std;

const int MN = 1005;

bool badx[MN], bady[MN];

int main() {
	int n, m; scanf("%d %d", &n, &m);

	for (int i = 0; i < m; ++i) {
		int x, y;
		scanf("%d %d", &x, &y); --x, --y;
		badx[x] = true, bady[y] = true;
	}

	int ans = 0;
	for (int x = 1; x < n - 1; ++x) {
		int cur = !badx[x] + !bady[x];
		if (n % 2 && n / 2 == x) cur = min(cur, 1);
		ans += cur;
	}

	printf("%d\n", ans);
	return 0;
}
