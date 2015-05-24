#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for((i)=0;(i)<(int)(n);++(i))

const int MN = 300010;

int a[MN];

int main() {
	int n, k, i, j;
	scanf("%d %d", &n, &k);

	REP(i, n) scanf("%d", a + i);

	sort(a, a + n);

	int maxi = a[n - 1], mini = a[0];

	int ans = 1;
	REP(i, mini + 1) {
		if (!i) continue;
		int start = 0;
		for (j = i; ; j += i) {
			int pre = j - i;
			if (a[start] >= j) continue;
			int ind = lower_bound(a + start, a + n, j) - a; --ind;

			if (pre + k < a[ind]) break;

			start = ind + 1;

			if (j > maxi || start == n) break;
		}
		if (start == n) ans = i;
	}

	printf("%d\n", ans);
	return 0;
}
