#include <bits/stdc++.h>
using namespace std;

#define S 0
#define E 1

const int MN = 101010;
const long long MVAL = 1LL << 60;

int cp[MN], c[MN][2][2], n;
long long memo[MN][2];

long long get_min(int i, bool s) {
	if (i == n) return 0;
	long long &ret = memo[i][s];
	if (ret == -1) {
		ret = MVAL;
		ret = min(ret, get_min(i + 1, S) + c[i][!s][S]);
		ret = min(ret, get_min(i + 1, E) + c[i][!s][E]);
	}
	return ret;
}

void build(int i, bool s) {
	if (i == n) return ;
	if (s == S) printf("F");
	else printf("B");

	long long ret1 = get_min(i + 1, S) + c[i][!s][S];
	long long ret2 = get_min(i + 1, E) + c[i][!s][E];

	if (ret1 < ret2) build(i + 1, S);
	else build(i + 1, E);
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int t, i;
		scanf("%d %d", &n, &t);

		long long sum = 0;
		for (i = 0; i < n; ++i) {
			scanf("%d %d %d %d %d", &cp[i], &c[i][S][S], &c[i][S][E], &c[i][E][S], &c[i][E][E]);
			sum += cp[i], memo[i][0] = memo[i][1] = -1;
		}

		if (sum > t) {
			puts("IMPOSSIBLE");
			continue;
		}

		if (get_min(0, S) < get_min(0, E)) {
			if (get_min(0, S) + sum > t) {
				puts("IMPOSSIBLE");
				continue;
			}
			build(0, S);
		} else {
			if (get_min(0, E) + sum > t) {
				puts("IMPOSSIBLE");
				continue;
			}
			build(0, E);
		}
		puts("");

	}
	return 0;
}
