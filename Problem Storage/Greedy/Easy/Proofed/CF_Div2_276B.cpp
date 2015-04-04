#include <bits/stdc++.h>
using namespace std;

char a[1005];
int have[26];

int main() {
	scanf("%s", a);

	int n = strlen(a);
	for (int i = 0; i < n; ++i) {
		++have[a[i] - 'a'];
	}

	int odd = 0;
	for (int i = 0; i < 26; ++i) {
		if (have[i] % 2) ++odd;
	}

	if (odd == 0) {
		puts("First");
		return 0;
	}

	if (odd % 2) {
		puts("First");
		return 0;
	}

	puts("Second");
	return 0;
}





