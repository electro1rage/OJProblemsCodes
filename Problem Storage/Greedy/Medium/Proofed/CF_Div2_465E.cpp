#include <bits/stdc++.h>
using namespace std;

const int MN = 101010, MOD = 1000000007;

int get_num(char c) {
	return c - '0';
}

pair<long long, int> a[10];
char s[MN], t[MN];
vector<string> q;

int main() {
	int n, i, j;

	scanf("%s", s);
	scanf("%d", &n);

	for (i = 0; i < n; ++i) {
		scanf("%s", t);
		q.push_back(t);
	}

	for (i = 0; i < 10; ++i) a[i] = {10, i};

	for (i = n - 1; i >= 0; --i) {
		int sz = q[i].size();
		int x;
		pair<int, int> temp {1, 0};
		for (j = 3; j < sz; ++j) {
			x = get_num(q[i][j]);
			temp.first = (1LL * temp.first * a[x].first) % MOD;
			temp.second = ((1LL * temp.second * a[x].first) + a[x].second) % MOD;
		}
		x = get_num(q[i][0]);
		a[x] = temp;
	}

	n = strlen(s);
	int ans = 0;
	for (i = 0; i < n; ++i) {
		int x = get_num(s[i]);
		ans = (1LL * ans * a[x].first + a[x].second) % MOD;
	}

	printf("%d\n", ans);

	return 0;
}
