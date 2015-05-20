#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for((i)=0;(i)<(int)(n);++(i))

const int MN = 1000010;

char s[MN];

int main() {
	scanf("%s", s);
	int n, i;
	n = strlen(s);

	int ans = 0, boys = 0;
	REP(i, n) {
		if (s[i] == 'M') ++boys;
		else {
			if (!boys) continue;
			ans = max(ans + 1, boys);
		}
	}

	printf("%d\n", ans);
	return 0;
}
