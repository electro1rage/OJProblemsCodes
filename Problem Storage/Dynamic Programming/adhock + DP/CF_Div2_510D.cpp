#include <bits/stdc++.h>
using namespace std;

const int MAX = 305;

unordered_map<int, int> memo[MAX];
int n;
int l[MAX], c[MAX];

int solve(int ind, int g) {
	if (g == 1) return 0;
	if (ind == n) return 1e9 + 5;

	if (memo[ind].count(g)) return memo[ind][g];
	int &ret = memo[ind][g];

	ret = min(solve(ind + 1, g), solve(ind + 1, __gcd(g, l[ind])) + c[ind]);
	return ret;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> l[i];
	for (int j = 0; j < n; ++j)
		cin >> c[j];

	int res = 1e9 + 1;

	res = solve(0, 0);
	if (res >= 1000000000) {
		cout << -1 << endl;
		return 0;
	}
	cout << res << endl;
	return 0;
}
