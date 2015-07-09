#include <bits/stdc++.h>
using namespace std;

priority_queue<int> x, y;
int a[505050];

int main() {
	int n, i;
	scanf("%d", &n);

	for (i = 0; i < n; ++i) scanf("%d", a + i);

	sort(a, a + n);

	for (i = 0; i < n / 2; ++i) x.push(a[i]);
	for (; i < n; ++i) y.push(a[i]);

	int ans = n;

	while (!x.empty()) {
		if (x.top() * 2 <= y.top()) {
			--ans; x.pop(); y.pop();
		} else x.pop();
	}

	printf("%d\n", ans);
	return 0;
}
