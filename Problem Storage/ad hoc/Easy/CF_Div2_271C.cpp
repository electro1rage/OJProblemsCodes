#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000005;

int id[MAXN];

int main() {
	int k, n;
	scanf("%d %d", &n, &k);

	if (k == 1 || 3 * k > n) {
		puts("-1");
		return 0;
	}

	memset(id, -1, sizeof id);
	for (int i = 0; i < k; ++i) {
		id[i * 2] = id[i * 2 + 1] = i + 1;
	}

	int i, j;
	for (i = n - 1, j = k; j > 0; --j, --i) id[i] = j;
	while (id[i] == -1) {
		id[i] = 1;
		--i;
	}

	for (int i = 0; i < n; ++i)
		printf("%d ", id[i]);puts("");
	return 0;
}







