#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin >> s;

	int x = 0, y = 0;
	for (auto &c: s) {
		x += c == 'x';
		y += c == 'y';
	}

	if (x > y) cout << string(x - y, 'x') << endl;
	else cout << string(y - x, 'y') << endl;
	return 0;
}
