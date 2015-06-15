#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for((i)=0;(i)<(int)(n);++(i))

const int MN = 101010;

int x[MN], y[MN], z[MN];
char s[MN];
int n;

void get_count(char c, int a[]) {
	int i;
	REP(i, n + 1) if (i) a[i] = a[i - 1] + (s[i] == c);
}

int get_range(int l, int r, int a[]) {
	return a[r] - a[l - 1];
}

void get_ans(int l, int r) {
	if (r - l < 2) {
		puts("YES");
		return ;
	}
	int xc = get_range(l, r, x), yc = get_range(l, r, y), zc = get_range(l, r, z);

	if (abs(xc - yc) > 1 || abs(xc - zc) > 1 || abs(yc - zc) > 1) {
		puts("NO");
	} else {
		puts("YES");
	}
}

int main() {
	scanf("%s", s + 1);
	s[0] = 'O';
	n = strlen(s) - 1;

	get_count('x', x);
	get_count('y', y);
	get_count('z', z);

	int m;
	scanf("%d", &m);
	int i;
	REP(i, m) {
		int l, r;
		scanf("%d %d", &l, &r);
		get_ans(l, r);
	}
	return 0;
}
