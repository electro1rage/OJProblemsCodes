#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for((i)=0;(i)<(int)(n);++(i))

const int MN = 101010;

int b[MN];
int p[MN];

int get_cost(int a, int n) {
	int i;
	long long sum = 0;
	REP(i, n) {
		if (p[i] > b[n - i - 1]) {
			a -= p[i] - b[n - i - 1];
			sum += b[n - i - 1];
		} else sum += p[i];
		if (a < 0) return -1;
	}
	return max(sum - a, 0LL);
}

int main() {
	int n, m, a, i;
	scanf("%d %d %d", &n, &m, &a);

	REP(i, n) scanf("%d", b + i);
	REP(i, m) scanf("%d", p + i);

	sort(p, p + m);
	sort(b, b + n);
	reverse(b, b + n);

	int s = 0, e = min(n, m);
	int ans = -1, cost = -1;
	while (s <= e) {
		int mid = (s + e) / 2;
		int curcost = get_cost(a, mid);
		if (curcost < 0) e = mid - 1;
		else ans = mid, cost = curcost, s = mid + 1;
	}

	printf("%d %d\n", ans, cost);
	return 0;
}
