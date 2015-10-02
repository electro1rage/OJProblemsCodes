#include <bits/stdc++.h>
using namespace std;

#define ban 0
#define pic 1

const int MN = 101, MVAL = 1010101010;

int a[MN], n, m;
unordered_map<long long, int> memo;
long long pw[MN];
pair<int, int> q[22];

int get_ans(int hh, vector<int> &v, int i) {
	if (i == m) return 0;
	if (memo.count(hh)) return memo[hh];
	int j, k, sz = v.size(), ret;
	if (q[i].second == 0) ret = -MVAL;
	else ret = MVAL;
	for (j = 0; j < n; ++j) {
		bool good = true;
		for (k = 0; k < sz; ++k) good &= v[k] != j;
		if (good) {
			if (q[i].second == 0) {
				v.push_back(j);
				ret = max(ret, get_ans(hh + pw[j], v, i + 1) + (q[i].first == ban ? 0 : a[j]));
				v.pop_back();
			} else {
				v.push_back(j);
				ret = min(ret, get_ans(hh + pw[j], v, i + 1) + (q[i].first == ban ? 0 : -a[j]));
				v.pop_back();
			}
		}
	}
	return memo[hh] = ret;
}

int main() {
	int i;
	scanf("%d", &n);
	for (i = 0; i < n; ++i) scanf("%d", a + i);
	scanf("%d", &m);
	for (i = 0; i < m; ++i) {
		char c;
		scanf(" %c", &c);
		if (c == 'p') q[i].first = pic;
		else q[i].first = ban;
		scanf("%d", &q[i].second);
		--q[i].second;
	}

	sort(a, a + n);
	reverse(a, a + n);
	n = m;

	pw[0] = 1;
	for (i = 1; i < n; ++i) pw[i] = 37 * pw[i - 1];

	vector<int> v;
	printf("%d\n", get_ans(0, v, 0));
	return 0;
}
