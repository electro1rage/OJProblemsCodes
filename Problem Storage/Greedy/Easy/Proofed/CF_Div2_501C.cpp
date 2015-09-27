#include <bits/stdc++.h>
using namespace std;

const int MN = 1 << 17;

int d[MN], s[MN];

int main() {
	int n, i;
	scanf("%d", &n);
	for (i = 0; i < n; ++i) scanf("%d %d", d + i, s + i);

	vector<pair<int, int> > ans;
	priority_queue<pair<int, pair<int, int> > > q;
	for (i = 0; i < n; ++i) if (d[i] != 0) q.push({-d[i], {s[i], i}});

	while (!q.empty()) {
		int deg = -q.top().first, sum = q.top().second.first, node = q.top().second.second; q.pop();
		if (d[node] != deg) continue;
		ans.push_back({sum, node});
		--d[sum], s[sum] = s[sum] ^ node;
		if (d[sum] == 0) continue;
		q.push({-d[sum], {s[sum], sum}});
	}

	int sz = ans.size();
	printf("%d\n", sz);
	for (auto &x : ans) printf("%d %d\n", x.first, x.second);
	return 0;
}
