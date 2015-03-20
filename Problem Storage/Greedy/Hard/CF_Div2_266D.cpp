#include <bits/stdc++.h>
using namespace std;

const int MAXN = 205;
const int MAXVAL = 1 << 29;


int graph[MAXN][MAXN];
bool edge[MAXN][MAXN];
int dist[MAXN][MAXN];

double get_ans(vector<pair<int, int> > a, int D, int u, int v) {
	sort(a.rbegin(), a.rend());

	vector<pair<int, int> > w;
	int pre = -1;
	for (int i = 0; i < a.size(); ++i) {
		if (a[i].second > pre) {
			pre = a[i].second;
			w.push_back(a[i]);
		}
	}

	int sz = w.size();
	double ans = min(w[0].first, w[sz - 1].second);
	for (int i = 0; i < sz - 1; ++i) {
		double tmp = (w[i].second + w[i + 1].first + D) / 2.0;
		ans = min(ans, tmp);
	}
	return ans;
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j)
			dist[i][j] = MAXVAL;
		dist[i][i] = 0;
	}

	for (int i = 0; i < m; ++i) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);

		--u, --v;
		graph[u][v] = graph[v][u] = w;
		edge[u][v] = edge[v][u] = true;
		dist[u][v] = dist[v][u] = w;
	}

	for (int k = 0; k < n; ++k)
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);


	double ans = MAXVAL;
	for (int u = 0; u < n; ++u) {
		for (int v = u + 1; v < n; ++v) {
			if (edge[u][v]) {
				vector<pair<int, int> > a;
				for (int k = 0; k < n; ++k) {
					a.push_back({dist[u][k], dist[v][k]});
				}
				double tmpans = get_ans(a, graph[u][v], u, v);
				ans = min(ans, tmpans);
			}
		}
	}

	printf("%.2f\n", ans);
	return 0;
}





