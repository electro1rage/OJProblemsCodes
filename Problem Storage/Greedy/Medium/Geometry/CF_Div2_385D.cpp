/*
reality, be rent!
synapse, break!
Van!shment Th!s World !!
*/
#include <bits/stdc++.h>
using namespace std;

#define eps 1e-9
#define PIE 3.141592654

int x[20], y[20], a[20];
int n, l, r;
double dp[1 << 20];

int main() {
	int n, l, r, i, j;
	scanf("%d %d %d", &n, &l, &r);
	for (i = 0; i < n; ++i) scanf("%d %d %d", x + i, y + i, a + i);
	for (i = 0; i < (1 << n); ++i) {
		dp[i] = l;
		for (j = 0; j < n; ++j) {
			double x1, y1, x2, y2;
			if ((i >> j) & 1) {
				x1 = dp[i ^ (1 << j)] - x[j];
				y1 = -y[j];

				x2 = x1 * cos(a[j] * PIE / 180) - y1 * sin(a[j] * PIE / 180);
				y2 = x1 * sin(a[j] * PIE / 180) + y1 * cos(a[j] * PIE / 180);

				if (y2 >= 0) {
					dp[i] = r;
				} else dp[i] = max(dp[i], x[j] - y[j] / y2 * x2);
			}
		}
	}
	dp[(1 << n) - 1] = min(dp[(1 << n) - 1], (double)r);
	printf("%.6lf\n", dp[(1 << n) - 1] - l);
	return 0;
}
