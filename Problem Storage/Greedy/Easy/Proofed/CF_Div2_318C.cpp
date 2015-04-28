#include <bits/stdc++.h>
using namespace std;

int main() {
	long long x, y, m;

	cin >> x >> y >> m;

	if (x < y) swap(x, y);

	if (x >= m) {
		printf("0\n");
		return 0;
	}

	if (x <= 0) {
		puts("-1");
		return 0;
	}

	long long ans = 0;

	if (y < 0) {
		ans += (-y + x - 1) / x, y += ((-y + x - 1) / x) * x;
	}

	while (x < m) {
		++ans;
		y = x + y;
		swap(x, y);
	}

	cout << ans << endl;
	return 0;
}




