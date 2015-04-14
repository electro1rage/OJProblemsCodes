#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000005;

char s[MAXN];

int main() {
	int n, k;
	scanf("%d %d", &n, &k);

	if (k > n || (k == 1 && n != 1)) {
		puts("-1");
		return 0;
	}

	int i, j;
	for (i = 0; i < 2 && i < k; ++i) {
		s[i] = i + 'a';
	}

	for (j = 0; j < n - k; ++j, ++i) {
		s[i] = i % 2 + 'a';
	}

	for (j = 'c'; j < 'a' + k; ++j, ++i) {
		s[i] = j;
	}

	printf("%s\n", s);
	return 0;
}





