/*
reality, be rent!
synapse, break!
Van!shment Th!s World !!
*/
#include <bits/stdc++.h>
using namespace std;

const int MN = 1010101;

bool keep[MN];
int pos[MN];
int a[MN];
int L[MN], R[MN];
int tree[MN];

void add(int i, int val) {
	for (; i < MN; i += (i & -i)) tree[i] += val;
}

int get(int i) {
	int ret = 0;
	for (; i > 0; i -= (i & -i)) ret += tree[i];
	return ret;
}

void process(int n, int b[MN]) {
	vector<int> v(1);
	int i;
	for (i = 1; i <= n; ++i) {
		if (keep[a[i]]) {
			while (v.back() > a[i]) v.pop_back();
			v.push_back(a[i]);
		} else {
			auto it = upper_bound(v.begin(), v.end(), a[i]);
			--it;
			b[a[i]] = pos[*it];
		}
	}
}

int main() {
	int n, k, i;
	scanf("%d %d", &n, &k);
	for (i = 1; i <= n; ++i) scanf("%d", a + i), pos[a[i]] = i;
	for (i = 0; i < k; ++i) {
		int x;
		scanf("%d", &x);
		keep[x] = true;
	}
	pos[0] = 0;
	process(n, L);
	reverse(a + 1, a + n + 1);
	pos[0] = n + 1;
	process(n, R);
	reverse(a + 1, a + n + 1);

	for (i = 1; i <= n; ++i) add(i, 1);

	vector<int> x;
	for (i = 1; i <= n; ++i) if (!keep[a[i]]) x.push_back(a[i]);
	sort(x.begin(), x.end());
	long long ans = 0;
	for (i = 0; i < n - k; ++i) {
		int l = L[x[i]], r = R[x[i]];
		ans += get(r - 1) - get(l);
		add(pos[x[i]], -1);
	}

	printf("%I64d\n", ans);
	return 0;
}
