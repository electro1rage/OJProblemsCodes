#include <bits/stdc++.h>
using namespace std;

const int MN = 105;

char grid[MN][MN];

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; ++i) scanf("%s", grid[i]);

	vector<pair<int, int> > ans;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (grid[i][j] == '.') {
				ans.push_back({i, j});
				break;
			}
		}
	}

	if (ans.size() == n) {
		for (int i = 0; i < n; ++i) printf("%d %d\n", ans[i].first + 1, ans[i].second + 1);
		return 0;
	}

	ans.clear();
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (grid[j][i] == '.') {
				ans.push_back({j, i});
				break;
			}
		}
	}

	if (ans.size() == n) {
		for (int i = 0; i < n; ++i) printf("%d %d\n", ans[i].first + 1, ans[i].second + 1);
		return 0;
	}

	printf("-1\n");
	return 0;
}









