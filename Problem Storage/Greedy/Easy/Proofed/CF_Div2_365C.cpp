#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for((i)=0;(i)<(int)(n);++(i))

const int MN = 4040;

map<int, int> m;

char s[MN];

int number(char c) {
	return c - '0';
}

int main() {
	int a;
	scanf("%d", &a);
	scanf("%s", s);

	int n = strlen(s), i;
	REP(i, n) {
		int sum = 0;
		for (int j = i; j < n; ++j) {
			sum += number(s[j]);
			++m[sum];
		}
	}

	long long ans = 0;
	REP(i, n) {
		int sum = 0;
		for (int j = i; j < n; ++j) {
			sum += number(s[j]);
			if (sum == 0) {
				if (a == 0) {
					ans += n * (n + 1) / 2;
				}
				continue;
			}
			if (a % sum == 0) {
				if (!m.count(a / sum)) continue;
				ans += m[a / sum];
			}
		}
	}

	cout << ans << endl;
	return 0;
}
