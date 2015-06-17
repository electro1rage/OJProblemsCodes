#include <bits/stdc++.h>
using namespace std;

const int MN = 3030;

int vst[MN][MN];
int p[MN];
bool one[MN], zeros[MN];
int n, k;

int dfs(int i, int j, int k) {
	if (vst[i][j]) return 0;
	vst[i][j] = 1;

	if (k == 0 || j >= n) return 1;

	int ans = 0;

	if (p[i] && !zeros[j]) ans += dfs(j + 1, j + 2, k - 1);
	if (p[i] && !one[j]) ans += dfs(i, j + 1, k - 1);
	if (p[i] != 100 && !zeros[j]) ans += dfs(j, j + 1, k - 1);

	return ans + 1;
}

int main() {
	int i;
	scanf("%d %d", &n, &k);

	for (i = 0; i < n; ++i) scanf("%d", p + i);

	zeros[n] = true;
	for (i = n - 1; i >= 0; --i) one[i] = one[i + 1] | (p[i] == 100);
	for (i = n - 1; i >= 0; --i) zeros[i] = zeros[i + 1] & (p[i] == 0);

	printf("%d", dfs(0, 1, k));
	return 0;
}
