#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);

	if (n % 2) {
		for (int i = 0; i < n; ++i) printf("%d ", i); puts("");
		for (int i = 0; i < n; ++i) printf("%d ", i); puts("");
		for (int i = 0; i < n; ++i) printf("%d ", (i + i) % n); puts("");
		return 0;
	}

	puts("-1");
	return 0;
}
