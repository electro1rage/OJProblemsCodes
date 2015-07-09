#include <bits/stdc++.h>
using namespace std;

const int MVAL = 2020202020;

vector<pair<int, int> > a;
int dp[303][150101];

void insert_mini(deque<pair<int, int> > &d, int a, int i) {
	while (!d.empty() && d.back().first >= a) d.pop_back();
	d.push_back({a, i});
}

int get_mini(deque<pair<int, int> > &d, int bad) {
	while (!d.empty() && d.front().second <= bad) d.pop_front();
	return d.front().first;
}

int main() {
    int n, m, d, i, j;
    scanf("%d %d %d", &n, &m, &d);

    long long b = 0;
    a.push_back({101, -n});
    for (i = 0; i < m; ++i) {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        b += y, a.push_back({x - 1, z});
    }

    for (i = 1; i <= m; ++i) {
       long long step = 1LL * d * (a[i].second - a[i - 1].second);
       deque<pair<int, int> > q;
       for (j = 0; j < n && j < step + 1; ++j) insert_mini(q, dp[i - 1][j], j);
       for (j = 0; j < n; ++j) {
           int dist = abs(j - a[i].first);
           dp[i][j] = get_mini(q, max(-101LL, j - step - 1)) + dist;
           if (j + step + 1 < n) insert_mini(q, dp[i - 1][j + step + 1], j + step + 1);
       }
    }

    int ans = MVAL;
    for (i = 0; i < n; ++i) ans = min(ans, dp[m][i]);

    cout << b - ans << endl;
    return 0;
}
