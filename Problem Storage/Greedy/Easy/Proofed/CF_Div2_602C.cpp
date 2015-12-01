/*
reality, be rent!
synapse, break!
Van!shment Th!s World !!
*/
#include <bits/stdc++.h>
using namespace std;

const int MN = 404, MVAL = 1000000000;

int rail[MN][MN];
int bus[MN][MN];

int main() {
	int n, m, u, v, i, j, k;
	scanf("%d %d", &n, &m);

	for (i = 0; i < n; ++i) {
		for (j = 0; j < n; ++j) bus[i][j] = 1, rail[i][j] = MVAL;
	}

	for (i = 0; i < m; ++i) {
		scanf("%d %d", &u, &v);
		--u, --v;
		rail[u][v] = rail[v][u] = 1;
		bus[u][v] = bus[v][u] = MVAL;
	}

	for (i = 0; i < n; ++i) rail[i][i] = bus[i][i] = MVAL;

	for (k = 0; k < n; ++k) {
		for (i = 0; i < n; ++i) {
			for (j = 0; j < n; ++j) {
				if (rail[i][k] + rail[k][j] < rail[i][j]) rail[i][j] = rail[i][k] + rail[k][j];
			}
		}
	}

	for (k = 0; k < n; ++k) {
		for (i = 0; i < n; ++i) {
			for (j = 0; j < n; ++j) {
				if (bus[i][k] + bus[k][j] < bus[i][j]) bus[i][j] = bus[i][k] + bus[k][j];
			}
		}
	}


	if (bus[0][n - 1] == MVAL || rail[0][n - 1] == MVAL) {
		puts("-1");
		return 0;
	}

	if (rail[0][n - 1] == 1) printf("%d\n", bus[0][n - 1]);
	else printf("%d\n", rail[0][n - 1]);
	return 0;
}
