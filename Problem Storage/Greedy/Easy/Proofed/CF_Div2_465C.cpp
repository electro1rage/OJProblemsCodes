#include <bits/stdc++.h>
using namespace std;

char s[1010];

int get_num(char c) {
	return c - 'a';
}

int main() {
	int n, p, i, j;
	scanf("%d %d", &n, &p);

	scanf("%s", &s);

	for (i = n - 1; i >= 0; --i) {
		for (j = get_num(s[i]) + 1; j < p; ++j) {
			if (i - 1 >= 0 && get_num(s[i - 1]) == j) continue;
			if (i - 2 >= 0 && get_num(s[i - 2]) == j) continue;
			break;
		}
		if (j == p) continue;
		s[i] = j + 'a';
		break;
	}
	if (i == -1) {
		puts("NO");
		return 0;
	}
	for (i = i + 1; i < n; ++i) {
		for (j = 0; j < p; ++j) {
			if (i - 1 >= 0 && get_num(s[i - 1]) == j) continue;
			if (i - 2 >= 0 && get_num(s[i - 2]) == j) continue;
			break;
		}
		s[i] = j + 'a';
	}

	printf("%s\n", s);
	return 0;
}
