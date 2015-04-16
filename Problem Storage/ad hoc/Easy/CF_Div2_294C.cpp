#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
const int MAXN = 1005;

int a[MAXN];
int memo[MAXN][MAXN];
int dp[MAXN][MAXN];

int get_count(int s, int e) {
    if (s >= e) return 1;
    int &ret = memo[s][e];
    if (ret == -1) {
        ret = get_count(s + 1, e);
        ret %= MOD;
        ret += get_count(s, e - 1);
        ret %= MOD;
    }
    return ret;
}

int main() {
    memset(memo, -1, sizeof memo);
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; ++i) scanf("%d", a + i);

    sort(a, a + m);

    int ans1 = 1;
    for (int i = 1; i < m; ++i) {
        ans1 = (1LL * ans1 * get_count(a[i - 1] + 1, a[i] - 1)) % MOD;
    }

    dp[0][0] = 1;

    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            if(i) dp[i][j] += dp[i - 1][j];
            dp[i][j] %= MOD;
            if(j) dp[i][j] += dp[i][j - 1];
            dp[i][j] %= MOD;
        }
    }

    int sum = 0;
    int ans2 = 1;
    for (int i = 1; i < m; ++i) {
        int diff = a[i] - a[i - 1] - 1;
        ans2 = (1LL * ans2 * dp[sum][diff]) % MOD;
        sum += diff;
    }

    ans2 = (1LL * ans2 * dp[sum][a[0] - 1]) % MOD;
    sum += a[0] - 1;
    ans2 = (1LL * ans2 * dp[sum][n - a[m - 1]]) % MOD;


    int ans = (1LL * ans1 * ans2) % MOD;
    printf("%d\n", ans);
    return 0;
}
