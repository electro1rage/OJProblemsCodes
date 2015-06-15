#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for((i)=0;(i)<(int)(n);++(i))

map<int, int> fb, fa;

const int MN = 202020;

int a[MN];
vector<int> ans;
int n, m, p;

void add(int x, int &good) {
	++fa[x];
	if (fb.count(x) && fa[x] <= fb[x]) ++good;
}

void take(int x, int &good) {
	--fa[x];
	if (fb.count(x) && fa[x] < fb[x]) --good;
}

void get_ans(int i) {
	int j, k, good = 0;
	fa.clear();
	if (i + 1LL * (m - 1) * p >= n) return ;
	for (j = 0, k = i; j < m; ++j, k += p) {
		add(a[k], good);
	}

	if (good == m) ans.push_back(i);

	for (j = i; k < n; j += p, k += p) {
		take(a[j], good);
		add(a[k], good);
		if (good == m) ans.push_back(j + p);
	}
}

int main() {
	int x, i;
	scanf("%d %d %d", &n, &m, &p);

	REP(i, n) scanf("%d", a + i);
	REP(i, m) scanf("%d", &x), ++fb[x];

	REP(i, p) get_ans(i);

	sort(ans.begin(), ans.end());

	printf("%d\n", (int)ans.size());
	REP(i, ans.size()) {
		if (i) putchar(' ');
		printf("%d", ans[i] + 1);
	}
	puts("");

	return 0;
}
