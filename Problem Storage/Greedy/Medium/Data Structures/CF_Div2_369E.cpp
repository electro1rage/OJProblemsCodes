#include <bits/stdc++.h>
using namespace std;

const int MN = 1010101;
const int MM = 303030;

int s[MN], e[MN];
int node[10 * MN];
vector<int> query[MM];
map<pair<int, int>, int> M;
vector<pair<int, int> > a, b;

void insert(int pos, int s = 0, int e = MN - 3, int p = 1) {
	if (s == e) {
		++node[p];
		return ;
	}

	int mid = (s + e) / 2;
	if (pos <= mid) insert(pos, s, mid, p * 2);
	else insert(pos, mid + 1, e, p * 2 + 1);

	node[p] = node[p * 2] + node[p * 2 + 1];
}

void remove(int pos, int s = 0, int e = MN - 3, int p = 1) {
	if (s == e) {
		--node[p];
		return ;
	}

	int mid = (s + e) / 2;
	if (pos <= mid) remove(pos, s, mid, p * 2);
	else remove(pos, mid + 1, e, p * 2 + 1);

	node[p] = node[p * 2] + node[p * 2 + 1];
}

int get(int l, int r, int s = 0, int e = MN - 3, int p = 1) {
	if (r < l) return 0;
	if (l <= s && e <= r) return node[p];

	int mid = (s + e) / 2;
	if (r <= mid) return get(l, r, s, mid, p * 2);
	else if (l > mid) return get(l, r, mid + 1, e, p * 2 + 1);
	else {
		int left = get(l, r, s, mid, p * 2);
		int right = get(l, r, mid + 1, e, p * 2 + 1);
		return left + right;
	}
}

int get_start(int l, int r) {
	if (r < l) return 0;
	int left = (l == 0 ? 0 : s[l - 1]);
	return s[r] - left;
}

int get_end(int l, int r) {
	if (r < l) return 0;
	int left = (l == 0 ? 0 : e[l - 1]);
	return e[r] - left;
}

int main() {
	int n, m, i, j;
	scanf("%d %d", &n, &m);
	for (i = 0; i < n; ++i) {
		int l, r;
		scanf("%d %d", &l, &r);
		--l, --r;
		a.push_back({l, r});
		insert(r);
		++s[l], ++e[r];
	}

	for (i = 1; i < MN; ++i) s[i] += s[i - 1], e[i] += e[i - 1];

	for (i = 0; i < m; ++i) {
		int x;
		scanf("%d", &x);
		for (j = 0; j < x; ++j) {
			int p;
			scanf("%d", &p);
			--p;
			query[i].push_back(p);
			if (j) b.push_back({query[i][j - 1], query[i][j]});
		}
	}

	sort(b.begin(), b.end());
	sort(a.begin(), a.end());

	int bsz = b.size(), asz = a.size();
	for (i = 0, j = 0; i < bsz && j < asz; ) {
		if (a[j].first <= b[i].first) {
			remove(a[j].second);
			++j;
		} else {
			M[b[i]] = get(b[i].first + 1, b[i].second - 1);
			++i;
		}
	}

	for (i = 0; i < m; ++i) {
		int sz = query[i].size();
		int ans = 0;
		for (j = 0;j < sz; ++j) {
			ans += get_start(0, query[i][j]) - get_end(0, query[i][j] - 1);
			if (j) {
				int a = query[i][j - 1], b = query[i][j];
				int temp = get_start(0, a) - get_end(0, a);
				temp -= get_end(a + 1, b - 1);
				temp += M[{a, b}];
				ans -= temp;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
