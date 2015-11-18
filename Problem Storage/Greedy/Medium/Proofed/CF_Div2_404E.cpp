/*
reality, be rent!
synapse, break!
Van!shment Th!s World !!
*/
#include <bits/stdc++.h>
using namespace std;

const int SHIFT = 1010101;

char s[1010101];
int add[2] = {-1, 1}, vst[2020202];
int good[SHIFT], a[SHIFT];

int main() {
	scanf("%s", s);
	int n = strlen(s), ans = 0, i, j, k;
	for (i = 0; i < n; ++i) s[i] = add[string("LR").find(s[i])];

	vst[SHIFT] = 1;
	for (i = 0, j = 0; i < n; ++i) j += s[i], ++vst[j + SHIFT];

	if (vst[j + SHIFT] == 1) {
		puts("1");
		return 0;
	}

	if (s[n - 1] == 1) {
		for (i = 0; i < n; ++i) s[i] = (s[i] == 1 ? -1:1);
	}
	int curmin = 0, maxi = 0;

	for (i = 0, j = 0; i < n; ++i) {
		if (j == 0 && s[i] == 1) continue;
		j += s[i];
		a[i] = j;
	}

	good[n - 1] = true;
	for (i = n - 2; i >= 0; --i) {
		if (a[i] <= a[n - 1]) good[i] = false;
		else good[i] = good[i + 1];
	}

	for (i = 0, j = 0; i < n; ++i) {
		j += s[i];
		curmin = min(curmin, j);
		if (j > maxi) {
			if (good[i] && a[n - 1] + j - 1 < curmin) ++ans;
			maxi = j;
		}
	}

	printf("%d\n", ans);
	return 0;
}
