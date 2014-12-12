#include <bits/stdc++.h>
using namespace std;

int Asuna[100005][30];
int acum[100005][30];
int ans[100005];
int s[100005], e[100005], q[100005];

int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; ++i) {
		scanf("%d %d %d", s + i, e + i, q + i);

		for (int j = 0; (1 << j) <= q[i]; ++j) {
			Asuna[s[i]][j] += (q[i] >> j) & 1;
		}
		for (int j = 0; (1 << j) <= q[i]; ++j) {
			Asuna[e[i] + 1][j] -= (q[i] >> j) & 1;
		}
	}

	int Kristina[30] = {};
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < 30; ++j)
			Kristina[j] += Asuna[i][j];

		int temp = 0;
		for (int j = 0; j < 30; ++j)
			temp |= (!!Kristina[j]) << j;

		for (int j = 0; j < 30; ++j)
			acum[i][j] += acum[i - 1][j] + !!Kristina[j];

		ans[i] = temp;
	}

	for (int i = 0; i < m; ++i) {
		int diff = e[i] - s[i] + 1;
		bool bad = 0;

		for (int j = 0; j < 30; ++j) {
			if (acum[e[i]][j] - acum[s[i] - 1][j] >= diff && !(q[i] & (1 << j))) {
				bad = 1;
				break;
			}
		}

		if (bad) {
			printf("NO\n");
			return 0;
		}
	}

	printf("YES\n");
	for (int i = 1; i <= n; ++i)
		printf("%d ", ans[i]);printf("\n");

	return 0;
}




