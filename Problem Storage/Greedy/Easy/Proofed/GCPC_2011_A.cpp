#include <bits/stdc++.h>
using namespace std;

const long long MVAL = 1LL << 60;

long long get_ans(vector<pair<long long, int> > &a, long long n) {
	long long ans = MVAL;
	int sz = a.size(), i;
	for (i = 0; i < sz; ++i) {
		long long f = a[i].first, sum = n / f;
		while (f <= n / a[i].first) f *= a[i].first, sum += n / f;
		ans = min(ans, sum / a[i].second);
	}
	return ans;
}

long long factors(long long n, long long k) {
	long long i;
	vector<pair<long long, int> > factor;
	for (i = 2; i * i <= k; ++i) {
		if (k % i == 0) {
			factor.push_back({i, 0});
			while (k % i == 0) k /= i, ++factor.back().second;
		}
	}
	if (k > 1) factor.push_back({k, 1});
	return get_ans(factor, n);
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		long long n, k;
		cin >> n >> k;
		cout << factors(n, k) << endl;
	}
	return 0;
}
