#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);

	vector<int> v(n);
	for (auto &x : v)
		scanf("%d", &x);

	sort(v.begin(), v.end());

	int res = 1000000;
	for (int i = 0; i < n; ++i) {
		res = min(res, i + n - (int)(upper_bound(v.begin(), v.end(), v[i] * 2) - v.begin()));
	}

	printf("%d\n", res);
	return 0;
}
