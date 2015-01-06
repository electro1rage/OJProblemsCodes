#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	int a[505], b[1005], w[505];
	long long res = 0;

	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		w[i] = a[i];
	}

	for (int i = 0; i < m; ++i)
		cin >> b[i];

	bool use[1005];

	for (int i = 1; i < m; ++i) {
		memset(use, 0, sizeof use);
		for (int j = i - 1; j >= 0; --j) {
			if (b[i] == b[j]) break;
			if (!use[b[j]]) {
				use[b[j]] = 1;
				res += w[b[j]];
			}
		}
	}

	cout << res << endl;
	return 0;
}
