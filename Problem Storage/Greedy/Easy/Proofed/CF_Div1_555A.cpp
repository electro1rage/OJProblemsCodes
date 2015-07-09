#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > a;

int get_sec(vector<vector<int> > &a) {
	int sz = a.size(), ret = 0, i;
	for (i = 1; i < sz; ++i) {
		int nsz = a[i].size() - 1;
		ret += 2 * nsz + 1;
	}
	return ret;
}

int main() {
	int n, k, i, j, l;
	scanf("%d %d", &n, &k);

	int sz = 0, ans = 0;
	for (i = 0; i < k; ++i) {
		int m;
		scanf("%d", &m);
		vector<vector<int> > b;
		for (j = 0; j < m; ++j) {
			int x;
			scanf("%d", &x);
			if (j == 0) b.push_back({x});
			else {
				sz = b.size();
				if (x != b[sz - 1].back() + 1) b.push_back({x});
				else b[sz - 1].push_back(x);
			}
		}
		sz = b[0].size();
		ans += m - sz;
		sz = b.size();
		a.push_back(b[0]);
		for (j = 1; j < sz; ++j) {
			for (l = 0; l < b[j].size(); ++l) a.push_back({b[j][l]});
		}
	}

	sort(a.begin(), a.end());

	ans += get_sec(a);

	printf("%d\n", ans);
	return 0;
}
