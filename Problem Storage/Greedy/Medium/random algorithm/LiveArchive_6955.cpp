/*
reality, be rent!
synapse, break!
Van!shment Th!s World !!
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, p, cnt;
	while (~scanf("%d", &n)) {
		srand(time(0));
		scanf("%d", &p);
		cnt = (n * p + 99) / 100;
		vector<pair<int, int> > point(n);
		int i, j;
		for (i = 0; i < n; ++i) scanf("%d %d", &point[i].first, &point[i].second);
		random_shuffle(point.begin(), point.end());

		if (n == 1) {
			puts("possible");
			continue;
		}

		for (i = 0; i < 500; ++i) {
			int r1 = rand() % n, r2 = rand() % n;
			while (r2 == r1) r2 = rand() % n;
			int top1 = point[r1].first - point[r2].first;
			int bot1 = point[r1].second - point[r2].second;
			int ans = 0;
			for (j = 0; j < n && ans < cnt; ++j) {
				int top2 = point[r1].first - point[j].first;
				int bot2 = point[r1].second - point[j].second;
				if (1LL * top1 * bot2 == 1LL * top2 * bot1) ++ans;
			}
			if (ans == cnt) {
				puts("possible");
				goto END;
			}
		}

		puts("impossible");
		END:;
	}
	return 0;
}
