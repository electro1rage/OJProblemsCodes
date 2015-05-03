#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

char a[105];

int main() {
	scanf("%s", a);

	int n = strlen(a);
	reverse(a, a + n);

	int ans = 0, fact = 1;
	for (int i = 0; i < n; ++i) {
		if (a[i] == '1') ans = (2LL * ans + fact) % MOD;
		else ans = 2LL * ans % MOD;
		fact = (fact * 4LL) % MOD;
	}

	printf("%d\n", ans);
	return 0;
}




