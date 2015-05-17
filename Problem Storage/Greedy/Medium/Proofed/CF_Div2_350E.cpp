#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)

bool bad[310];

int main() {
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);

	vector<int> a(k);
	int i;
	REP(i, k) scanf("%d", &a[i]), bad[a[i]] = true;

	int temp = a.back(); a.pop_back();

	if (k == n) {
		puts("-1");
		return 0;
	}

	if ((n - 1) * (n - 2) / 2 + n - k < m) {
		puts("-1");
		return 0;
	}

	for (int i = 1; i <= n; ++i) if (!bad[i]) a.push_back(i);
	a.push_back(temp);

	for (int i = 0; i < n - 1; ++i, --m) printf("%d %d\n", a[i], a[i + 1]);

	for (int i = 0; i < n - 1; ++i) {
		for (int j = i + 2; j < n - 1; ++j) {
			if (m == 0) goto END;
			--m;
			printf("%d %d\n", a[i], a[j]);
		}
		continue;
		END:
		break;
	}

	for (int i = k - 1; i < n - 2 && m != 0; ++i, --m) {
		printf("%d %d\n", a[i], a[n - 1]);
	}

	return 0;
}
