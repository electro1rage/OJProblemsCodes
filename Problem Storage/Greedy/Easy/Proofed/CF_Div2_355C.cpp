#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for((i)=0;(i)<(int)(n);++(i))

const int MN = 100010;

int w[MN];

int get_ans(int a, int b, int l, int r) {
	if (abs(a - b) <= 1) return 0;
	if (a > b) return (a - b - 1) * l;
	return (b - a - 1) * r;
}

int main() {
	int n, l, r, ql, qr, i;
	scanf("%d %d %d %d %d", &n, &l, &r, &ql, &qr);


	int suml = 0, sumr = 0;
	REP(i, n) scanf("%d", w + i), sumr += w[i] * r;

	int ans = sumr + get_ans(0, n, 101, qr);
	REP(i, n) {
		suml += w[i] * l, sumr -= w[i] * r;
		ans = min(ans, suml + sumr + get_ans(i + 1, n - i - 1, ql, qr));
	}

	printf("%d\n", ans);
	return 0;
}
