#include <bits/stdc++.h>
using namespace std;

int f, s;

void solve(int n, int m) {
	int sf = 0, ss = 0;
	int pre = 0;

	int sz = n + m;

	for (int i = 0; i < sz; ++i) {
		if (i % 2) {
			if (pre) {
				if (m) {
					--m;
					++sf;
				} else {
					--n;
					++ss;
					pre = 0;
				}
			} else {
				if (n) {
					--n;
					++sf;
				} else {
					--m;
					++ss;
					pre = 1;
				}
			}
		} else {
			if (pre) {
				if (n) {
					++ss;
					--n;
					pre = 0;
				} else {
					--m;
					++sf;
				}
			} else {
				if (m) {
					--m;
					++ss;
					pre = 1;
				} else {
					--n;
					++sf;
				}
			}
		}
	}

	if (f < sf || (f == sf && s > ss)) {
		f = sf;
		s = ss;
	}
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	f = -1;

	solve(n - 1, m);
	solve(m - 1, n);

	printf("%d %d\n", f, s);
	return 0;
}
