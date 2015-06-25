#include <bits/stdc++.h>
using namespace std;

const int MN = 303030;

long long accum[MN];
pair<int, int> b[MN];
int a[MN];

long long get_sum(int i, int j) {
	return accum[j + 1] - accum[i];
}

int main() {
	int n, k, i;
	scanf("%d", &n);

	for (i = 0; i < n; ++i) scanf("%d", a + i), b[i].first = a[i], b[i].second = i;
	sort(a, a + n);
	sort(b, b + n);
	for (i = 0; i < n; ++i) accum[i + 1] = a[i] + accum[i];

	scanf("%d", &k);

	long long sum = 0, bestsum, ans;

	for (i = 1; i < k; ++i) sum += 1LL * (k - i) * i * (a[i] - a[i - 1]);

	bestsum = sum, ans = 0;

	for (i = 0; i < n - k; ++i) {
		sum = sum + 1LL * a[i + k] * (k - 1) - get_sum(i + 1, i + k - 1) + 1LL * a[i] * (k - 1) - get_sum(i + 1, i + k - 1);
		if (bestsum > sum) bestsum = sum, ans = i + 1;
	}

	bool f = false;
	for (i = ans; i < ans + k; ++i) {
		if (f) putchar(' '); f = true;
		printf("%d", b[i].second + 1);
	}
	puts("");
	return 0;
}
