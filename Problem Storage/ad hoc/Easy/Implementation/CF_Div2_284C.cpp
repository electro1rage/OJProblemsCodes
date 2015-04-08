#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;

int a[MAXN];
stack<int> b;

int main() {
	int n;
	scanf("%d", &n);

	b.push(0);
	long long ans = 0;
	for (int i = 0; i < n; ++i) {
		int t;
		scanf("%d", &t);

		if (t == 2) {
			int k;
			scanf("%d", &k);

			b.push(k);
			ans += k;

			int sz = b.size();
			printf("%6f\n", (double)ans / sz);
		} else if (t == 1) {
			int ai, xi;
			scanf("%d %d", &ai, &xi);

			ans += ai * xi;
			a[ai - 1] += xi;

			int sz = b.size();
			printf("%6f\n", (double)ans / sz);
		} else {
			int top = b.top(); b.pop();
			int sz = b.size();

			ans -= top + a[sz];
			a[sz - 1] += a[sz];
			a[sz] = 0;

			printf("%6f\n", (double)ans / sz);
		}
	}
	return 0;
}






