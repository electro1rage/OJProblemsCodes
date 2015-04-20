#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m, x, y, a, b;

	scanf("%d %d %d %d %d %d", &n, &m, &x, &y, &a, &b);

	int gcd = __gcd(a, b);
	a /= gcd, b /= gcd;

	int z = min(n / a, m / b);
	int xl = a * z;
	int yl = b * z;

	int xleft = xl / 2, xright, ybottom = yl / 2, ytop;
	if (xl % 2) ++xleft;
	if (yl % 2) ++ybottom;
	xright = xl - xleft, ytop = yl - ybottom;

	if (x + xright > n) {
		x = n - xright;
	} else if (x - xleft < 0) {
		x = xleft;
	}

	if (y + ytop > m) {
		y = m - ytop;
	} else if (y - ybottom < 0) {
		y = ybottom;
	}

	printf("%d %d %d %d\n", x - xleft, y - ybottom, x + xright, y + ytop);
	return 0;
}
