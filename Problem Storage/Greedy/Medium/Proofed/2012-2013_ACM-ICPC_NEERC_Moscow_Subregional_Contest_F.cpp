#include <bits/stdc++.h>
using namespace std;

#define eps 1e-9

const int MN = 10101;

int maxi[MN], n;
double cur[MN];
vector<int> adj[MN];

bool equal(double a, double b) {
	return abs(a - b) < eps;
}

bool bigger(double a, double b) {
	return a - b > eps;
}

bool smaller(double a, double b) {
	return eps < b - a;
}

void get_ans(int s, int x) {
	cur[s] += x;
	int i, j, sz;
	bool change = true;
	while (change) {
		change = false;
		for (i = 0; i < n; ++i) {
			double rem = cur[i] - maxi[i];
			if (bigger(rem, 0.0)) {
				cur[i] = maxi[i];
				sz = adj[i].size();
				for (j = 0; j < sz; ++j) cur[adj[i][j]] += rem / sz, change = true;
			}
		}
	}
}

int main() {
	int m, i;
	scanf("%d %d", &n, &m);
	for (i = 0; i < n; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		maxi[i] = a, cur[i] = b;
	}

	for (i = 0; i < m; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		--a, --b;
		adj[a].push_back(b);
	}

	int s, x, g;
	scanf("%d %d %d", &s, &x, &g);
	--s, --g;
	get_ans(s, x);

	printf("%.4lf\n", cur[g]);
	return 0;
}
