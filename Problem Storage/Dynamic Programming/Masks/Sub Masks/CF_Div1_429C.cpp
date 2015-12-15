/*
reality, be rent!
synapse, break!
Van!shment Th!s World !!
*/
#include <bits/stdc++.h>
using namespace std;

int a[24], n;

vector<int> v;
bool vst[1 << 12][24];

bool dfs(int mask, int rem, int i) {
	if (i == n) {
		if (mask == 1 << (n - 1)) return rem == 0;
		return false;
	}

	if (vst[mask][rem]) return false;
	vst[mask][rem] = true;

	if (a[i] != 2 && rem >= a[i] - 1 && dfs(mask | (1 << i), rem - a[i] + 1, i + 1)) return true;

	int sub, j, sum, need;
	for (sub = mask; sub > 0; sub = (sub - 1) & mask) {
		sum = 0, need = 0;
		for (j = 0; j < n; ++j) if ((sub >> j) & 1) sum += a[j];
		if (sum < a[i] - 1) need = a[i] - 1 - sum;
		if (need + sum != a[i] - 1) continue;
		if (need > rem) continue;
		if (need + __builtin_popcount(sub) == 1) continue;
		if (dfs((mask ^ sub) | (1 << i), rem - need, i + 1)) return true;
	}
	return false;
}

int main() {
	int m, i;
	scanf("%d", &m);
	for (i = 0; i < m; ++i) scanf("%d", a + i);

	if (m == 1 && a[0] == 1) {
		puts("YES");
		return 0;
	}

	sort(a, a + m);

	for (i = 0; i < m; ++i) if (a[i] != 1) v.push_back(a[i]);
	n = v.size();

	for (i = 0; i < n; ++i) a[i] = v[i];

	if (dfs(0, m - v.size(), 0)) puts("YES");
	else puts("NO");
	return 0;
}
