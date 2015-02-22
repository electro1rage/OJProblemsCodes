#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > number;
int id[1000005];
int dp[4005][4005];
int arr[4005];
int cur;

int main() {
	int n;
	scanf("%d", &n);

	memset(id, -1, sizeof id);

	for (int i = 0; i < n; ++i) {
		int x;
		scanf("%d", &x);
		arr[i] = x;
		if (id[x] == -1) {
			id[x] = cur;
			++cur;
			number.push_back(vector<int> (1, i));
		} else {
			number[id[x]].push_back(i);
		}
	}

	int res = 1;

	for (int i = n - 2; i >= 0; --i) {
		for (int j = i + 1; j < n; ++j) {
			dp[i][j] = 2;

			vector<int> &temp = number[id[arr[i]]];
			auto it = upper_bound(temp.begin(), temp.end(), j);

			if (it != temp.end()) dp[i][j] = dp[j][*it] + 1;

			res = max(res, dp[i][j]);
		}
	}

	printf("%d\n", res);
	return 0;
}




