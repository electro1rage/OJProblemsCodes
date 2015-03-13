#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
const int LOGN = 18;

int n;

vector<int> adj[MAXN];
int parent[MAXN], level[MAXN], M[MAXN][LOGN], rootsz[MAXN];

int DFS(int p, int node, int l) {
	level[node] = l;
	parent[node] = p;

	rootsz[node] = 1;

	for (auto &x : adj[node])
		if (x != p) rootsz[node] += DFS(node, x, l + 1);

	return rootsz[node];
}

void tree_preprocess() {
	memset(M, -1, sizeof M);

	for (int i = 1; i < MAXN; ++i)
		M[i][0] = parent[i];

	for (int i = 1; i < LOGN; ++i) {
		for (int j = 1; j < MAXN; ++j) {
			if (M[j][i - 1] != -1)
				M[j][i] = M[M[j][i - 1]][i - 1];
		}
	}
}

int get_k_parent(int &b, int k) {
	--k;
	int parentlevel = level[b] - k;

	for (int i = LOGN - 1; i >= 0; --i)
		if (M[b][i] != -1 && level[M[b][i]] >= parentlevel) {
			b = M[b][i];
		}

	return parent[b];
}

int LCA(int &a, int &b) {
	for (int i = LOGN - 1; i >= 0; --i) {
		if (M[b][i] != -1 && level[M[b][i]] >= level[a]) {
			b = M[b][i];
		}
	}

	if (a == b)
		return a | b;

	for (int i = LOGN - 1; i >= 0; --i) {
		if (M[b][i] != -1 && M[a][i] != M[b][i]) {
			a = M[a][i], b = M[b][i];
		}
	}

	return parent[a] | parent[b];
}

int get_ans(int a, int b) {
	if (a == b) {
		return n;
	}

	if (level[a] > level[b]) swap(a, b);

	int tempa = a, tempb = b;
	int lca = LCA(tempa, tempb);

	if (level[a] == level[b]) {
		return n - rootsz[tempa] - rootsz[tempb];
	}

	int dist = level[a] - level[lca] + level[b] - level[lca];

	if (dist % 2) return 0;

	int midnode = get_k_parent(b, dist / 2);

	return rootsz[midnode] - rootsz[b];
}

int main() {
	scanf("%d", &n);

	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		scanf("%d %d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	DFS(-1, 1, 0);

	tree_preprocess();

	int q;
	scanf("%d", &q);

	for (int i = 0; i < q; ++i) {
		int u, v;
		scanf("%d %d", &u, &v);

		printf("%d\n", get_ans(u, v));
	}
	return 0;
}





