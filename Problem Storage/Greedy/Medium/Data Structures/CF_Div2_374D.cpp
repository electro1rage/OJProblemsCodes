#include <bits/stdc++.h>
using namespace std;

const int MN = 1010101;

int tree[MN * 3];
int a[MN];
int ans[MN];

void add(int pos, int s = 0, int e = MN - 1, int p = 1) {
	if (s == e) {
		tree[p] = 1;
		return ;
	}
	int mid = (s + e) / 2;
	if (pos <= mid) add(pos, s, mid, p * 2);
	else add(pos, mid + 1, e, p * 2 + 1);

	tree[p] = tree[p * 2] + tree[p * 2 + 1];
}

int get_pos(int pos, int s = 0, int e = MN - 1, int p = 1) {
	if (s == e) return tree[p];
	int mid = (s + e) / 2;
	if (pos <= mid) return get_pos(pos, s, mid, p * 2);
	else return get_pos(pos, mid + 1, e, p * 2 + 1);
}

void remove(int pos, int s = 0, int e = MN - 1, int p = 1) {
	if (s == e) {
		tree[p] = 0;
		return ;
	}

	int mid = (s + e) / 2;
	if (pos <= tree[p * 2]) remove(pos, s, mid, p * 2);
	else remove(pos - tree[p * 2], mid + 1, e, p * 2 + 1);

	tree[p] = tree[p * 2] + tree[p * 2 + 1];
}

int main() {
	int n, m, cursz = 0, i, j, k;
	scanf("%d %d", &n, &m);

	for (i = 0; i < m; ++i) scanf("%d", a + i);

	for (i = 0, k = 0; i < n; ++i) {
		int x;
		scanf("%d", &x);
		if (x != -1) {
			ans[k] = x, add(k), ++k, ++cursz;
		} else {
			j = upper_bound(a, a + m, cursz) - a;
			cursz -= j;
			for (j = j - 1; j >= 0; --j) {
				remove(a[j]);
			}
		}
	}

	vector<int> b;
	for (i = 0; i < k; ++i) {
		if(get_pos(i)) b.push_back(ans[i]);
	}

	int sz = b.size();
	if (sz == 0) {
		puts("Poor stack!");
		return 0;
	}

	for (i = 0; i < sz; ++i) {
		printf("%d", b[i]);
	}
	puts("");
	return 0;
}
