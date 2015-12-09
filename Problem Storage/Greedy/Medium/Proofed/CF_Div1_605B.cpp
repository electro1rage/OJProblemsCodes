/*
reality, be rent!
synapse, break!
Van!shment Th!s World !!
*/
#include <bits/stdc++.h>
using namespace std;

const int MN = 101010;

pair<int, int> ans[MN];
int b[MN];

int main() {
	int n, m, val, u, v, cur, maxi, i, j;
	scanf("%d %d", &n, &m);

	vector<pair<int, pair<int, int> > > x;
	for (i = 0; i < m; ++i) {
		scanf("%d %d", &val, &u);
		if (u == 1) x.push_back({val, {0, i}});
		else x.push_back({val, {1, i}});
	}

	for (i = 1; i <= n; ++i) b[i] = 1;

	sort(x.begin(), x.end());

	for (i = 0, cur = 3, maxi = 1; i < m; ++i) {
		val = x[i].first, u = x[i].second.first, j = x[i].second.second;
		if (u == 0) {
			++maxi;
			ans[j] = {maxi, maxi - 1};
		} else {
			while (true) {
				if (cur > maxi) {
					puts("-1");
					return 0;
				}
				u = cur, v = b[u], ++b[u];
				if (v == u - 1) {
					++cur;
					continue;
				}
				ans[j] = {u, v};
				break;
			}
		}
	}

	for (i = 0; i < m; ++i) printf("%d %d\n", ans[i].first, ans[i].second);
	return 0;
}
