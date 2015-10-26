/*
reality, be rent!
synapse, break!
Van!shment Th!s World !!
*/
#include <bits/stdc++.h>
using namespace std;

const int MN = 55;

int c[2][MN][MN];
int vst[MN];
int parent[MN], state[MN], n;

int dij(int src, int snk) {
	int i, j;
	for (i = 0; i < n; ++i) vst[i] = INT_MAX;
	priority_queue<pair<int, int> > q;
	parent[src] = -1;
	q.push({0, src});
	vst[src] = 0;
	while (!q.empty()) {
		if (q.top().second == snk) break;
		int cost = -q.top().first, node = q.top().second; q.pop();
		for (i = 0; i < n; ++i) {
			if (c[0][node][i] == 0 && vst[i] > cost + 1) {
				vst[i] = cost + 1;
				q.push({-cost - 1, i});
				parent[i] = node, state[i] = 0;
			}
			for (j = 0; j < 2; ++j) {
				if (c[j][node][i] != -1 && c[j][node][i] && vst[i] > cost) {
					vst[i] = cost;
					q.push({-cost, i});
					parent[i] = node, state[i] = j;
				}
			}
		}
	}
	if (q.top().second != snk) return 10101;
	return -q.top().first;
}

int get_maxflow(int k) {
	int ret = 0;
	while (true) {
		int src = 0, snk = n - 1;
		int cost = dij(src, snk), flow = INT_MAX;
		if (cost > k) break;
		while (parent[snk] != -1) {
			int &ref1 = c[state[snk]][parent[snk]][snk];
			flow = min(flow, ref1);
			snk = parent[snk];
		}
		flow = max(1, flow);
		k -= cost;
		ret += flow;
		snk = n - 1;
		while (parent[snk] != -1) {
			int &ref1 = c[state[snk]][parent[snk]][snk], &ref2 = c[!state[snk]][snk][parent[snk]];
			if (ref1) ref1 -= flow;
			ref2 += flow;
			snk = parent[snk];
		}
	}
	return ret;
}

int main() {
	int k, i, j;
	scanf("%d %d", &n, &k);
	for (i = 0; i < n; ++i) {
		for (j = 0; j < n; ++j) scanf("%d", &c[0][i][j]);
	}
	for (i = 0; i < n; ++i) {
		for (j = 0; j < n; ++j) if (c[0][i][j] == 0) c[0][i][j] = c[1][j][i] = -1;
	}

	printf("%d\n", get_maxflow(k));
	return 0;
}
