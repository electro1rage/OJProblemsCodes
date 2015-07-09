#include <bits/stdc++.h>
using namespace std;

const int MN = 101010;

char s[MN];
int a[MN];

int main() {
	int n, i, j;
	scanf("%s", s);
	n = strlen(s);
	for (i = 0; i < n; ++i) a[i] = s[i] - '0';

	long long ans = 1;
	int ctr = 0;

	for (i = 0; i < n; ++i) {
		if (i + 1 < n && a[i] + a[i + 1] == 9) {
			for (j = 0; i + j < n; ++j) {
				if (j % 2) {
					if (a[i + 1] != a[i + j]) break;
				} else {
					if (a[i] != a[i + j]) break;
				}
			}
			if (j % 2) ans *= j / 2 + 1;
			i += j - 1;
		}
	}

	cout << ans << endl;
	return 0;
}
