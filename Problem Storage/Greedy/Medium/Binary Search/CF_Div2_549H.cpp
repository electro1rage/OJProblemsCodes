#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for((i)=0;(i)<(int)(n);++(i))

double get_ans(double a, double d, double c, double b) {
	return (c * b - a * d) / (-a - b - c - d);
}

double get_ans2(double a, double d, double c, double b) {
	return (c * b - a * d) / (a - d + c - b);
}

double get_ans3(double a, double d, double c, double b) {
	return (c * b - a * d) / (-a - d + c + b);
}

int main() {

	int a, b, c, d;
	scanf("%d %d", &a, &b);
	scanf("%d %d", &c, &d);

	if (1LL * a * d == 1LL * b * c) {
		cout << setprecision(9) << fixed << 0 << endl;
		return 0;
	}

	double ans = min(abs(get_ans(a, d, c, b)), abs(get_ans(c, b, a, d)));
	ans = min(ans, abs(get_ans2(a, d, c, b)));
	ans = min(ans, abs(get_ans2(c, b, a, d)));
	ans = min(ans, abs(get_ans2(a, d, b, c)));
	ans = min(ans, abs(get_ans2(d, a, c, b)));
	ans = min(ans, abs(get_ans2(d, a, b, c)));
	ans = min(ans, abs(get_ans2(c, b, d, a)));
	ans = min(ans, abs(get_ans2(b, c, a, d)));
	ans = min(ans, abs(get_ans2(b, c, d, a)));

	ans = min(ans, abs(get_ans3(a, d, c, b)));
	ans = min(ans, abs(get_ans3(c, b, a, d)));

	cout << setprecision(9) << fixed << ans << endl;
	return 0;
}
