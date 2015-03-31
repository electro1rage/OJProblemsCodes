#include <bits/stdc++.h>
using namespace std;

int get_sqrt(int x) {
	int s = 1, e = 34567;
	int res;
	while (s <= e) {
		int mid = (s + e) / 2;
		if (mid * mid >= x) {
			res = mid;
			e = mid - 1;
		} else s = mid + 1;
	}
	return res;
}

int main() {
	/*
	 * ceil(sqrt(ai)) = c;
	 * 2^p >= c * 2^ki
	 * lg(2^p) >= lg(c) + lg(2^ki)
	 *	p >= lg(c) + ki
	 *	p = ceil(lg(c)) + ki
	 */
	int n;
	scanf("%d", &n);

	int ans = -1;
	for (int i = 0; i < n; ++i) {
		int k, a;
		scanf("%d %d", &k, &a);

		int asqrt = get_sqrt(a);
		int log;
		for (log = 1; (1 << log) < asqrt; ++log);

		ans = max(ans, log + k);
	}

	printf("%d\n", ans);
	return 0;
}




