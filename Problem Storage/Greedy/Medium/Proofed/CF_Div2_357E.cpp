#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for((i)=0;(i)<(int)(n);++(i))

int main() {
	int n, i;
	scanf("%d", &n);

	int one = 0, two = 0, three = 0, four = 0;
	REP(i, n) {
		int x;
		scanf("%d", &x);
		one += x == 1;
		two += x == 2;
		three += x == 3;
		four += x == 4;
	}

	int ans = 0;

	int mini = min(one, two);
	three += mini;
	ans += mini;

	two -= mini;
	one -= mini;

	three += one / 3;
	ans += (one / 3) * 2;
	one %= 3;

	if (one == 2) {
		if (three >= 2) {
			three -= 2;
			four += 2;
			one -= 2;
			ans += 2;
		} else {
			ans += 1;
			two += 1;
			one -= 2;
		}
	} else if (one == 1) {
		if (three) {
			three -= 1;
			ans += 1;
			one -= 1;
			four += 1;
		} else if (four >= 2) {
			one -= 1;
			ans += 2;
			four -= 2;
			three += 3;
		} else {
			puts("-1");
			return 0;
		}
	}

	ans += two / 3 * 2;
	three += two / 3 * 2;
	two %= 3;

	if (two == 2) {
		ans += 2;
		two -= 2;
	} else if (two == 1) {
		if (four) {
			ans += 1;
			two -= 1;
		} else if (three >= 2) {
			four += 2;
			ans += 2;
			two -= 1;
		} else {
			puts("-1");
			return 0;
		}
	}

	printf("%d\n", ans);
	return 0;
}
