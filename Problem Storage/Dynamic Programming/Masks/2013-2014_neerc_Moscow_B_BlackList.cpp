/*
reality, be rent!
synapse, break!
Van!shment Th!s World !!
*/
#include <bits/stdc++.h>
using namespace std;

#define EQL 0
#define LESS 1
#define MORE 2

const int MN = 22;

char s[MN];
int a[MN], ans[MN];
int memo[MN][1 << 16][3];

string d = "0123456789ABCDEF";

int get_cmp(int a, int b, int cmp) {
	if (cmp != EQL) return cmp;
	if (a > b) return LESS;
	if (a == b) return EQL;
	return MORE;
}

bool get_next(int i, int mask, int cmp) {
	if (cmp == LESS) return false;
	if (i == MN) return cmp == MORE;

	int &ret = memo[i][mask][cmp], j;

	if (ret == -1) {
		ret = false;
		for (j = 0; j < 16; ++j) {
			if ((mask >> j) & 1) continue;
			if (get_next(i + 1, mask | (1 << j), get_cmp(a[i], j, cmp))) return ret = true;
		}
	}
	return ret;
}


void get_ans(int i, int mask, int cmp) {
	if (i == MN) return ;

	int j;
	for (j = 0; j < 16; ++j) {
		if ((mask >> j) & 1) continue;
		if (get_next(i + 1, mask | (1 << j), get_cmp(a[i], j, cmp))) {
			ans[i] = j;
			get_ans(i + 1, mask | (1 << j), get_cmp(a[i], j, cmp));
			return ;
		}
	}
}

int get_num(char c) {
	int i;
	for (i = 0; i < 16; ++i) if (d[i] == c) return i;
}

int main() {
	scanf("%s", s);
	int n = strlen(s), i, j;
	for (i = n - 1, j = MN - 1; i >= 0; --i, --j) a[j] = get_num(s[i]);

	for (i = MN - n; i >= 0; --i) {
		memset(memo, -1, sizeof memo);
		if (get_next(i, 0, EQL)) {
			get_ans(i, 0, EQL);
			for (j = i; j < MN; ++j) cout << d[ans[j]];cout << endl;
			return 0;
		}
	}

	return 0;
}
