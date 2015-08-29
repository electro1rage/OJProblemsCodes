#include <bits/stdc++.h>
using namespace std;

const int MN = 10101;

map<int, int> M;
int X;

int acum[1 << 10][MN];
int score[MN], trait[MN];

int main() {
	int n, m, k, i, j;
	scanf("%d %d", &n, &k);

	for (i = 0; i < n; ++i) {
		int x;
		scanf("%d %d", score + i, &x);
		for (j = 0; j < x; ++j) {
			int y;
			scanf("%d", &y);
			--y;
			trait[i] |= 1 << y;
		}
	}

	for (i = 0; i < n; ++i) M[score[i]] = -1;
	for (auto &x : M) x.second = X, ++X;

	for (i = 0; i < n; ++i) score[i] = M[score[i]];

	for (i = 0; i < (1 << k); ++i) {
		for (j = 0; j < n; ++j) {
			if (trait[j] != i) continue;
			++acum[i][score[j]];
		}
		for (j = MN - 3; j >= 0; --j) acum[i][j] += acum[i][j + 1];
	}

	scanf("%d", &m);
	for (i = 0; i < m; ++i) {
		int a, x, mask = 0;
		scanf("%d %d", &a, &x);
		--a;
		for (j = 0; j < x; ++j) {
			int y;
			scanf("%d", &y);
			--y;
			mask |= 1 << y;
		}
		int have = mask & trait[a], nohave = mask ^ have, ans = 0;
		for (j = 0; j < (1 << k); ++j) {
			if ((j & have) == have && (j & nohave) == 0) ans += acum[j][score[a] + 1];
		}
		printf("%d\n", ans + 1);
	}
	return 0;
}
