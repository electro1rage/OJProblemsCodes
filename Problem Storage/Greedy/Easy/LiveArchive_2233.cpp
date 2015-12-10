/*
reality, be rent!
synapse, break!
Van!shment Th!s World !!
*/
#include <bits/stdc++.h>
using namespace std;

#define eps 1e-9

const int MN = 103;

int x[MN], y[MN], z[MN], r[MN];
double dist[MN];
bool vst[MN];

double get_dist(double x1, double y1, double z1, double x2, double y2, double z2) {
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) + (z1 - z2) * (z1 - z2));
}

double dij(int n) {
	double maxi, ret = get_dist(x[n], y[n], z[n], x[n + 1], y[n + 1], z[n + 1]);
	memset(vst, 0, sizeof vst);
	int best, i, j;
	for (i = 0; i < n; ++i) dist[i] = get_dist(x[n], y[n], z[n], x[i], y[i], z[i]) - r[i];
	for (i = 0; i < n; ++i) if (dist[i] < eps) dist[i] = 0;

	for (i = 0; i < n; ++i) {
		best = -1;
		for (j = 0; j < n; ++j) {
			if (vst[j]) continue;
			if (best == -1) best = j;
			else if (dist[best] - dist[j] > eps) best = j;
		}
		vst[best] = true;

		for (j = 0; j < n; ++j) {
			if (vst[j]) continue;
			maxi = get_dist(x[best], y[best], z[best], x[j], y[j], z[j]) - r[j] - r[best];
			if (maxi < eps) maxi = 0;
			if (dist[j] - dist[best] - maxi > eps) dist[j] = dist[best] + maxi;
		}
	}

	for (i = 0; i < n; ++i) {
		maxi = get_dist(x[i], y[i], z[i], x[n + 1], y[n + 1], z[n + 1]) - r[i];
		if (maxi < eps) maxi = 0;
		if (ret - dist[i] - maxi > eps) ret = dist[i] + maxi;
	}
	return ret;
}

int main() {
	int n, i, K = 1;
	while (true) {
		scanf("%d", &n);
		if (n == -1) break;
		for (i = 0; i < n; ++i) scanf("%d %d %d %d", x + i, y + i, z + i, r + i);
		scanf("%d %d %d", x + n, y + n, z + n);
		scanf("%d %d %d", x + n + 1, y + n + 1, z + n + 1);
		printf("Cheese %d: Travel time = %d sec\n", K, (int)(round(dij(n) * 10) + eps));
		++K;
	}
	return 0;
}
