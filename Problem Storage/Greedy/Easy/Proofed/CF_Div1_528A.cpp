#include <bits/stdc++.h>
using namespace std;

set<int> hcut, vcut;
multiset<int> hrange, vrange;

void update(set<int> &cut, multiset<int> &range, int val) {
	cut.insert(val);
	auto it = cut.find(val);
	auto preit = it;
	auto nexit = it;
	--preit, ++nexit;

	int diff = (*nexit) - (*preit);
	auto diffit = range.find(diff);
	range.erase(diffit);

	int diff1 = (*it) - (*preit);
	int diff2 = (*nexit) - (*it);

	range.insert(diff1);
	range.insert(diff2);

}

int main() {
	int w, h, n;
	cin >> w >> h >> n;

	hcut.insert(0), hcut.insert(h), hrange.insert(h);
	vcut.insert(0), vcut.insert(w), vrange.insert(w);

	for (int i = 0; i < n; ++i) {
		char op;
		int val;
		cin >> op >> val;
		if (op == 'H') {
			update(hcut, hrange, val);
		} else {
			update(vcut, vrange, val);
		}

		auto maxhit = hrange.end();
		auto maxwit = vrange.end();

		--maxhit, --maxwit;

		long long X = *maxhit, Y = *maxwit;

		cout << X * Y << endl;
	}
	return 0;
}



