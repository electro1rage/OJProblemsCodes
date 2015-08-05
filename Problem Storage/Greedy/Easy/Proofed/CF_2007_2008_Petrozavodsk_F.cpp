#include <bits/stdc++.h>
using namespace std;

int a[505], win[505];
int match, winsz, segsz;
bool seg[505];

void add(int x) {
	if (!win[x]) ++winsz;
	if (!win[x] && seg[x]) ++match;
	++win[x];
}

void take(int x) {
	if (win[x] == 1) --winsz;
	if (win[x] == 1 && seg[x]) --match;
	--win[x];
}

int main() {
	freopen("numbereater.in","r",stdin);
	freopen("numbereater.out","w",stdout);
	int n, i, j, l, r, ans = 0;
	scanf("%d", &n);
	for (i = 0; i < n; ++i) scanf("%d", a + i);

	for (i = 0; i < n; ++i) {
		memset(seg, 0, sizeof seg);
		segsz = 0;
		for (j = i; j < n; ++j) {
			if (!seg[a[j]]) ++segsz;
			seg[a[j]] = true;

			memset(win, 0, sizeof win);
			bool bad = false;
			match = 0, winsz = 0, l = 0, r = 0, add(a[0]);
			if (j && match == segsz) bad = true;
			while (j && !bad) {
				if (r == j || winsz == segsz) take(a[l]), ++l;
				else ++r, add(a[r]);
				if (r == j && l >= i) break;
				if (match == segsz) {
					bad = true;
					break;
				}
			}

			if (!bad) ++ans;
		}
	}
	printf("%d\n", ans);
	return 0;
}
