#include <bits/stdc++.h>
using namespace std;

void output(double ans) {
	cout << setprecision(6) << fixed << ans << endl;
}

double memo[50][50][50];

int n, len, pivotlen, pivotind;
vector<int> a;

long long nCr(int n, int r1) {
	int r2 = n - r1;
	if (r2 == 0) r2 = 1;

	long long ret = r2;
	for (long long i = 1; i <= min(r2, r1); ++i) {
		ret = ret * (n - i + 1) / i;
	}

	return ret;
}

double get_number(int i, int r, int curlen) {
	if (i == n) {
		if (curlen + pivotlen > len) return r * 1.0 / nCr(n, r);
		return 0;
	}

	double &ret = memo[i][r][curlen];
	if (ret != ret) {
		ret = get_number(i + 1, r, curlen);
		if (curlen + a[i] <= len && i != pivotind) ret += get_number(i + 1, r + 1, curlen + a[i]);
	}
	return ret;
}

int main() {
	scanf("%d", &n);
	a.resize(n);
	for (auto &x : a)
		scanf("%d", &x);

	scanf("%d", &len);

	if (accumulate(a.begin(), a.end(), 0) <= len) {
		output(n);
		return 0;
	}

	double ans = 0;
	for (int i = 0; i < n; ++i) {
		memset(memo, -1, sizeof memo);
		pivotind = i, pivotlen = a[i];
		ans += get_number(0, 0, 0);
	}


	output(ans);
	return 0;
}



