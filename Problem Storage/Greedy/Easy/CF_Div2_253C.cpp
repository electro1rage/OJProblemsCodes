#include <bits/stdc++.h>
using namespace std;

int a[100005];

int left_right(int a, int b) {
	return abs(a - b);
}

int top_down(int r1, int r2, int &c1) {
	int mn = c1;
	if (r1 > r2) swap(r1, r2);

	for (int i = r1; i <= r2; ++i)
		mn = min(mn, a[i] + 1);

	c1 = mn;
	return abs(r1 - r2);
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; ++i)
		scanf("%d", a + i);

	int r1, c1, r2, c2;
	scanf("%d %d %d %d", &r1, &c1, &r2, &c2);

	int res = 1000000000;
	for (int i = 1; i <= n; ++i) {
		int tc = c1;
		res = min(res, top_down(r1, i, tc) + top_down(i, r2, tc) + left_right(tc, c2));
	}

	printf("%d\n", res);
	return 0;
}
