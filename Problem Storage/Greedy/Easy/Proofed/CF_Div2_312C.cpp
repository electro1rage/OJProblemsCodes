#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k;
	scanf("%d %d", &n, &k);

	if (n * (n - 1) / 2 <= k) {
		puts("no solution");
		return 0;
	}

	for (int i = 0; i < n; ++i)
		printf("101 %d\n", i);
	return 0;
}
