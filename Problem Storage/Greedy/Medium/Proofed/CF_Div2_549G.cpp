#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for((i)=0;(i)<(int)(n);++(i))

const int MN = 202020;

struct data {
	int val, final, pos;
};

bool cmp_final(data a, data b) {
	return a.final > b.final;
}

data a[MN];

int main() {
	int n;
	scanf("%d", &n);

	int i, x;
	REP(i, n) scanf("%d", &x), a[n - i - 1] = {x, x - (n - i - 1), n - i - 1};

	sort(a, a + n, cmp_final);

	REP(i, n) if (i && a[i].final == a[i - 1].final) {
		puts(":(");
		return 0;
	}

	reverse(a, a + n);

	REP(i, n) {
		if (i) printf(" ");
		printf("%d", a[i].val + (n - i - 1) - a[i].pos);
	}
	puts("");

	return 0;
}
