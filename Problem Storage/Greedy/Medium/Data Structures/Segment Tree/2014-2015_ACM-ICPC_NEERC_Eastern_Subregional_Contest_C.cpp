#include <bits/stdc++.h>
using namespace std;

const int MN = 101010;

struct letter {
	int change, month, day, hh, mm, ind;
};

struct data {
	long long credit, add;
	data () {
		credit = add = 0;
	}
};

data tree[MN * 3];

void insert(int val, int pos, int s = 0, int e = MN - 3, int p = 1) {
	if (s == e) {
		if (val < 0) tree[p].credit = val;
		else tree[p].add = val;
		return ;
	}

	int mid = (s + e) / 2;
	if (pos <= mid) insert(val, pos, s, mid, p * 2);
	else insert(val, pos, mid + 1, e, p * 2 + 1);

	tree[p].credit = tree[p * 2].credit + min(tree[p * 2].add + tree[p * 2 + 1].credit, 0LL);
	tree[p].add = max(tree[p * 2].add + tree[p * 2 + 1].credit, 0LL) + tree[p * 2 + 1].add;
}

bool cmpa(letter a, letter b) {
	if (a.month != b.month) return a.month < b.month;
	if (a.day != b.day) return a.day < b.day;
	if (a.hh != b.hh) return a.hh < b.hh;
	return a.mm < b.mm;
}

vector<letter> a;
vector<int> b;
int place[MN];

int main() {
	int n, i;
	scanf("%d", &n);

	a.resize(n);
	for (i = 0; i < n; ++i) {
		scanf("%d %d.%d %d:%d", &a[i].change, &a[i].day, &a[i].month, &a[i].hh, &a[i].mm);
		a[i].ind = i;
		b.push_back(a[i].change);
	}

	sort(a.begin(), a.end(), cmpa);

	for (i = 0; i < n; ++i) place[a[i].ind] = i;

	for (i = 0; i < n; ++i) {
		insert(b[i], place[i]);
		cout << tree[1].credit << endl;
	}
	return 0;
}
