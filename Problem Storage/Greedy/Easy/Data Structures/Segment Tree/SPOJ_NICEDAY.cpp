#include <bits/stdc++.h>
using namespace std;

int n;

int rs, re, val;

int tree[262144 + 1];

void insert(int s = 0, int e = n, int p = 1) {
	if (s == e) {
		tree[p] = val;
		return;
	}

	int mid = (s + e) / 2;
	if (rs <= mid) {
		insert(s, (s + e) / 2, p * 2);
	} else {
		insert((s + e) / 2 + 1, e, p * 2 + 1);
	}

	tree[p] = min(tree[p * 2], tree[p * 2 + 1]);
}

int query(int s = 0, int e = n, int p = 1) {
	if (s >= rs && e <= re) {
		return tree[p];
	}

	int mid = (s + e) / 2;
	if (re <= mid) {
		return query(s, (s + e) / 2, p * 2);
	}

	return min(query(s, (s + e) / 2, p * 2), query((s + e) / 2 + 1, e, p * 2 + 1));
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int res = 1;
		scanf("%d", &n);

		for (int i = 0; i <= n; ++i) {
			rs = i;
			val = 1000000;
			insert();
		}

		vector<pair<int, pair<int, int> > > v(n);

		for (int i = 0; i < n; ++i)
			scanf("%d %d %d", &v[i].first, &v[i].second.first, &v[i].second.second);

		sort(v.begin(), v.end());


		for (int i = 0; i < n; ++i) {
			if (i) {
				re = v[i].second.first - 1;
				rs = 0;
				int mini = query();
				if (mini > v[i].second.second) {
					++res;
				}
			}
			rs = v[i].second.first, val = v[i].second.second;
			insert();
		}

		printf("%d\n", res);
	}
	return 0;
}
