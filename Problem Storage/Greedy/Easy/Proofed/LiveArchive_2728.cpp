/*
reality, be rent!
synapse, break!
Van!shment Th!s World !!
*/
#include <bits/stdc++.h>
using namespace std;

const int MN = 55, MT = 202;

int dist[MN][MT];
int d[MN], x[MN], y[MN];
bool l[MN][MT], r[MN][MT];

void dij(int n, int m1, int m2) {
	int c, cur, t, i, j;
	for (i = 0; i < n; ++i) for (j = 0; j < MT; ++j) dist[i][j] = MT;

	deque<pair<int, pair<int, int> > > q;
	dist[0][0] = 0;
	q.push_front({0, {0, 0}});

	while (!q.empty()) {
		c = -q.front().first, cur = q.front().second.first, t = q.front().second.second, q.pop_front();

		if (dist[cur][t] != c) continue;

		if (t + 1 < MT && dist[cur][t + 1] > c + 1) dist[cur][t + 1] = c + 1, q.push_back({-c - 1, {cur, t + 1}});

		if (r[cur][t]) {
			for (i = cur; i < n - 1; ++i) {
				if (t + d[i] < MT && dist[i + 1][t + d[i]] > c) dist[i + 1][t + d[i]] = c, q.push_front({-c, {i + 1, t + d[i]}});
				break;
			}
		}

		if (l[cur][t]) {
			for (i = cur - 1; i >= 0; --i) {
				if (t + d[i] < MT && dist[i][t + d[i]] > c) dist[i][t + d[i]] = c, q.push_front({-c, {i, t + d[i]}});
				break;
			}
		}
	}
}

int main() {
	int n, K = 1;
	while (true) {
		scanf("%d", &n);
		if (n == 0) break;
		int t, m1, m2, i, j;

		scanf("%d", &t);
		for (i = 0; i < n - 1; ++i) scanf("%d", d + i);

		scanf("%d", &m1);
		for (i = 0; i < m1; ++i) scanf("%d", x + i);

		scanf("%d", &m2);
		for (i = 0; i < m2; ++i) scanf("%d", y + i);


		memset(l, 0, sizeof l);
		memset(r, 0, sizeof r);

		for (i = 0; i < m1; ++i) {
			int sum = 0;
			r[0][x[i]] = true;
			for (j = 0; j < n - 1; ++j) {
				if (x[i] + sum + d[j] < MT) sum += d[j], r[j + 1][x[i] + sum] = true;
				else break;
			}
		}

		for (i = 0; i < m2; ++i) {
			int sum = 0;
			l[n - 1][y[i]] = true;
			for (j = n - 2; j >= 0; --j) {
				if (y[i] + sum + d[j] < MT) sum += d[j], l[j][y[i] + sum] = true;
				else break;
			}
		}

		dij(n, m1, m2);

		if (dist[n - 1][t] > t) printf("Case Number %d: impossible\n", K);
		else printf("Case Number %d: %d\n", K, dist[n - 1][t]);
		++K;
	}
	return 0;
}
