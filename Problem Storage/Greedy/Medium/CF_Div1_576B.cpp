#include <bits/stdc++.h>
using namespace std;

const int MN = 101010;

vector<int> base;
int a[MN];
bool vst[MN];

bool get_cycles(int n) {
	int i;
	for (i = 1; i <= n; ++i) {
		if (vst[i]) continue;
		int j = i, cnt = 1;
		while (a[j] != i) {
			j = a[j], vst[j] = true;
			++cnt;
		}
		if (cnt == 2 && base.empty()) base.push_back(i), base.push_back(a[i]);
		if (cnt % 2) return false;
	}
	if (base.empty()) return false;
	return true;
}

int main() {
	int n, i;
	scanf("%d", &n);
	for (i = 1; i <= n; ++i) scanf("%d", a + i);

	if (!get_cycles(n)) {
		for (i = 1; i <= n; ++i) {
			if (a[i] == i) {
				int j;
				puts("YES");
				for (j = 1; j <= n; ++j) {
					if (j == i) continue;
					printf("%d %d\n", i, j);
				}
				return 0;
			}
		}
		puts("NO");
		return 0;
	}

	memset(vst, 0, sizeof vst);
	puts("YES");
	printf("%d %d\n", base[0], base[1]);
	vst[base[0]] = vst[base[1]] = true;

	for (i = 1; i <= n; ++i) {
		if (!vst[i]) {
			vst[i] = true;
			int x = base[0], y = i;
			printf("%d %d\n", x, y);
			while (a[y] != i) {
				x = a[x], y = a[y], vst[y] = true;
				printf("%d %d\n", x, y);
			}
		}
	}
	return 0;
}
