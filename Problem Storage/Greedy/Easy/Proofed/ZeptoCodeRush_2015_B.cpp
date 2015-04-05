#include <bits/stdc++.h>
using namespace std;

const int MAXN = 4000;

int lights[MAXN];

int main() {
	int n;
	scanf("%d", &n);

	int len = (1 << (n + 1)) - 1;
	for (int i = 2; i <= len; ++i) {
		scanf("%d", lights + i);
	}

	int ans = 0;
	for (int i = len; i > 1; i -= 2) {
		ans += abs(lights[i] - lights[i - 1]);
		int parent = i / 2;
		lights[parent] += max(lights[i], lights[i - 1]);
	}

	printf("%d\n", ans);
	return 0;
}






