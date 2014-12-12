#include <bits/stdc++.h>
using namespace std;

int main() {
	long long r, g, b;

	cin >> r >> g >> b;

	if (r > g) swap(r, g);
	if (g > b) swap(g, b);
	if (r > g) swap(r, g);

	if ((r + g) * 2 <= b) cout << r + g << endl;
	else cout << (r + g + b) / 3 << endl;
	return 0;
}
