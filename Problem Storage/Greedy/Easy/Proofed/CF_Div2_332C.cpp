#include <bits/stdc++.h>
using namespace std;

bool have[100005];

int main() {
	int n, p, k;
	scanf("%d %d %d", &n, &p, &k);

	vector<pair<int, pair<int, int> > > x, y, z;
	vector<int> ans;
	for (int i = 0; i < n; ++i) {
		int a, b; scanf("%d %d", &a, &b);
		x.push_back({b, {-a, i + 1}});
	}

	sort(x.begin(), x.end());

	for (int i = p - k; i < n; ++i) y.push_back({-x[i].second.first, {x[i].first, x[i].second.second}});

	sort(y.begin(), y.end());
	reverse(y.begin(), y.end());

	for (int i = 0; i < k; ++i) z.push_back({y[i].second.first, {y[i].first, y[i].second.second}}), have[y[i].second.second] = true;

	for (int i = 0; i < n; ++i) {
		if (have[x[i].second.second]) {
			for (int j = i - 1, l = 0; j >= 0 && l < p - k; --j, ++l) {
				ans.push_back(x[j].second.second);
			}
			break;
		}
	}

	for (int i = 0; i < ans.size(); ++i) printf("%d ", ans[i]);
	for (int i = 0; i < z.size(); ++i) printf("%d ", z[i].second.second);
	return 0;
}






