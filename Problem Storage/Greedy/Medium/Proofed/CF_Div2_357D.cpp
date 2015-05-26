#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for((i)=0;(i)<(int)(n);++(i))

const int MN = 1000010;

char x[MN], y[MN];
int a[MN][26];
int vst[MN];
int clr;
int xsz, ysz;

long long get_lcm(long long a, long long b) {
	return a / __gcd(a, b) * b;
}

void dfs(int i) {
	if (vst[i]) return;
	vst[i] = clr;
	++a[clr][y[i] - 'a'];
	dfs((i + xsz) % ysz);
}

int main() {
	long long n, m;
	cin >> n >> m;

	scanf("%s", x);
	scanf("%s", y);

	int i;
	xsz = strlen(x), ysz = strlen(y);
	if (xsz < ysz) {
		swap(xsz, ysz);
		swap(n, m);
		REP(i, max(xsz, ysz)) swap(x[i], y[i]);
	}

	long long lcm = get_lcm(xsz, ysz);
	long long M = m * ysz / lcm;

	long long ans = 0;

	REP(i, ysz) {
		if (!vst[i]) {
			++clr;
			dfs(i);
		}
	}

	int X = lcm / xsz;
	REP(i, xsz) {
		int curclr = vst[i % ysz];
		ans += X - a[curclr][x[i] - 'a'];
	}

	cout << ans * M << endl;
	return 0;
}
