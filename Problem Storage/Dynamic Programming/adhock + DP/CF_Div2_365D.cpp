#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for((i)=0;(i)<(int)(n);++(i))

const int MN = 50;
const int MVAL = 500000;
const int MM = 505050;

bool can[MM];

int main() {
	int n, d;
	scanf("%d %d", &n, &d);

	can[0] = true;

	int i, j;
	REP(i, n) {
		int a;
		scanf("%d", &a);
		for (j = MVAL; j >= 0; --j) {
			if (can[j] && j + a <= MVAL) can[j + a] = true;
		}
	}

	int ans = 0, days = 0;
	while (true) {
		int cur = ans;
		for (i = cur + 1; i <= ans + d && i <= MVAL; ++i)
			if (can[i]) cur = i;
		if (cur == ans) break;
		ans = cur;
		++days;
	}

	cout << ans << ' ' << days << endl;
	return 0;
}
