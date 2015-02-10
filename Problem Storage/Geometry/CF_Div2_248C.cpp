#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-8;

int main() {
	int y1, y2, yw, xb, yb, r;
	scanf("%d %d %d %d %d %d", &y1, &y2, &yw, &xb, &yb, &r);

	double l3 = yw - r - yb;
	double l6 = yw - r - y1 - r;
	double l4 = l6 * xb / (l3 + l6);
	double l7 = (y2 - y1 - r) * l4 / (sqrt(l4 * l4 + l6 * l6));

	if (l7 - r < EPS) {
		puts("-1");
		return 0;
	}

	cout << setprecision(8) << fixed << l4 << endl;
	return 0;
}
