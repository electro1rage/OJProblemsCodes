#include <bits/stdc++.h>
using namespace std;

const int MN = 5005;

int tree[MN][MN];

void add(int x, int val) {
	++x;
	for (; x < MN; x += (x & -x)) ++tree[x][val];
}

void process() {
	int i, j;
	for (i = 0; i < MN; ++i) {
		for (j = MN - 3; j >= 0; --j) tree[i][j] += tree[i][j + 1];
	}
}

int get_count(int x, int val) {
	++x;
	int ret = 0;
	for (; x > 0; x -= (x & -x)) {
		ret += tree[x][val];
	}
	return ret;
}

char grid[MN][MN];

int main() {
	int n, m, i, j, k;
	scanf("%d %d", &n, &m);
	for (i = 0; i < n; ++i) scanf("%s", grid[i]);


	for (i = 0; i < n; ++i) {
		for (j = 0; j < m; ) {
			if (grid[i][j] == '1') {
				for (k = j; k < m; ++k) if (grid[i][k] == '0') break;
				add(j, k - 1);
				j = k;
			} else ++j;
		}
	}

	process();

	int ans = 0;
	for (i = 0; i < m; ++i) {
		for (j = i; j < m; ++j) {
			int sz1 = get_count(i, j), sz2 = j - i + 1;
			ans = max(ans, sz1 * sz2);
		}
	}

	printf("%d\n", ans);
	return 0;
}
