#include <bits/stdc++.h>
using namespace std;

const int a[] = {1869, 1968, 1689, 6198, 1698, 1986, 1896}, MN = 1010101;

bool vst[MN], f[10];
char s[MN];
char temp[MN];

int get_num(char c) {
	return c - '0';
}

int main() {
	scanf("%s", s);
	int n, i, j;
	n = strlen(s);
	for (i = 0, j = 0; i < n; ++i) {
		int x = get_num(s[i]);
		if ((x == 1 || x == 6 || x == 8 || x == 9) && !f[x]) f[x] = true, vst[i] = true;
		else temp[j] = s[i], ++j;
	}
	temp[j] = 0;
	sort(temp, temp + j);
	reverse(temp, temp + j);
	if (temp[0] == '0') {
		printf("%d%s\n", a[0], temp);
		return 0;
	}
	int rem = 0;
	for (i = 0; i < j; ++i) {
		int x = get_num(temp[i]);
		rem = (rem * 10 + x) % 7;
	}
	rem = (rem * 10000) % 7;
	int ans;
	if (rem == 0) ans = 0;
	else ans = 7 - rem;
	printf("%s%d\n", temp, a[ans]);
	return 0;
}
