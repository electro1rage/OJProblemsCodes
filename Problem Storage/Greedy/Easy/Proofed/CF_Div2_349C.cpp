#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)

const int MN = 100005;

int a[MN];

int main() {
	int n, i;
	scanf("%d", &n);

	long long sum = 0;
	REP(i, n) scanf("%d", a + i), sum += a[i];

	sort(a, a + n);

	int ans = (sum + n - 2) / (n - 1);
	printf("%d\n", max(ans, a[n - 1]));
	return 0;
}
