#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	printf("%d\n", min(n + 1, m + 1));

	int x = 0, y = m;
	while (x <= n && y >= 0) {
		printf("%d %d\n", x, y);
		++x, --y;
	}
	return 0;
}




