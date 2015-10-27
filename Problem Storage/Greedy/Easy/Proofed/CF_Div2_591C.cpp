/*
reality, be rent!
synapse, break!
Van!shment Th!s World !!
*/
#include <bits/stdc++.h>
using namespace std;

const int MN = 505050;

int a[MN];

int main() {
	int n, i, j, k, l;
	scanf("%d", &n);
	for (i = 0; i < n; ++i) scanf("%d", a + i);

	int ans = 0;
	for (i = 0; i < n; i = j) {
		for (j = i; j < n; ++j) {
			bool dist = (j - i) % 2;
			if (a[j] != (a[i] ^ dist)) break;
		}
		int dist = (j - i);
		ans = max(ans, (dist - 1) / 2);
		for (l = 0, k = i; l < (dist + 1) / 2; ++l, ++k) a[k] = a[i];
		for (l = 0, k = j - 1; l < dist / 2; ++l, --k) a[k] = a[j - 1];
	}

	printf("%d\n", ans);
	for (i = 0; i < n; ++i) {
		if (i) putchar(' ');
		printf("%d", a[i]);
	}
	puts("");
	return 0;
}
