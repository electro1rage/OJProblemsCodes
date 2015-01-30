#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

vector<vector<int> > adj;
vector<pair<int, int> > edge;
vector<unordered_set<int> > connected;
int n, m, h, t;


void print(int u, int v, vector<int> &head, vector<int> &tail) {
	cout << u + 1 << ' ' << v + 1 << endl;
	for (auto &x : head)
		cout << x + 1 << ' ';cout << endl;
	for (auto &x : tail)
		cout << x + 1 << ' ';cout << endl;
}

bool used[100005];
vector<int> get(int u, int num) {
	vector<int> v;
	int ctr = 0;
	for (auto &x : adj[u]) {
		if (ctr == num) break;
		if (!used[x]) {
			++ctr;
			used[x] = 1;
			v.push_back(x);
		}
	}
	return v;
}

void solve(int u, int v, vector<int> &shared, vector<int> &head, vector<int> &tail) {
	if (head.empty()) {
		if (tail.size() > t) tail.erase(tail.begin() + t, tail.end());
		for (auto &x : tail) {
			used[x] = 1;
			--t;
		}
		vector<int> tailrem;
		tailrem = get(v, t);
		for (auto &x : tailrem)
			tail.push_back(x);
		head = get(u, h);
	} else {
		if (head.size() > h) head.erase(head.begin() + h, head.end());
		for (auto &x : head) {
			used[x] = 1;
			--h;
		}
		vector<int> headrem;
		headrem = get(u, h);
		for (auto &x : headrem)
			head.push_back(x);
		tail = get(v, t);
	}

	print(u, v, head, tail);
}

int main() {
	scanf("%d %d %d %d", &n, &m, &h, &t);

	adj.resize(n);
	connected.resize(n);

	for (int i = 0; i < m; ++i) {
		int x, y;
		scanf("%d %d", &x, &y);
		adj[--x].push_back(--y);
		adj[y].push_back(x);
		edge.push_back(make_pair(x, y));
		connected[x].insert(y);
		connected[y].insert(x);
	}

	for (int i = 0; i < m; ++i) {
		int x = edge[i].first;
		int y = edge[i].second;

		if (adj[x].size() > adj[y].size()) swap(x, y);

		int ysz = adj[y].size();
		int xsz = adj[x].size();

		if (ysz - 1 >= h + t && (xsz - 1 >= h || xsz - 1 >= t)) {
			vector<int> head, tail;
			used[x] = used[y] = 1;
			int u = y, v = x;
			if (xsz - 1 >= h) {
				head = get(x, h);
				tail = get(y, t);
				u = x, v = y;
			} else {
				tail = get(x, t);
				head = get(y, h);
			}
			puts("YES");
			print(u, v, head, tail);
			return 0;
		}

		vector<int> shared;
		vector<int> own;
		for (auto &u : adj[x]) {
			if (u == y) continue;
			if (connected[u].find(y) != connected[u].end()) {
				shared.push_back(u);
			} else {
				own.push_back(u);
			}
		}

		int headneed1 = max(0, h - (int)own.size());
		int tailneed1 = max(0, t - (int)own.size());
		int own2 = (int)adj[y].size() - (int)shared.size() - 1;
		int headneed2 = max(0, h - own2);
		int tailneed2 = max(0, t - own2);

		if (headneed1 + tailneed2 <= shared.size()) {
			puts("YES");
			vector<int> empty;
			used[x] = used[y] = 1;
			solve(x, y, shared, own, empty);
			return 0;
		} else if (headneed2 + tailneed1 <= shared.size()) {
			puts("YES");
			vector<int> empty;
			used[x] = used[y] = 1;
			solve(y, x, shared, empty, own);
			return 0;
		}
	}

	puts("NO");
	return 0;
}
