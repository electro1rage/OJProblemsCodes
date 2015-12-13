/*
reality, be rent!
synapse, break!
Van!shment Th!s World !!
*/
#include <bits/stdc++.h>
using namespace std;

int a[26][26];
int r[26], d[26];

int main() {
	int n;
	while (true) {
		scanf("%d", &n);
		if (n == 0) break;
		memset(a, 0, sizeof a);
		int m, u, v, c, i, j, k;
		for (i = 0; i < n; ++i) {
			scanf("%d %d", &u, &k);
			for (j = 0; j < k; ++j) {
				scanf("%d %d", &v, &c);
				a[u][v] += c;
			}
		}

		vector<pair<int, int> > ans;
		while (true) {
			scanf("%d", &m);
			if (m == 0) break;
			ans.push_back({0, m});
			for (i = 0; i < n; ++i) scanf("%d", &u), r[u] = i;
			for (i = 0; i < n; ++i) scanf("%d", &u), d[u] = i;
			for (i = 1; i <= n; ++i) {
				for (j = 1; j <= n; ++j) {
					ans.back().first += (abs(r[i] - d[j]) + 1) * a[i][j];
				}
			}
		}

		sort(ans.begin(), ans.end());
		puts("Configuration Load");
		for (auto &o : ans) {
			printf("%5d         %d\n", o.second, o.first);
		}

	}
	return 0;
}
