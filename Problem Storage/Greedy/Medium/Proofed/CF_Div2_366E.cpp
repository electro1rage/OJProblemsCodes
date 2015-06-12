#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for((i)=0;(i)<(int)(n);++(i))

const int MK = 10;
const int MVAL = 1000000000;

int maxtl[MK], maxbr[MK], maxtr[MK], maxbl[MK];

int main() {
	int n, m, k, s, i, j, x;
	scanf("%d %d %d %d", &n, &m, &k, &s);

	REP(i, k + 1) maxtl[i] = maxtr[i] = maxbl[i] = maxbr[i] = -MVAL;

	REP(i, n) REP(j, m) {
		scanf("%d", &x); --x;
		maxtl[x] = max(maxtl[x], -i - j);
		maxtr[x] = max(maxtr[x], -i + j);
		maxbl[x] = max(maxbl[x], i - j);
		maxbr[x] = max(maxbr[x], i + j);
	}

	int ans = 0;
	int pre, cur;
	scanf("%d", &pre); --pre;
	REP(i, s) if (i) {
		scanf("%d", &cur); --cur;
		ans = max(ans, maxtl[pre] + maxbr[cur]);
		ans = max(ans, maxtl[cur] + maxbr[pre]);
		ans = max(ans, maxtr[cur] + maxbl[pre]);
		ans = max(ans, maxtr[pre] + maxbl[cur]);
		pre = cur;
	}

	printf("%d\n", ans);
	return 0;
}
