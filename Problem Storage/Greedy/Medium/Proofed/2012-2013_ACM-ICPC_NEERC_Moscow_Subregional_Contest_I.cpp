#include <bits/stdc++.h>
using namespace std;

int get_ceil(int x, int y) {
	return (x + y - 1) / y;
}

int main() {
	int n, m, w, l, x, y;
	cin >> n >> m >> w >> l;
	x = m % l, y = n % w;
	if (n % w == 0 && m % l == 0) {
		cout << (n / w) * (m / l) << endl;
	} else if (n % w == 0 && m % l != 0) {
		cout << (n / w) * (m / l) + get_ceil(n / w, l / x) << endl;
	} else if (n % w != 0 && m % l == 0) {
		cout << (n / w) * (m / l) + get_ceil(m / l, w / y) << endl;
	} else if (n % w != 0 && m % l != 0) {
		int ans = (n / w) * (m / l);
		ans += get_ceil((n - y) / w, l / x);
		ans += get_ceil((m - x) / l, w / y);
		ans += (((n - y) / w) % (l / x) == 0) && (((m - x) / l) % (w / y) == 0);
		cout << ans << endl;
	}
	return 0;
}
