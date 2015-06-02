#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for((i)=0;(i)<(int)(n);++(i))

const int MN = 5050;

int maxi[MN][MN];
int mini[MN][MN];
int a[MN];

int main() {
	int n, i, j;
	scanf("%d", &n);

	REP(i, n) scanf("%d", a + i);

	REP(i, n) {
		for (int j = 1; j < n; ++j) maxi[i][j] = maxi[i][j - 1] + (a[j - 1] > i);
		for (int j = n - 2; j >= 0; --j) mini[i][j] = mini[i][j + 1] + (a[j + 1] < i);
	}

	int swaps = 0;
	REP(i, n) swaps += mini[a[i]][i];

	int ans = swaps, ctr = 0;
	REP(i, n) REP(j, n) {
		if (i >= j || (i < j && a[i] < a[j])) continue;
		swaps -= mini[a[i]][i];
		swaps -= maxi[a[i]][i];
		swaps -= mini[a[j]][j];
		swaps -= maxi[a[j]][j];

		swaps += mini[a[i]][j];
		swaps += maxi[a[i]][j];
		swaps += mini[a[j]][i];
		swaps += maxi[a[j]][i];

		if (swaps + 1 < ans) {
			ans = swaps + 1, ctr = 1;
		} else if (swaps + 1 == ans) ++ctr;

		swaps -= mini[a[i]][j];
		swaps -= maxi[a[i]][j];
		swaps -= mini[a[j]][i];
		swaps -= maxi[a[j]][i];


		swaps += mini[a[i]][i];
		swaps += maxi[a[i]][i];
		swaps += mini[a[j]][j];
		swaps += maxi[a[j]][j];
	}

	printf("%d %d\n", ans, ctr);
	return 0;
}
