#include <bits/stdc++.h>
using namespace std;

const int MN = 10005;
const int MOD = 1000000007;
//												0			1		2	  3	  4		5	  6	 7
vector<vector<int> > nextstate{{4, 7, 1}, {0, 6}, {5}, {4}, {0, 3}, {2}, {1}, {0}};

int n;
char grid[3][MN];
int memo[8][MN];

bool validate_update(int &mask, int &i) {
	int nmask = 0;
	for (int j = 0; j < 3; ++j) {
		nmask |= ((grid[j][i] != '.') << j);
	}

	if (mask & nmask) return false;

	mask |= nmask;
	return true;
}

int get_count(int mask, int i) {
	if (i == n) return mask == 0;
	if (!validate_update(mask, i)) return 0;

	int &ret = memo[mask][i];
	if (ret == -1) {
		ret = 0;
		for (int nmask : nextstate[mask]) {
			ret = (ret + get_count(nmask, i + 1)) % MOD;
		}
	}
	return ret;
}

int main() {
	scanf("%d", &n);

	for (int i = 0; i < 3; ++i) scanf("%s", grid[i]);
	memset(memo, -1, sizeof memo);

	int x, y;
	for (int i = 0; i < 3; ++i) for (int j = 0; j < n; ++j) if (grid[i][j] == 'O') x = i, y = j;

	bool bad = false;
	if (x != 0 && x != 2 && y != 0 && y != n - 1) bad = true;

	int ans = get_count(0, 0);
	if (bad) {
		int badright = get_count(0, y + 2);
		memset(memo, -1, sizeof memo);
		n = y - 1;
		int badleft = get_count(0, 0);

		ans = (ans - 2LL * badleft * badright % MOD + MOD) % MOD;
	}
	printf("%d\n", ans);
	return 0;
}
