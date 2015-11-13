/*
reality, be rent!
synapse, break!
Van!shment Th!s World !!
*/
#include <bits/stdc++.h>
using namespace std;

int a[2020][2020];
bool vst[2020];
bool can[2020];
int n;

void dfs(int node) {
	vst[node] = true;
	int i;
	for (i = 0; i < n; ++i) {
		if (a[node][i] && !vst[i]) dfs(i);
	}
}

bool reach(int node, int goal) {
	if (vst[node] && can[node]) return true;
	if (vst[node]) return false;
	vst[node] = true;
	int i;
	for (i = 0; i < n; ++i) {
		if (a[node][i]) {
			if (reach(i, goal)) {
				can[node] = true;
				return true;
			}
		}
	}
	return false;
}

int main() {
	int i, j;
	scanf("%d", &n);
	for (i = 0; i < n; ++i) {
		for (j = 0; j < n; ++j) scanf("%d", &a[i][j]);
	}

	for (i = 0; i < n; ++i) {
		if (a[i][i]) {
			dfs(i);
			for (j = 0; j < n; ++j) {
				if (!vst[j]) {
					puts("NO");
					return 0;
				}
			}
			memset(vst, 0, sizeof vst);
			vst[i] = can[i] = true;
			for (j = 0; j < n; ++j) reach(j, i);
			for (j = 0; j < n; ++j) {
				if (!can[j]) {
					puts("NO");
					return 0;
				}
			}
			puts("YES");
			return 0;
		}
	}
	return 0;
}
