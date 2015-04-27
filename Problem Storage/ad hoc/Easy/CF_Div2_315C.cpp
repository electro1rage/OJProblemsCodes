#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k;
	scanf("%d %d", &n, &k);

	long long left = 0;
	long long shift = 0;

	for (int i = 0; i < n; ++i) {
		int a; scanf("%d", &a);
		if (left - (1LL * (i - shift) * (n - i - 1) * a) < k) {
			++shift;
			printf("%d\n", i + 1);
		} else {
			left += a * (i - shift);
		}
	}
	return 0;
}
