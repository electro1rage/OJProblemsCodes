#include <bits/stdc++.h>
using namespace std;

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

int get_dir(char c) {
	return string("UDLR").find(c);
}

bool valid(int a, int b) {
	if (a == 0 && b == 0) return true;
	if (((b < 0 && a < 0) || (b > 0 && a > 0)) && (b % a == 0)) return true;
	return false;
}

char s[105];

int main() {
	int a, b;
	scanf("%d %d", &a, &b);
	scanf("%s", s);

	int n = strlen(s);
	int x = 0, y = 0;

	for (int i = 0; i < n; ++i) {
		x += dx[get_dir(s[i])], y += dy[get_dir(s[i])];
	}

	for (int i = 0; i <= n; ++i) {
		int ta = a, tb = b;
		for (int j = i; j < n; ++j) {
			a += dx[get_dir(s[j])], b += dy[get_dir(s[j])];
		}
		if (valid(x, a) && valid(y, b) && 1LL * x * b == 1LL * y * a) {
			puts("Yes");
			return 0;
		}
		a = ta, b = tb;
	}

	puts("No");
	return 0;
}
