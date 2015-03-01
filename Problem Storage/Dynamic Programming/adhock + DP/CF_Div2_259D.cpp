#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

long long res[10];

int Pow(int x, int p) {
	if (p == 1) return x;

	if (p % 2)
		return ((long long)x * Pow((long long)x * x % MOD, p / 2)) % MOD;

	return Pow((long long)x * x % MOD, p / 2);
}

int nPr(int n, int r) {
	if (r > n) return 0;
	if (r == 0) return 1;

	int ret = 1;
	for (int i = n - r + 1; i <= n; ++i)
		ret = ((long long)ret * i) % MOD;

	return ret;
}

int nCr(int n, int r) {
	if (r > n) return 0;

	int ret = 1;

	for (int j = 0; j < r; ++j) {
		ret = ((long long)ret * (n - j)) % MOD;
	}

	ret = ((long long)ret * Pow(nPr(r, r), MOD - 2)) % MOD;

	return ret;
}

int memo[7][11][11];
int get_ans(int i, int total, int level) {
	if (level == 10 || total >= 10 || i > 6) return 0;
	if (i == 6) {
		int temp = 0;
		for (int j = total + 1; j < 10; ++j)
			temp = (temp + res[j]) % MOD;
		return temp % MOD;
	}

	int &ret = memo[i][total][level];
	if (ret == -1) {
		ret = 0;
		for (int j = 0; j <= 6; ++j) {
			ret = (ret + (long long)nCr(res[level], j) * get_ans(i + j, total + j * level, level + 1) % MOD) % MOD;
		}
	}
	return ret;
}


int get_len(int x) {
	int res = 0;
	while (x) {
		x /= 10;
		++res;
	}
	return res;
}

int get_luck(int x) {
	int res = 0;
	while (x) {
		if (x % 10 == 4 || x % 10 == 7) ++res;
		x /= 10;
	}
	return res;
}

int main() {
	int m;
	scanf("%d", &m);

	int len = get_len(m);

	int dp[11][10] = {};
	dp[0][0] = 1;

	for (int curlen = 1; curlen < len; ++curlen) {
		for (int luck = 0; luck < 10; ++luck) {
			dp[curlen][luck] += dp[curlen - 1][luck] * 8;
			if (luck) dp[curlen][luck] += dp[curlen - 1][luck - 1] * 2;
		}
	}


	dp[len][get_luck(m)]++;
	for (int i = 0; i < len; ++i) {
		int s = 0 + (i == (len - 1)), e = m % 10;
		int curluck = get_luck(m / 10);
		int goodluck = 0, noluck = 0;

		for (int j = s; j < e; ++j) {
			if (j == 4 || j == 7) ++goodluck;
			else ++noluck;
		}

		for (int luck = 0; luck < 10; ++luck) {
			if (luck - curluck - (goodluck != 0) >= 0) dp[len][luck] += dp[i][luck - curluck - (goodluck != 0)] * goodluck;
			if (luck - curluck >= 0) dp[len][luck] += dp[i][luck - curluck] * noluck;
		}

		m /= 10;
	}
	dp[len - 1][0]--;

	for (int i = 0; i < 10; ++i)
		res[i] = dp[len][i] + dp[len - 1][i];

	memset(memo, -1, sizeof memo);
	cout << (1LL * get_ans(0, 0, 0) * nPr(6, 6)) % MOD << endl;
	return 0;
}






