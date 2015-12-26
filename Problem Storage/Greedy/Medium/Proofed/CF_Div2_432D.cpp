/*
reality, be rent!
synapse, break!
Van!shment Th!s World !!
*/
#include <bits/stdc++.h>
using namespace std;

const int MN = 101010;

char s[MN];
int Z[MN], cnt[MN];

int main() {
	int n, sz, l, r, k, i;
	scanf("%s", s);
	n = strlen(s);

	l = r = 0, Z[0] = n, ++cnt[Z[0]];
	for (i = 1; i < n; ++i) {
		if (i > r) {
			l = r = i;
			while (r < n && s[r - l] == s[r]) ++r;
			Z[i] = r - l, --r;
		} else {
			k = i - l;
			if (Z[k] < r - i + 1) Z[i] = Z[k];
			else {
				l = i;
				while (r < n && s[r - l] == s[r]) ++r;
				Z[i] = r - l, --r;
			}
		}
		++cnt[Z[i]];
	}

	for (i = n - 1; i >= 0; --i) cnt[i] += cnt[i + 1];

	vector<pair<int, int> > ans;
	for (i = 1; i <= n; ++i) {
		if (Z[n - i] == i) ans.push_back({i, cnt[i]});
	}

	sz = ans.size();
	printf("%d\n", sz);
	for (i = 0; i < sz; ++i) printf("%d %d\n", ans[i].first, ans[i].second);
	return 0;
}
