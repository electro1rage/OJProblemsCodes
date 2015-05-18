#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)

int a[3010];

int main() {
	int n;
	scanf("%d", &n);

	int i;
	REP(i, n) scanf("%d", a + i);

	int ans = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n - 1; ++j) {
			if (a[j] > a[j + 1]) ++ans, swap(a[j], a[j + 1]);
		}
	}

	printf("%d.000000\n", (ans + 1) / 2 + ans / 2 * 3);
	return 0;
}
