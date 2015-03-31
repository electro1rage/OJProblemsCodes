#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5005;
const int MAXVAL = 1e9 + 5;

int dp[MAXN];
int arr[MAXN];

int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; ++i) {
		int type;
		double dou;
		scanf("%d %lf", &type, &dou);
		arr[i] = type;
	}

	int ans = -1;
	for (int i = 1; i <= n; ++i) {
		dp[i] = 1;
		for (int j = 1; j < i; ++j) {
			if (arr[i] >= arr[j]) dp[i] = max(dp[i], dp[j] + 1);
		}
		ans = max(ans, dp[i]);
	}

	printf("%d\n", n - ans);
	return 0;
}






