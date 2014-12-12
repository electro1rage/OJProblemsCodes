#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k;
	scanf("%d %d", &n, &k);

	int a[100005];
	for (int i = 1; i <= n; ++i) {
		a[i - 1] = i;
	}

	bool b = 1;
	for(int i = k; i > 0; --i) {
		if(b)a[i - 1] = a[i] - i;
		else a[i - 1] = a[i] + i;
		b = !b;
	}

	for(int i = 0; i < n; ++i)
		printf("%d ", a[i]);
	return 0;
}
