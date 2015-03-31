#include <bits/stdc++.h>
using namespace std;

const int MOD1 = 1000000007;
const int MOD2 = 982451653;
const int MAXN = 1505;
const int CHAR = 26;
const char BAD = '0';
const long long SHIFT = 1000000000;

char s[MAXN];
char state[CHAR];
unordered_set<long long> vst;

int main() {
	int k;
	scanf("%s", s);
	scanf("%s", state);
	scanf("%d", &k);

	int ans = 0;

	int n = strlen(s);
	for (int i = 0; i < n; ++i) {
		int rem1 = 0, rem2 = 0, bad = 0;
		for (int j = i; j < n; ++j) {
			if (state[s[j] - 'a'] == BAD) ++bad;
			if (bad > k) break;

			rem1 = (rem1 * 26LL + s[j] - 'a' + 1) % MOD1;
			rem2 = (rem2 * 26LL + s[j] - 'a' + 1) % MOD2;

			long long hashnumber = rem1 * SHIFT + rem2;

			if (vst.insert(hashnumber).second) {
				++ans;
			}
		}
	}

	printf("%d\n", ans);
	return 0;
}





