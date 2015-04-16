#include <bits/stdc++.h>
using namespace std;

const int MAXN = 505;
const int MAXVAL = 1000000000;

int cost[MAXN][MAXN];
int icost[MAXN][MAXN];
int pathcost[MAXN][MAXN];
int a[MAXN];
long long ans[MAXN];
bool removed[MAXN];

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j)
			scanf("%d", &cost[i][j]);
	}

	for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) pathcost[i][j] = MAXVAL, icost[i][j] = MAXVAL;

	for (int i = 0; i < n; ++i) scanf("%d", a + i), --a[i], removed[a[i]] = true, icost[i][i] = 0, pathcost[i][i] = 0;
	removed[a[n - 1]] = false;

	for (int i = n - 2; i >= 0; --i) {
		int addednode = a[i];
		removed[addednode] = false;
		for (int j = 0; j < n; ++j)
			if (!removed[j]) icost[addednode][j] = cost[addednode][j], icost[j][addednode] = cost[j][addednode];

		//get the shortest path from the new added node to every other node.
		for (int j = 0; j < n; ++j) {
			if (removed[j]) continue;
			for (int k = 0; k < n; ++k) {
				if (removed[k]) continue;
				if (icost[addednode][j] + pathcost[j][k] < pathcost[addednode][k]) {
					pathcost[addednode][k] = icost[addednode][j] + pathcost[j][k];
				}
			}
		}

		//get the shortest path from each node to the new added node.
		for (int j = 0; j < n; ++j) {
			if (removed[j]) continue;
			for (int k = 0; k < n; ++k) {
				if (removed[k]) continue;
				if (pathcost[j][k] + icost[k][addednode] < pathcost[j][addednode]) {
					pathcost[j][addednode] = pathcost[j][k] + icost[k][addednode];
				}
			}
		}

		//updated the shortest path between each two nodes, using the new added node.
		for (int j = 0; j < n; ++j) {
			if (removed[j]) continue;
			for (int k = 0; k < n; ++k) {
				if (removed[k]) continue;
				if (pathcost[j][addednode] + pathcost[addednode][k] < pathcost[j][k]) {
					pathcost[j][k] = pathcost[j][addednode] + pathcost[addednode][k];
				}
			}
		}

		//update the answer for the i-th query.
		for (int j = 0; j < n; ++j) {
			if (removed[j]) continue;
			for (int k = 0; k < n; ++k) {
				if (removed[k]) continue;
				ans[i] += pathcost[j][k];
			}
		}
	}

	for (int i = 0; i < n; ++i) printf("%I64d ", ans[i]);puts("");
	return 0;
}






