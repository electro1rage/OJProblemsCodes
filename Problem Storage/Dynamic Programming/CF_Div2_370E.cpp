#include <bits/stdc++.h>
using namespace std;

const int MN = 101010;
const int MVAL = 1010101010;

struct data {
	int m, ind, f;
};

int a[2 * MN], nextt[2 * MN];
int dp[MN][5];
vector<data> b;
int n, sz;

int get_last(data x) {
	return x.ind + x.f - 1;
}

void fill_end(int last, int i) {
	int j, k = b[i].m + 1;
	for (j = last + 1; j + 1 < n; j += 2, ++k) {
		a[j] = a[j + 1] = k;
	}
	if ((n - last + 1) % 2) a[n - 1] = k - 1;
}

void fill_range(int s, int e, int m1, int m2) {
	if (e - 1 < s + 1) return;
	int i = s + 1, k = m1 + 1;
	a[i] = a[i + 1] = k;
	for (i = s + 3; i < e; ++i) {
		int zeros = e - i;
		int numbers = m2 - k - 1;
		if (numbers * 2 <= zeros && numbers * 5 >= zeros) {
			++k;
			a[i] = a[i + 1] = k;
			++i;
		} else {
			a[i] = k;
		}
	}
}

int dfs(int i, int c) {
	if (c + b[i].f > 5) return -MVAL;

	if (i == sz - 1) {
		int last = get_last(b[i]);
		if (c + b[i].f == 1) {
			if (last == n - 1) return -MVAL;
			++last;
		}
		if (n - last == 2) {
			if (c + b[i].f == 5) return -MVAL;
			++last;
		}
		return b[i].m + (n - last - 1) / 2;
	}

	if (dp[i][c] != -1) return dp[i][c];
	dp[i][c] = -MVAL;

	int j, k;
	for (k = b[i + 1].ind - 4; k <= b[i + 1].ind; ++k) {
		int rem = 5 - b[i].f - c;
		for (j = get_last(b[i]); j <= get_last(b[i]) + rem; ++j) {
			if (j >= k || j - b[i].ind + c == 0) continue;
			int zeros = k - j - 1;
			int numbers = b[i + 1].m - b[i].m - 1;
			if (numbers * 2 <= zeros && numbers * 5 >= zeros) {
				dp[i][c] = max(dp[i][c], dfs(i + 1, b[i + 1].ind - k));
			}
		}
	}
	return dp[i][c];
}

void build(int i, int c) {
	if (i == sz - 1) {
		int last = get_last(b[i]);
		if (c + b[i].f == 1) {
			a[last + 1] = b[i].m, ++last;
		}

		if (n - last == 2) {
			a[last + 1] = b[i].m, ++last;
		}
		fill_end(last, i);
		return ;
	}

	int maxi = -MVAL, maxk, maxj;

	int j, k;
	for (k = b[i + 1].ind - 4; k <= b[i + 1].ind; ++k) {
		int rem = 5 - b[i].f - c;
		for (j = get_last(b[i]); j <= get_last(b[i]) + rem; ++j) {
			if (j >= k || j - b[i].ind + c == 0) continue;
			int zeros = k - j - 1;
			int numbers = b[i + 1].m - b[i].m - 1;
			if (numbers * 2 <= zeros && numbers * 5 >= zeros) {
				if (maxi < dfs(i + 1, b[i + 1].ind - k)) {
					maxi = dfs(i + 1, b[i + 1].ind - k);
					maxk = k, maxj = j;
				}
			}
		}
	}

	for (k = maxk; k <= b[i + 1].ind; ++k) a[k] = b[i + 1].m;
	for (j = get_last(b[i]); j >= 0 && j <= maxj; ++j) a[j] = b[i].m;

	fill_range(maxj, maxk, b[i].m, b[i + 1].m);

	build(i + 1, b[i + 1].ind - maxk);
}

int main() {
	int i;
	scanf("%d", &n);

	for (i = 0; i < n; ++i) scanf("%d", a + i);

	for (i = n - 1; i >= 0; --i) {
		if (a[i] == 0) nextt[i] = nextt[i + 1];
		else nextt[i] = a[i];
	}

	for (i = 1; i < n; ++i) if (a[i - 1] == nextt[i]) a[i] = a[i - 1];


	b.push_back({0, -1, 1});
	for (i = 0; i < n; ++i) {
		if (a[i] != 0) {
			if (a[i] == b.back().m) ++b.back().f;
			else b.push_back({a[i], i, 1});
		}
	}

	sz = b.size();
	for (i = 0; i < sz; ++i) if ((i && b[i].m < b[i - 1].m) || b[i].f > 5) {
		puts("-1");
		return 0;
	}

	memset(dp, -1, sizeof dp);
	if (dfs(0, 4) < 0) {
		puts("-1");
		return 0;
	}

	build(0, 4);

	printf("%d\n", a[n - 1]);
	for (i = 0; i < n; ++i) {
		if (i) putchar(' ');
		printf("%d", a[i]);
	}
	puts("");

	return 0;
}
