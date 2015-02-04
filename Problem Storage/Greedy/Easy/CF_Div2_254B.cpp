#include <bits/stdc++.h>
using namespace std;

struct data {
	int s, e, p;
};

int month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	scanf("%d", &n);

	vector<data> a(n);
	for (int i = 0; i < n; ++i) {
		int m, d, p, t;
		scanf("%d %d %d %d", &m, &d, &p, &t);

		for (int j = 0; j < m - 1; ++j)
			d += month[j];
		a[i].s = d - t;
		a[i].e = d - 1;
		a[i].p = p;
	}

	int res = -1;
	for (int i = -105; i < 400; ++i) {
		int temp = 0;
		for (int j = 0; j < n; ++j) {
			if (a[j].s <= i && i <= a[j].e) temp += a[j].p;
		}
		res = max(res, temp);
	}

	printf("%d\n", res);
	return 0;
}
