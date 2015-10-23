/*
reality, be rent!
synapse, break!
Van!shment Th!s World !!
*/
#include <bits/stdc++.h>
using namespace std;

#define next _next

short cnt[10000000];
int next[10000000], n, s, t;

inline int get_dist(int s, int e) {
	if (s < e) return e - s;
	return ::s - s + e;
}

int get_next(int i) {
	if (cnt[i]) return i;
	return next[i] = get_next(next[i]);
}

inline long long get_res(int pos, int n, vector<int> &a) {
	long long ret = 0;
	while (true) {
		--cnt[pos], --n;
		ret += t;
		if (n == 0) break;
		auto it = lower_bound(a.begin(), a.end(), (pos + t) % s);
		if (it == a.end()) it = a.begin();
		if ((pos + t) % s != *it) ret += get_dist((pos + t) % s, *it);
		if (get_next(*it) != *it) ret += get_dist(*it, get_next(*it));
		pos = get_next(*it);
	}
	return ret;
}

int main() {
	while (~scanf("%d %d %d", &n, &s, &t)) {
		vector<int> a, b;
		int i, j;
		for (i = 0; i < n; ++i) {
			int x;
			scanf("%d", &x);
			a.push_back(x), b.push_back(x);
		}

		sort(a.begin(), a.end());
		a.erase(unique(a.begin(), a.end()), a.end());

		int sz = a.size();
		vector<long long> res;
		for (i = 0; i < sz; ++i) {
			for (j = 0; j < n; ++j) ++cnt[b[j]];
			for (j = 0; j < sz; ++j) next[a[j]] = a[(j + 1) % sz];
			res.push_back(get_res(a[i], n, a));
		}

		long long mini = res[0], maxi = res[0], sum = 0;
		for (i = 0; i < sz; ++i) {
			mini = min(mini, res[i]);
			long long dist = get_dist(a[(i - 1 + sz) % sz], a[i]) - 1;
			maxi = max(maxi, res[i] + dist);
			sum += (dist + 1) * res[i] + dist * (dist + 1) / 2;
		}
		printf("%lld\n", mini);
		printf("%lld\n", maxi);
		long long gcd = __gcd(sum, (long long)s);
		printf("%lld/%lld\n", sum / gcd, s / gcd);
	}
	return 0;
}
