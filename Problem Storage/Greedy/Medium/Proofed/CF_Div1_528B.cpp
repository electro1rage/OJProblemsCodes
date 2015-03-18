#include <bits/stdc++.h>
using namespace std;

int const MAXN = 200005;
int const MAXVAL = 2000000000;

pair<int, int> a[MAXN];

int add[MAXN], sub[MAXN];

int main() {
	a[0] = {-MAXVAL, 5};

	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; ++i) {
		int x, w;
		scanf("%d %d", &x, &w);
		a[i] = {x + w, x - w};
	}

	sort(a, a + n + 1);

	for (int i = 0; i <= n; ++i) {
		add[i] = a[i].first;
		sub[i] = a[i].second;

	}

	int pre = -MAXVAL;
	int ans = 0;

	for (int i = 1; i <= n; ++i) {
		if (sub[i] >= pre) {
			++ans;
			pre = add[i];
		}
	}

	printf("%d\n", ans);
	return 0;
}






