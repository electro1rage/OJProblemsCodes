#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;

int a[MAXN];
int l[MAXN], r[MAXN];
long long d[MAXN];
long long b[MAXN];

void process_array(long long a[], int n) {
	long long sum = 0;
	for (int i = 0; i < n; ++i) {
		sum += a[i];
		a[i] = sum;
	}
}

int main() {
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);

	for (int i = 0; i < n; ++i) scanf("%d", a + i);
	for (int i = 0; i < m; ++i) scanf("%d %d %I64d", l + i, r + i, d + i);

	for (int i = 0; i < k; ++i) {
		int x, y;
		scanf("%d %d", &x, &y); --x; --y;
		++b[x], --b[y + 1];
	}

	process_array(b, m);

	for (int i = 0; i < m; ++i) {
		d[i] *= b[i];
	}

	memset(b, 0, sizeof b);

	for (int i = 0; i < m; ++i) {
		int x = l[i] - 1, y = r[i] - 1;
		b[x] += d[i], b[y + 1] -= d[i];
	}

	process_array(b, n);

	for (int i = 0; i < n; ++i) printf("%I64d ", a[i] + b[i]);puts("");
	return 0;
}






