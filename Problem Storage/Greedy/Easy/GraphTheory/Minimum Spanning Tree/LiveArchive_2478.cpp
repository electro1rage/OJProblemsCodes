/*
reality, be rent!
synapse, break!
Van!shment Th!s World !!
*/
#include <bits/stdc++.h>
using namespace std;

const int MN = 55;
const double eps = 1e-9;

int c[MN][3], parent[MN];
double dist[MN], rett, retb;
bool vst[MN];

double get_dist(double x1, double y1, double x2, double y2) {
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

bool is_smaller(double x, double y) {
	return eps < y - x;
}

void get_ans(int n) {
	double temp;
	int best, i, j;
	for (i = 0; i < n; ++i) dist[i] = 1000000000000000000, vst[i] = false;
	dist[0] = 0;

	memset(parent, -1, sizeof parent);

	for (i = 0; i < n; ++i) {
		best = -1;
		for (j = 0; j < n; ++j) {
			if (vst[j]) continue;
			if (best == -1 || is_smaller(dist[j], dist[best])) best = j;
		}
		vst[best] = true;

		for (j = 0; j < n; ++j) {
			if (vst[j]) continue;
			temp = get_dist(c[best][0], c[best][1], c[j][0], c[j][1]);
			if (is_smaller(temp, dist[j])) {
				dist[j] = temp;
				parent[j] = best;
			}
		}
	}
}

void dfs(int n, int node, double maxi) {
	rett += c[node][2] * maxi, retb += c[node][2];
	int i;
	double temp;
	for (i = 0; i < n; ++i) {
		if (parent[i] != node) continue;
		temp = get_dist(c[node][0], c[node][1], c[i][0], c[i][1]);
		if (is_smaller(maxi, temp)) dfs(n, i, temp);
		else dfs(n, i, maxi);
	}
}

int main() {
	int n, K = 1;
	while (true) {
		scanf("%d", &n);
		if (n == 0) break;
		int i;
		for (i = 0; i < n; ++i) scanf("%d %d %d", &c[i][0], &c[i][1], &c[i][2]);

		get_ans(n);
		rett = retb = 0;
		dfs(n, 0, 0);
		printf("Island Group: %d Average %.2lf\n\n", K, rett / retb);
		++K;
	}
	return 0;
}
