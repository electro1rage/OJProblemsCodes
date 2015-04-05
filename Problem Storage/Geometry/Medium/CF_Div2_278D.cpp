#include <bits/stdc++.h>
using namespace std;

const int SHIFT = 10000000;

int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	if (m == 3) {
		if (n == 3) {
			puts("0 0");
			puts("0 1");
			puts("1 0");
			return 0;
		}
		if (n == 4) {
			puts("0 0");
			puts("100 0");
			puts("0 100");
			puts("5 5");
			return 0;
		}
		puts("-1");
		return 0;
	}

	for (int i = 0; i < m; ++i) {
		printf("%d %d\n", i, SHIFT + i * i);
	}
	for (int i = 0; i < n - m; ++i) {
		printf("%d %d\n", i, -SHIFT - i * i);
	}
	return 0;
}




