#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, l, x, y, i;
	scanf("%d %d %d %d", &n, &l, &x, &y);
	vector<int> a(n);
	for (i = 0; i < n; ++i) scanf("%d", &a[i]);

	bool good[2] = {};
	for (i = 0; i < n; ++i) {
		if (binary_search(a.begin(), a.end(), a[i] + x)) good[0] = true;
		if (binary_search(a.begin(), a.end(), a[i] + y)) good[1] = true;
	}

	if (good[0] && good[1]) {
		puts("0");
		return 0;
	}

	if (good[0]) {
		puts("1");
		printf("%d\n", y);
		return 0;
	}

	if (good[1]) {
		puts("1");
		printf("%d\n", x);
		return 0;
	}

	for (i = 0; i < n; ++i) {
		if (1LL * a[i] + 1LL * x + 1LL * y <= l && binary_search(a.begin(), a.end(), a[i] + x + y)) {
			puts("1");
			printf("%d\n", a[i] + x);
			return 0;
		}
	}

	for (i = 0; i < n; ++i) {
		if (binary_search(a.begin(), a.end(), a[i] + y - x)) {
			if (a[i] - x >= 0) {
				puts("1");
				printf("%d\n", a[i] - x);
				return 0;
			}
			if (a[i] + y <= l) {
				puts("1");
				printf("%d\n", a[i] + y);
				return 0;
			}
		}
	}

	puts("2");
	printf("%d %d\n", x, y);
	return 0;
}
