#include <bits/stdc++.h>
using namespace std;

const int MVAL = 2020202020;

struct rec {
	int j, x, y;
	bool operator<(const rec &a) const {
		return this->j < a.j;
	}
};

set<pair<pair<int, int>, int> > id;
set<rec> a;
int n;

int get_id(int x, int y) {
	y = n - y + 1;
	return y + x;
}

int main() {
	int q, sz = 0, i;
	scanf("%d %d", &n, &q);

	id.insert({{get_id(n, 1), get_id(1, n)}, sz});
	a.insert({sz, 1, 1});

	for (i = 0; i < q; ++i) {
		int x, y;
		char c;
		cin >> y >> x;
		int curid = get_id(x, y);
		auto it1 = id.lower_bound({{curid, -101}, -101});
		cin >> c;
		if (it1 == id.end()) {
			puts("0");
			continue;
		}
		int h = it1->first.first, l = it1->first.second;
		if (l > curid) {
			puts("0");
			continue;
		}
		int recid = it1->second;
		id.erase(it1);
		auto it2 = a.lower_bound({recid, -1, -1});
		int x1 = it2->x, y1 = it2->y;
		a.erase(it2);
		if (c == 'U') {
			printf("%d\n", x - x1 + 1);
			if (get_id(x + 1, y - 1) <= h) {
				++sz;
				id.insert({{h, get_id(x + 1, y - 1)}, sz});
				a.insert({sz, x1, y1});
			}
			if (get_id(x - 1, y + 1) >= l) {
				++sz;
				id.insert({{get_id(x - 1, y + 1), l}, sz});
				a.insert({sz, x1, y + 1});
			}
		} else {
			printf("%d\n", y - y1 + 1);
			if (get_id(x + 1, y - 1) <= h) {
				++sz;
				id.insert({{h, get_id(x + 1, y - 1)}, sz});
				a.insert({sz, x + 1, y1});
			}
			if (get_id(x - 1, y + 1) >= l) {
				++sz;
				id.insert({{get_id(x - 1, y + 1), l}, sz});
				a.insert({sz, x1, y1});
			}
		}
	}
	return 0;
}
