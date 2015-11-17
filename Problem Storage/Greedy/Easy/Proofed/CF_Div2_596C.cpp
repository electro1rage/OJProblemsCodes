/*
reality, be rent!
synapse, break!
Van!shment Th!s World !!
*/
#include <bits/stdc++.h>
using namespace std;

const int MN = 100000;

pair<int, int> id[MN + 5];
queue<int> w[2 * (MN + 5)];
map<pair<int, int>, int> pm;

int main() {
	int n, x, y, W, i;
	scanf("%d", &n);
	vector<pair<int, int> > v;
	for (i = 0; i < n; ++i) {
		scanf("%d %d", &x, &y);
		v.push_back({x, y});
	}

	for (i = 0; i < n; ++i) {
		scanf("%d", &x);
		w[x + MN].push(i + 1);
	}

	sort(v.begin(), v.end());

	for (auto &p : v) {
		x = p.first, y = p.second;
		W = y - x + MN;
		if (w[W].empty()) {
			puts("NO");
			return 0;
		}
		pm[{x, y}] = w[W].front(), id[w[W].front()] = {x, y}, w[W].pop();
	}

	for (auto &p : v) {
		x = p.first, y = p.second;
		if (x) {
			if (pm[{x, y}] < pm[{x - 1, y}]) {
				puts("NO");
				return 0;
			}
		}
		if (y) {
			if (pm[{x, y}] < pm[{x, y - 1}]) {
				puts("NO");
				return 0;
			}
		}
	}

	puts("YES");
	for (i = 1; i <= n; ++i) printf("%d %d\n", id[i].first, id[i].second);
	return 0;
}
