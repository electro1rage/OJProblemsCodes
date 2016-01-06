/*
reality, be rent!
synapse, break!
Van!shment Th!s World !!
*/
#include <bits/stdc++.h>
using namespace std;

#define ALICE 0
#define BOB 1

const int MN = 101;
int memo[MN][MN][MN][2];
int lft[MN], lftadd[MN], rt[MN], rtadd[MN];
bool canlft[MN], canrt[MN];
int a[MN];

bool get_ans(int l, int r, int rem, bool t) {
	if (l == 0 && r == 0) return t;

	int &ret = memo[l][r][rem][t];
	if (ret != -1) return ret;

	ret = !t;
	if (rem && get_ans(l, r, rem - 1, !t) == t) return (ret = t);
	if (r && get_ans(l, rt[r], rem + rtadd[r], !t) == t) return (ret = t);
	if (l && get_ans(lft[l], r, rem + lftadd[l], !t) == t) return (ret = t);
	if (canlft[l] && get_ans(0, r, rem + l - 1, !t) == t) return (ret = t);
	if (canrt[r] && get_ans(l, 0, rem + r - 1, !t) == t) return (ret = t);
	return ret;
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int n, i, j, k;
		scanf("%d", &n);
		for (i = 0; i < n; ++i) scanf("%d", a + i);
		for (i = 0; i < n; ++i) if (a[i] == 1) break;

		memset(canlft, false, sizeof canlft);
		memset(canrt, false, sizeof canrt);
		for (j = 1; j <= i; ++j) {
			if (j == 1 || a[i - 1] > a[i - 2]) canlft[j] = true;
			for (k = i - j; k < i; ++k) {
				if ((k - 1 < i - j || a[k] > a[k - 1]) && (a[k] > a[k + 1])) {
					lft[j] = i - k - 1, lftadd[j] = j - i + k;
					break;
				}
			}
		}

		for (j = 1; j < n - i; ++j) {
			if (j == 1 || a[i + 1] > a[i + 2]) canrt[j] = true;
			for (k = i + j; k > i; --k) {
				if ((a[k] > a[k - 1]) && (k + 1 > i + j || a[k] > a[k + 1])) {
					rt[j] = k - i - 1, rtadd[j] = j - k + i;
					break;
				}
			}
		}

		string ans[2];
		ans[ALICE] = "Alice", ans[BOB] = "Bob";
		memset(memo, -1, sizeof memo);
		puts(ans[get_ans(i, n - i - 1, 0, ALICE)].c_str());
	}
	return 0;
}
