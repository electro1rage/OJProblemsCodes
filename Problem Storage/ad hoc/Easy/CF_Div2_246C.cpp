#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k;
	scanf("%d %d", &n, &k);

	vector<int> a(n);

	for (auto &x : a)
		scanf("%d", &x);

	sort(a.rbegin(), a.rend());

	int last = 0;
	int use = 0;
	for (int i = 0; i < k; ++i) {
		if (use == n) {
			++last;
			use = last;
		}
		int c = last + 1;
		printf("%d ", c);
		for (int j = 0; j < last; ++j) {
			printf("%d ", a[j]);
		}
		if (use != n) printf("%d\n", a[use]);
		++use;
	}
	return 0;
}
