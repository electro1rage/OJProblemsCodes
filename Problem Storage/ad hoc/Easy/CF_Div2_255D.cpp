#include <bits/stdc++.h>
using namespace std;

int h;

long long top_bottom(long long n) {
	return n * n;
}

long long sum(long long s, long long e) {
	return (e * (e + 1) / 2) - (s * (s + 1) / 2);
}

long long left_right(long long n, long long x) {
	int s = max(0LL, n - x);
	int e = max(0LL, n - h + x - 1);
	return sum(s, n) + sum(e, n - 1);
}

int main() {
	int x, y, c;
	scanf("%d %d %d %d", &h, &x, &y, &c);

	for (long long t = 0; t <= 100000; ++t) {
		int outtop = max(0LL, 1 - x + t);
		int outbottom = max(0LL, x + t - h);
		int outright = max(0LL, y + t - h);
		int outleft = max(0LL, 1 - y + t);

		if (1 + 2 * t * (t + 1) - top_bottom(outtop) - top_bottom(outbottom) - left_right(outright, x) - left_right(outleft, x) >= c) {
			printf("%d\n", t);
			return 0;
		}
	}

	printf("Kawaii");
	return 0;
}





