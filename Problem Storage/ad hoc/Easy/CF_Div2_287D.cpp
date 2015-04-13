#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000005;

int p[2 * MAXN];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) p[i] = i;

	int start = 0;
	for (int i = 2; i <= n; ++i, ++start) {
		int first = (n - 1) / i * i + start, second = n + start;
		while (first >= start) {
			swap(p[first], p[second]);
			swap(first, second);
			first = second - i;
		}
	}

	for (int i = start; i < n + start; ++i) printf("%d ", p[i] + 1);puts("");
	return 0;
}
