#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for((i)=0;(i)<(int)(n);++(i))

const int MN = 5050;
const int MVAL = 2000000000;

struct data {
	int t, l, r, d;
};

int a[MN];
int b[MN];
vector<data> query;

int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	int i;
	REP(i, n) a[i] = MVAL;

	REP(i, m) {
		int t, l, r, d;
		scanf("%d %d %d %d", &t, &l, &r, &d);
		--l, --r;
		query.push_back({t, l, r, d});
		if (t == 1) {
			for (int j = l; j <= r; ++j) b[j] += d;
		} else {
			for (int j = l; j <= r; ++j) a[j] = min(a[j], d - b[j]);
		}
	}

	memcpy(b, a, sizeof a);

	REP(i, m) {
		if (query[i].t == 1) {
			for (int j = query[i].l; j <= query[i].r; ++j) a[j] += query[i].d;
		} else {
			int maxi = -MVAL;
			for (int j = query[i].l; j <= query[i].r; ++j) maxi = max(maxi, a[j]);
			if (maxi != query[i].d) {
				puts("NO");
				return 0;
			}
		}
	}

	puts("YES");
	REP(i, n) {
		if (i) printf(" ");
		if (b[i] == MVAL) {
			printf("101");
			continue;
		}
		printf("%d", b[i]);
	}
	puts("");
	return 0;
}
