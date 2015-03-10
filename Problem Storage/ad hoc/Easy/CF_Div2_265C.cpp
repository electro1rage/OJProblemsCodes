#include <bits/stdc++.h>
using namespace std;

#define LEFT 0
#define RIGHT 1

int dir[1000005];
char a[1000005];
int ans[1000005];


int main() {
	scanf("%s", a);
	int n = strlen(a);

	for (int i = 0; i < n; ++i) {
		if (a[i] == 'l') dir[i] = LEFT;
		if (a[i] == 'r') dir[i] = RIGHT;
	}

	int l = 0, r = n - 1;
	int i = 0;

	while (i < n) {
		if (dir[i] == LEFT) {
			ans[r] = i + 1;
			--r;
		} else if (dir[i] == RIGHT) {
			ans[l] = i + 1;
			++l;
		}
		++i;
	}

	for (i = 0; i < n; ++i)
		printf("%d\n", ans[i]);
	return 0;
}



