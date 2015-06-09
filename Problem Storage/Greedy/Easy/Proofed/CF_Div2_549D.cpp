#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for((i)=0;(i)<(int)(n);++(i))

const int MN = 110;

char a[MN][MN];
int val[MN][MN];

int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	int i, j;
	REP(i, n) scanf("%s", a[i]);

	int ans = 0;
	for (int k = n - 1; k >= 0; --k) {
		for (int l = m - 1; l >= 0; --l) {
			if ((a[k][l] == 'W' && val[k][l] != 1) || (a[k][l] == 'B' && val[k][l] != -1)) {
				++ans;
				int add;
				if (a[k][l] == 'W') add = 1 - val[k][l];
				else add = -1 - val[k][l];

				REP(i, k + 1) REP(j, l + 1) val[i][j] += add;
			}
		}
	}

	printf("%d\n", ans);
	return 0;
}
