/*
reality, be rent!
synapse, break!
Van!shment Th!s World !!
*/
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000009;

int m, n;

bool is_good(int x1, int y1, int x2, int y2) {
	int dx = abs(x1 - x2), dy = abs(y1 - y2);
	if (dx == 1 && dy == 2) return false;
	if (dx == 2 && dy == 1) return false;
	return true;
}

bool valid(vector<int> mask) {
	int x = mask.size(), i, j, k, l;
	for (i = 0; i < x; ++i) {
		for (j = 0; j < m; ++j) {
			if ((mask[i] >> j) & 1) {
				for (k = 0; k < x; ++k) {
					for (l = 0; l < m; ++l) {
						if ((mask[k] >> l) & 1) {
							if (!is_good(i, j, k, l)) return false;
						}
					}
				}
			}
		}
	}
	return true;
}

vector<vector<int> > get_i(vector<int> a) {
	int n = a.size(), i;
	vector<vector<int> > ret(n, vector<int> (n));
	for (i = 0; i < n; ++i) ret[i][i] = 1;
	return ret;
}

vector<vector<int> > mul(vector<vector<int> > a, vector<vector<int> > b) {
	int n = a.size(), i, j, k;
	vector<vector<int> > ret(n, vector<int> (n));
	for (i = 0; i < n; ++i) {
		for (j = 0; j < n; ++j) {
			for (k = 0; k < n; ++k) {
				ret[i][j] = (ret[i][j] + 1LL * a[i][k] * b[k][j]) % MOD;
			}
		}
	}
	return ret;
}

vector<vector<int> > get_pow(vector<vector<int> > a, int p) {
	if (p == 0) return get_i(a[0]);
	if (p % 2) return mul(a, get_pow(a, p - 1));
	return get_pow(mul(a, a), p / 2);
}

int state[1 << 4][1 << 4];

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &m, &n);
		int i, j, k, X = 0;
		for (i = 0; i < (1 << m); ++i) {
			for (j = 0; j < (1 << m); ++j) {
				if (valid(vector<int> {i, j})) state[i][j] = X, ++X;
			}
		}

		vector<vector<int> > a(X, vector<int> (X)), b = a;
		a[0][state[0][0]] = 1;

		for (i = 0; i < (1 << m); ++i) {
			for (j = 0; j < (1 << m); ++j) {
				for (k = 0; k < (1 << m); ++k) {
					if (valid(vector<int> {i, j, k})) b[state[i][j]][state[j][k]] = 1;
				}
			}
		}

		int ans = 0;
		b = get_pow(b, n);
		a = mul(a, b);
		for (i = 0; i < X; ++i) ans = (ans + a[0][i]) % MOD;
		printf("%d\n", ans);
	}
	return 0;
}
