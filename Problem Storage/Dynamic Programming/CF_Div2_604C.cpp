/*
reality, be rent!
synapse, break!
Van!shment Th!s World !!
*/
#include <bits/stdc++.h>
using namespace std;

const int MN = 100005, MVAL = 100 * MN;

int memo[MN][3][3], n;
char s[MN];

int get_ans(int i, int state, int prv) {
	if (i == n) return (state == 2 ? 0 : -MVAL);

	int &ret = memo[i][state][prv];
	if (ret != -1) return ret;

	int bit = (s[i] - '0');
	if (state == 1) bit = !bit;
	ret = 0;

	ret = max(ret, get_ans(i + 1, state, prv));
	if (bit != prv) ret = max(ret, get_ans(i + 1, state, bit) + 1);
	if (state == 0) {
		ret = max(ret, get_ans(i + 1, 1, prv));
		if (bit != prv) ret = max(ret, get_ans(i + 1, 1, bit) + 1);
	}
	if (state == 1) {
		ret = max(ret, get_ans(i + 1, 2, prv));
		if (bit != prv) ret = max(ret, get_ans(i + 1, 2, bit) + 1);
	}

	return ret;
}

int main() {
	memset(memo, -1, sizeof memo);
	scanf("%d", &n);
	scanf("%s", s);

	printf("%d\n", max(get_ans(0, 0, 2), get_ans(0, 1, 2)));
	return 0;
}
