/*
 reality, be rent!
 synapse, break!
 Van!shment Th!s World !!
 */
#include <bits/stdc++.h>
using namespace std;

const int MN = 105;

int a[MN][MN];

int main() {
	int n, m, k, ans = 20, tempans, temp1, temp2, i, j, l;
	scanf("%d %d %d", &n, &m, &k);

	for (i = 0; i < n; ++i) {
		for (j = 0; j < m; ++j)
			scanf("%d", &a[i][j]);
	}

	for (i = 0; i < n; ++i) {
		tempans = 0;
		for (j = 0; j < n; ++j) {
			temp1 = temp2 = 2;
			for (l = 0; l < m; ++l) {
				if (a[j][l] != a[i][l]) ++temp1;
				else ++temp2;
			}
			tempans += min(temp1, temp2);
		}
		ans = min(ans, tempans);
	}

	for (i = 0; i < m; ++i) {
		tempans = 0;
		for (j = 0; j < m; ++j) {
			temp1 = temp2 = 0;
			for (l = 0; l < n; ++l) {
				if (a[l][j] != a[l][i]) ++temp1;
				else ++temp2;
			}
			tempans += min(temp1, temp2);
		}
		ans = min(ans, tempans);
	}

	temp1 = temp2 = 0;
	for (i = 0; i < n; ++i) {
		for (j = 0; j < m; ++j) {
			if (a[i][j] == 1) ++temp1;
			else ++temp2;
		}
	}

	tempans = min(temp1, temp2);
	ans = min(ans, tempans);
	if (ans <= k)
		printf("%d\n", ans);
	else
		puts("-1");
	return 0;
}
