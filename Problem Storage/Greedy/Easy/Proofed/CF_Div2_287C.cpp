#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;

int p[MAXN];
int ans[MAXN];
int l, r;

void put_left(int x) {
	ans[l] = x; ++l;
}

void put_right(int x) {
	ans[r] = x; --r;
}

int main() {
	int n;
	scanf("%d", &n);

	if (n % 4 == 2 || n % 4 == 3) {
		puts("-1");
		return 0;
	}

	l = 0, r = n - 1;

	for (int i = 0; i < n; ++i) {
		p[i] = i + 1;
	}

	while (r - l > 0) {
		int a = p[l], b = p[l + 1], c = p[r], d = p[r - 1];
		put_left(b), put_left(c);
		put_right(d), put_right(a);
	}

	if (r == l) put_right(p[r]);

	for (int i = 0; i < n; ++i)
		printf("%d ", ans[i]);puts("");
	return 0;
}





