#include <bits/stdc++.h>
using namespace std;

int clr[100005];
set<int> have[100005];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; ++i) {
        cin >> clr[i];
    }

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        if (clr[a] == clr[b]) continue;
        have[clr[a]].insert(clr[b]);
        have[clr[b]].insert(clr[a]);
    }

    int res = -1;
    int winner = 10000000;
    for (int i = 1; i <= n; ++i) {
        int num = (int)have[clr[i]].size() - 1;
        if (res < num) {
            res = num;
            winner = clr[i];
        } else if (res == num) {
            winner = min(winner, clr[i]);
        }
    }

    cout << winner << endl;
    return 0;
}
