#include <bits/stdc++.h>
using namespace std;

bool have[100005];
int dp[100005];
int maxatprime[100005];
vector<vector<int> > primefactors;


int main() {
	int n;
	scanf("%d", &n);
	primefactors.resize(n);

	for (int i = 0; i < n; ++i) {
		int number;
		scanf("%d", &number);

		have[number] = true;

		for (int j = 2; 1LL * j * j <= number; ++j) {
			if (number % j == 0) {
				primefactors[i].push_back(j);
				while (number % j == 0) {
					number /= j;
				}
			}
		}

		if (number != 1) primefactors[i].push_back(number);
	}

	int ans = 1;
	for (int i = 1, ind = 0; i <= 100000; ++i) {
		if (have[i]) {
			for (auto &prime : primefactors[ind]) {
				dp[i] = max(dp[i], maxatprime[prime] + 1);
			}
			for (auto &prime : primefactors[ind]) {
				maxatprime[prime] = max(maxatprime[prime], dp[i]);
			}
			ans = max(ans, dp[i]);
			++ind;
		}
	}

	printf("%d\n", ans);

	return 0;
}



