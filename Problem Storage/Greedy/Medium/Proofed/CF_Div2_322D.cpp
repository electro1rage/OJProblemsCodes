#include <bits/stdc++.h>
using namespace std;

const int MN = 105;

int catk[MN];
int jatk[MN], jdef[MN];
bool vst[MN];

char pos[10];

int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	int atk = 0, def = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%s", pos);
		if (pos[0] == 'A') scanf("%d", jatk + atk), ++atk;
		else scanf("%d", jdef + def), ++def;
	}

	for (int i = 0; i < m; ++i) scanf("%d", catk + i);

	sort(jatk, jatk + atk);
	sort(catk, catk + m);

	int ans = 0;
	for (int i = 0, j = m - 1; i < atk && j >= 0; ++i, --j) {
		ans += max(catk[j] - jatk[i], 0);
	}

	int pos;
	for (int i = 0; i < def; ++i) {
		pos = -1;
		int val = 1000000000;
		for (int j = 0; j < m; ++j) {
			if (vst[j]) continue;
			if (catk[j] > jdef[i] && catk[j] < val) {
				val = catk[j], pos = j;
			}
		}
		if (pos == -1) break;
		vst[pos] = true;
	}

	if (pos == -1) {
		printf("%d\n", ans);
		return 0;
	}

	int ans2 = 0;
	for (int i = atk - 1; i >= 0; --i) {
		pos = -1;
		for (int j = m - 1; j >= 0; --j) {
			if (vst[j]) continue;
			if (catk[j] >= jatk[i]) {
				pos = j;
				break;
			}
		}
		if (pos == -1) {
			printf("%d\n", ans);
			return 0;
		}
		vst[pos] = true;
		ans2 += catk[pos] - jatk[i];
	}

	for (int i = 0; i < m; ++i) if (!vst[i]) ans2 += catk[i];

	printf("%d\n", max(ans, ans2));
	return 0;
}







