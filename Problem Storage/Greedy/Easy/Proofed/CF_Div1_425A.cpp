/*
reality, be rent!
synapse, break!
Van!shment Th!s World !!
*/
#include <bits/stdc++.h>
using namespace std;

int a[202];

int main() {
	int n, k, sum, ans = -1000, i, j, l;
	scanf("%d %d", &n, &k);

	for (i = 0; i < n; ++i) scanf("%d", a + i);

	for (i = 0; i < n; ++i) {
		for (j = i; j < n; ++j) {
			priority_queue<int> x, y;
			sum = 0;
			for (l = 0; l < n; ++l) {
				if (i <= l && l <= j) sum += a[l], x.push(-a[l]);
				else y.push(a[l]);
			}
			for (l = 0; l < k; ++l) {
				if (!y.empty() && -x.top() < y.top()) sum -= -x.top(), x.pop(), x.push(-y.top()), sum += y.top(), y.pop();
			}
			ans = max(ans, sum);
		}
	}

	printf("%d\n", ans);
	return 0;
}
