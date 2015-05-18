#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)

const int MN = 90;
const int MVAL = 2000001000;

int memo[MN][MN];
int n, m;
int a[25], b[25];
int len;

int get_mini(int i, int c) {
	if (c < 0) return MVAL;
	if (i == len) {
		if (c == 0) return 0;
		return MVAL;
	}

	int &ret = memo[i][c];
	if (ret == -1) {
		ret = MVAL;
		ret = min(ret, min(get_mini(i + 1, c + 1) + a[i % n], get_mini(i + 1, c - 1) + b[i % n]));
	}
	return ret;
}

int main() {
	scanf("%d %d", &n, &m);

	int i;
	REP(i, n) scanf("%d", a + i);
	REP(i, n) scanf("%d", b + i);

	memset(memo, -1, sizeof memo);

	if (n % 2) len = 2 * n, m /= 2;
	else len = n;

	int ans = get_mini(0, 0);

	memset(memo, -1, sizeof memo);

	len *= 2;
	int nans = get_mini(0, 0);

	int diff = nans - ans;

	printf("%d\n", ans + (m - 1) * diff);
	return 0;
}
