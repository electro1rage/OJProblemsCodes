#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;

map<int, bool> have;
int a[MAXN];


int main() {
	int n, k;
	scanf("%d %d", &n, &k);

	for (int i = 0; i < n; ++i)
		scanf("%d", a + i);

	sort(a, a + n);

	if (k == 1) {
		printf("%d\n", n);
		return 0;
	}

	int ans = 0;
	for (int i = 0; i < n; ++i) {
		have[a[i]] = true;
		if (a[i] % k) continue;
		if (have[a[i] / k]) {
			have[a[i]] = false;
			++ans;
		}
	}

	printf("%d\n", n - ans);
	return 0;
}






