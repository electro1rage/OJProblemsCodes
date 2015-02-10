#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, d;

	scanf("%d %d", &n, &d);
	vector<int> point(n);

	for (auto &x : point)
		scanf("%d", &x);

	long long res = 0;
	for (int i = 0; i < n - 1; ++i) {
		int s = i, e = n - 1, ret = -1;
		while (s <= e) {
			int mid = (s + e) / 2;
			if (point[mid] - point[i] <= d) {
				ret = mid;
				s = mid + 1;
			} else e = mid - 1;
		}
		int f = ret - i;
		res += 1LL * f * (f - 1) / 2;
	}

	cout << res << endl;
	return 0;
}
