#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)

const int MN = 100010;
const int MD = 1000010;

struct state {
	int l, r, val;
};

int a, b, d;
int n;
int x[MN];
int nextt[MD], jump[MD];

void get_jump(int x) {
	int init = 0;
	if (a % x) init = a - a % x + x - a;
	for (int i = init; i < d; i += x) jump[i] = max(jump[i], x - 1);
}

int main(void){
	scanf("%d", &n);

	int i;
	REP(i, n) scanf("%d", x + i);

	scanf("%d %d", &b, &a);

	d = b - a + 1;

	REP(i, d) jump[i] = 1;

	sort(x, x + n);
	REP(i, n) if (i == 0 || x[i] != x[i - 1]) get_jump(x[i]);

	int cur = jump[0];
	vector<state> pre {{1, jump[0], 0}};
	for (int i = 1; i < d && cur < d; ++i) {
		if (cur >= i + 1 && cur < i + jump[i]) pre.push_back({cur + 1, i + jump[i], i}), cur = i + jump[i];
		else if (cur < i + 1) pre.push_back({i + 1, i + jump[i], i}), cur = i + jump[i];
	}

	for (int i = 0; i < pre.size(); ++i) {
		for (int j = pre[i].l; j <= pre[i].r && j < d; ++j) nextt[j] = pre[i].val;
	}

	int ans = 0;
	cur = d - 1;
	while (cur) {
		++ans, cur = nextt[cur];
	}
	printf("%d\n", ans);
	return 0;
}
