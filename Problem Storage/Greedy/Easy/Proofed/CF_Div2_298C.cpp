#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;

char a[MAXN], b[MAXN];

int main() {
	scanf("%s", a);
	scanf("%s", b);

	int n = strlen(a), m = strlen(b);

	int i;
	int aones = 0, bones = 0;
	for (i = 0; i < n; ++i) if (a[i] == '1') ++aones;
	for (i = 0; i < m; ++i) if (b[i] == '1') ++bones;

	aones += aones % 2;

	if (aones >= bones) puts("YES");
	else puts("NO");
	return 0;
}






