#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for((i)=0;(i)<(int)(n);++(i))

const int MN = 101;

int grid[MN][MN];
char s[MN][MN];
int a[MN];
int cur[MN];
int ans[MN];

int main() {
	int n;
	scanf("%d", &n);

	int i, j;
	REP(i, n) scanf("%s", s[i]);

	REP(i, n) REP(j, n) grid[i][j] = s[i][j] - '0';

	REP(i, n) scanf("%d", a + i);

	int m = 0;

	while (true) {
		bool bad = false;
		REP(i, n) if (cur[i] == a[i]) {
			bad = true;
			j = i;
			break;
		}
		if (!bad) break;

		ans[m] = j + 1;
		REP(i, n) cur[i] += grid[j][i];
		++m;
	}

	printf("%d\n", m);
	REP(i, m) {
		if (i) printf(" ");
		printf("%d", ans[i]);
	}
	puts("");
	return 0;
}
