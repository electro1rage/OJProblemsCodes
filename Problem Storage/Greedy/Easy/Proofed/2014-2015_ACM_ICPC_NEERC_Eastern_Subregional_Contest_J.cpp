#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, sum1 = 0, sum2 = 0, x, i;
	scanf("%d", &n);

	vector<pair<int, int> > a, b;

	for (i = 0; i < n; ++i) scanf("%d", &x), a.push_back({x, i + 1}), sum1 += x;
	for (i = 0; i < n; ++i) scanf("%d", &x), b.push_back({x, i + 1}), sum2 += x;

	sort(a.begin(), a.end()), sort(b.begin(), b.end());

	if (sum1 > sum2) reverse(b.begin(), b.end());
	else reverse(a.begin(), a.end());

	for (i = 0; i < n; ++i) printf("%d %d\n", a[i].second, b[i].second);
	return 0;
}
