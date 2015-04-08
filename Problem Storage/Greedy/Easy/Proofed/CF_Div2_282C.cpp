#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000006;

char a[MAXN], b[MAXN];

int main() {

	scanf("%s", a);
	int n = strlen(a);

	scanf("%s", b);
	int m = strlen(b);

	if (n != m) {
		puts("NO");
		return 0;
	}

	if (!strcmp(a, b)) {
		puts("YES");
		return 0;
	}

	bool aa = false, bb = false;
	for (int i = 0; i < n; ++i) {
		if (a[i] == '1') aa = true;
	}

	for (int i = 0; i < n; ++i) {
		if (b[i] == '1') bb = true;
	}

	if (aa && bb) {
		puts("YES");
		return 0;
	}

	puts("NO");
	return 0;
}









