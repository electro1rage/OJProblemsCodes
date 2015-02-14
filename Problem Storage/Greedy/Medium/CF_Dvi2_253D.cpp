#include <bits/stdc++.h>
using namespace std;

char table[405][405];
int anumber[405][405];

int n, m, bound;

struct line {
	int x1, y1, x2, y2;
	line (int x1, int y1, int x2, int y2) {
		this->x1 = x1, this->y1 = y1, this->x2 = x2, this->y2 = y2;
	}
};

int a_number(int x1, int y1, int x2, int y2) {
	return anumber[x2][y2] - anumber[x1 - 1][y2] - anumber[x2][y1 - 1] + anumber[x1 - 1][y1 - 1];
}

int ways(int n) {
	return n * (n - 1) / 2;
}

long long solve(vector<line> &a) {
	int start = 0, mid = 0, last = 1, sz = a.size();

	if (sz < 2) return 0;

	long long ret = 0;
	while (last < sz) {
		if (a_number(a[start].x1, a[start].y1, a[last].x2, a[last].y2) <= bound) ++last;
		else {
			if (last - 1 == start) {
				++last;
				++mid;
			} else {
				ret += ways(last - start) - ways(mid - start + 1);
				mid = last - 1;
			}
			++start;
		}
	}
	if (a_number(a[start].x1, a[start].y1, a[last - 1].x2, a[last - 1].y2) <= bound) {
		ret += ways(last - start) - ways(mid - start + 1);
	}

	return ret;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d %d %d", &n, &m, &bound);

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> table[i][j];
			anumber[i][j] = anumber[i - 1][j] + anumber[i][j - 1] - anumber[i - 1][j - 1] + (table[i][j] == 'a');
		}
	}


	long long res = 0;
	for (int i = 1; i <= m; ++i)
		for (int j = i + 1; j <= m; ++j) {
			vector<line> have[26];
			for (int k = 1; k <= n; ++k) {
				if (table[k][i] == table[k][j])
					have[table[k][i] - 'a'].push_back(line(k, i, k, j));
			}
			for (int k = 0; k < 26; ++k) {
				res += solve(have[k]);
			}
		}

	cout << res << endl;
	return 0;
}
