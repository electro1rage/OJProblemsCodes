#include <bits/stdc++.h>
using namespace std;

int endt[808];
int vst[808];

int main() {
	int m, t, r, x, i, j, ans = 0;
	scanf("%d %d %d", &m, &t, &r);

	for (i = 0; i < m; ++i) scanf("%d", vst + i);

	for (x = -400; x <= 300; ++x) {
		if (ans > 800) {
			puts("-1");
			return 0;
		}
		for (i = 0; i < m; ++i) {
			if (vst[i] < x) continue;
			int cnt = 0;
			for (j = 0; j < ans; ++j) cnt += endt[j] >= vst[i];
			if (vst[i] == x) {
				if (cnt < r) {
					puts("-1");
					return 0;
				}
			} else {
				int need = r - cnt;
				if (vst[i] - x <= need) endt[ans] = x + t, ++ans;
			}
		}
	}

	printf("%d\n", ans);
	return 0;
}
