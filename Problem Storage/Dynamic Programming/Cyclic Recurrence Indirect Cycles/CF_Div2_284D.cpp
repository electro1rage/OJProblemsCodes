#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
const long long MAXVAL = 2000000000000005LL;

long long memo[MAXN][2];
int a[MAXN];

int n;
long long get_ans(int i, bool op) {
	if (i > n || i <= 0) return 0;

	long long &ret = memo[i][op];

	if (ret < -1) return -MAXVAL;
	if (ret == -1) {
		ret = -2;
		long long tempret;
		if (op) {
			tempret = a[i] + get_ans(i - a[i], !op);
		} else {
			tempret = a[i] + get_ans(i + a[i], !op);
		}
		ret = tempret;
	}
	return ret;
}

int main() {
	memset(memo, -1, sizeof memo);

	scanf("%d", &n);

	for (int i = 2; i <= n; ++i) scanf("%d", a + i);

	memo[1][0] = -2;

	for (int i = 2; i <= n; ++i) {
		long long ans = get_ans(i, 1);
		if (ans < 0) {
			cout << -1 << endl;
		} else {
			cout << ans + i - 1 << endl;
		}
	}
	return 0;
}





