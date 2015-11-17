/*
reality, be rent!
synapse, break!
Van!shment Th!s World !!
*/
#include <bits/stdc++.h>
using namespace std;

struct interval {
	int l, r;
	interval& operator=(const interval& x) {
		l = x.l, r = x.r;
		return *this;
	}
};

int get_int(interval a, interval b) {
	if (a.l > b.l) swap(a, b);
	if (a.r <= b.l) return 0;
	return a.r - b.l;
}

int get_free(interval a, interval b) {
	int inter = get_int(a, b);
	return a.r - a.l - inter;
}

interval a[2020][2];
int x[2020];
double L, R, memo[2][2020][2020][2];
int h;

double get_ans(int ls, int l, int r, int rs) {
	double &ret = memo[ls][l][r][rs];
	if (ret == ret) return ret;
	ret = 0;
	if (l == r) {
		if (get_int(a[l][1], a[l - 1][ls]) != 0) {
			ret = get_free(a[l][1], a[r + 1][rs]);
			return ret;
		}
		if (get_int(a[r][0], a[r + 1][rs]) != 0) {
			ret = get_free(a[r][0], a[l - 1][ls]);
			return ret;
		}
		ret = L * get_free(a[l][0], a[l - 1][ls]) + R * get_free(a[r][1], a[r + 1][rs]);
		return ret;
	}
	if (get_int(a[l][1], a[l - 1][ls]) != 0) {
		ret = get_free(a[l][1], a[l + 1][1]) + get_ans(1, l + 1, r, rs);
		return ret;
	}
	if (get_int(a[r][0], a[r + 1][rs]) != 0) {
		ret = get_free(a[r][0], a[r - 1][0]) + get_ans(ls, l, r - 1, 0);
		return ret;
	}
	double retl = 0, retr = 0;
	retl += L * (get_free(a[l][0], a[l - 1][ls]) + get_ans(0, l + 1, r, rs));
	retl += R * (get_free(a[l][1], a[l + 1][1]) + get_ans(1, l + 1, r, rs));

	retr += L * (get_free(a[r][0], a[r - 1][0]) + get_ans(ls, l, r - 1, 0));
	retr += R * (get_free(a[r][1], a[r + 1][rs]) + get_ans(ls, l, r - 1, 1));

	ret = 0.5 * retl + 0.5 * retr;
	return ret;
}

int main() {
	memset(memo, -1, sizeof memo);
	int n, i;
	cin >> n >> h >> L;
	R = 1 - L;

	for (i = 1; i <= n; ++i) cin >> x[i];

	sort(x + 1, x + n + 1);
	x[0] = -1000000000, x[n + 1] = -x[0];

	for (i = 0; i <= n + 1; ++i) {
		a[i][0] = {x[i] - h, x[i]}, a[i][1] = {x[i], x[i] + h};
	}

	cout << setprecision(7) << fixed << get_ans(0, 1, n, 1) << endl;
	return 0;
}
