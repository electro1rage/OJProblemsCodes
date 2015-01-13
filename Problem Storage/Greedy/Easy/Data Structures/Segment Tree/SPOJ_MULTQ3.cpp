#include <bits/stdc++.h>
using namespace std;

struct node {
	int x, y, z;
	node() {
		x = y = z =  0;
	}
	node operator +(const node t) {
		node temp;
		temp.x = t.x + x;
		temp.y = t.y + y;
		temp.z = t.z + z;
		return temp;
	}
};

int n, q;
node tree[262144 + 1];
int need[262144 + 1];
int rs, re;

void build(int s = 0, int e = n - 1, int p = 1) {
	if (s == e) {
		tree[p].x = 1;
		tree[p].y = 0;
		tree[p].z = 0;
		return;
	}

	build(s, (s + e) / 2, p * 2);
	build((s + e) / 2 + 1, e, p * 2 + 1);

	tree[p] = tree[p * 2] + tree[p * 2 + 1];
}

void update(int s = 0, int e = n - 1, int p = 1) {
	if (need[p]) {
		for (int i = 0; i < need[p] % 3; ++i) {
			swap(tree[p].y, tree[p].z);
			swap(tree[p].y, tree[p].x);
		}
		if (s != e) {
			need[p * 2] += need[p];
			need[p * 2 + 1] += need[p];
		}
		need[p] = 0;
	}

	if (s > re || e < rs) return;

	if (s >= rs && e <= re) {
		swap(tree[p].y, tree[p].z);
		swap(tree[p].y, tree[p].x);
		if (s != e) {
			need[p * 2] += 1;
			need[p * 2 + 1] += 1;
		}
		return;
	}

	update(s, (s + e) / 2, p * 2);
	update((s + e) / 2 + 1, e, p * 2 + 1);

	tree[p] = tree[p * 2] + tree[p * 2 + 1];
}

int query(int s = 0, int e = n - 1, int p = 1) {
	if (need[p]) {
		for (int i = 0; i < need[p] % 3; ++i) {
			swap(tree[p].y, tree[p].z);
			swap(tree[p].y, tree[p].x);
		}
		if (s != e) {
			need[p * 2] += need[p];
			need[p * 2 + 1] += need[p];
		}
		need[p] = 0;
	}

	if (s >= rs && e <= re) {
		return tree[p].x;
	}

	int mid = (s + e) / 2;
	if (re <= mid) {
		return query(s, (s + e) / 2, p * 2);
	} else if (rs > mid) {
		return query((s + e) / 2 + 1, e, p * 2 + 1);
	} else {
		return query(s, (s + e) / 2, p * 2) + query((s + e) / 2 + 1, e, p * 2 + 1);
	}
}

int main() {
	scanf("%d %d", &n, &q);
	build();

	for (int i = 0; i < q; ++i) {
		int op;
		scanf("%d %d %d", &op, &rs, &re);
		if (op == 1) {
			printf("%d\n", query());
		} else {
			update();
		}
	}

	return 0;
}
