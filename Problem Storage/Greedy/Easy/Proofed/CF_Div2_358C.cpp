#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for((i)=0;(i)<(int)(n);++(i))

const int MN = 100010;

vector<pair<int, pair<int, string> > > a[MN];

bool get_pos(pair<int, pair<int, string> > a, pair<int, pair<int, string> > b) {
	return a.second.first < b.second.first;
}

int main() {
	int n, i, j;
	scanf("%d", &n);

	int sz = 0;
	int x;
	REP(i, n) {
		scanf("%d", &x);
		if (x == 0) {
			++sz;
			continue;
		}
		a[sz].push_back({x, {i, ""}});
	}

	if (x) ++sz;

	REP(i, sz) sort(a[i].rbegin(), a[i].rend());

	REP(i, sz) {
		int s = a[i].size();
		if (s >= 1) a[i][0].second.second = "pushStack";
		if (s >= 2) a[i][1].second.second = "pushQueue";
		if (s >= 3) a[i][2].second.second = "pushFront";

		for (j = 3; j < s; ++j) a[i][j].second.second = "pushBack";

		sort(a[i].begin(), a[i].end(), get_pos);
		REP(j, s) cout << a[i][j].second.second << endl;

		if (i == sz - 1 && x) continue;

		cout << min(3, s);
		if (s >= 1) printf(" popStack");
		if (s >= 2) printf(" popQueue");
		if (s >= 3) printf(" popFront");
		puts("");
	}


	return 0;
}
