#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for((i)=0;(i)<(int)(n);++(i))

int a[100010];
char s[100010];

int main() {
	int n, i;
	scanf("%d", &n);

	REP(i, n) scanf("%d", a + i);

	scanf("%s", s);

	int l = 0, r = 0;
	REP(i, n) if (s[i] == '1') r += a[i];

	int ans = r;
	REP(i, n) {
		if (s[i] == '1') {
			r -= a[i];
			ans = max(ans, l + r);
		}
		l += a[i];
	}

	printf("%d\n", ans);
	return 0;
}
