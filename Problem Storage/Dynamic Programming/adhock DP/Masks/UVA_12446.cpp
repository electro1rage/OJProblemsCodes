#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007, MN = 1010101, ALL = 3, NON = 0;

int memo[MN][ALL + 1][ALL + 1];

bool bit(int mask, int i) {
	return (mask >> i) & 1;
}

int set_bit(int mask, int i) {
	return mask ^ (1 << i);
}

int get_ans(int i, int b, int t) {
	if (i == 0) return b == NON && t == NON;

	int &ret = memo[i][b][t];
	if (ret == -1) {
		ret = 0;

		if (b == ALL && t == ALL) ret = get_ans(i - 1, NON, NON);
		else if (bit(b, 0) && bit(b, 1) && !bit(t, 0) && !bit(t, 1)) {
			ret = (ret + get_ans(i - 1, NON, NON)) % MOD;
			ret = (ret + get_ans(i - 1, NON, set_bit(set_bit(t, 0), 1))) % MOD;
		} else if (!bit(b, 0) && !bit(b, 1) && bit(t, 0) && bit(t, 1)) {
			ret = (ret + get_ans(i - 1, NON, NON)) % MOD;
			ret = (ret + get_ans(i - 1, set_bit(set_bit(b, 0), 1), NON)) % MOD;
		} else if (bit(b, 0) && !bit(b, 1) && bit(t, 0) && !bit(t, 1)) {
			ret = (ret + get_ans(i - 1, NON, NON)) % MOD;
			ret = (ret + get_ans(i - 1, set_bit(set_bit(b, 1), 0), set_bit(set_bit(t, 1), 0))) % MOD;
		} else if (!bit(b, 0) && bit(b, 1) && !bit(t, 0) && bit(t, 1)) {
			ret = (ret + get_ans(i - 1, NON, NON)) % MOD;
			ret = (ret + get_ans(i - 1, set_bit(set_bit(b, 0), 1), set_bit(set_bit(t, 0), 1))) % MOD;
		} else if (b == NON && t == NON) {
			ret = (2 * (ret + get_ans(i - 1, NON, NON)) % MOD) % MOD;
			ret = (ret + get_ans(i - 1, ALL, ALL)) % MOD;
			ret = (ret + get_ans(i - 1, NON, set_bit(set_bit(t, 0), 1))) % MOD;
			ret = (ret + get_ans(i - 1, set_bit(set_bit(b, 0), 1), NON)) % MOD;
			ret = (ret + get_ans(i - 1, set_bit(b, 0), set_bit(t, 0))) % MOD;
			ret = (ret + get_ans(i - 1, set_bit(b, 1), set_bit(t, 1))) % MOD;
		}
	}
	return ret;
}

int main() {
	int i;
	memset(memo, -1, sizeof memo);
	for (i = 0; i <= 1000000; i += 3) get_ans(i, NON, NON);

	int T;
	scanf("%d", &T);
	while (T--) {
		int n;
		scanf("%d", &n);
		printf("%d\n", get_ans(n, NON, NON));
	}
	return 0;
}
