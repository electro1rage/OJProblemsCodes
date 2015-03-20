#include <bits/stdc++.h>
using namespace std;

#define ROW 1
#define COL 2

struct swapop {
	int t, i, j;
	swapop(int t, int i, int j) {
		this->t = t;
		this->i = i;
		this->j = j;
	}
};

int n;
vector<int> row[1005];
vector<swapop> ans;

void make_swap(int t, int i, int j) {
	if (i == j) return;

	ans.push_back(swapop(t, i + 1, j + 1));

	if (t == ROW) {
		swap(row[i], row[j]);
	} else {
		for (int r = 0; r < n; ++r) {
			vector<int> &currow = row[r];
			int pos1 = lower_bound(currow.begin(), currow.end(), i) - currow.begin();
			int pos2 = lower_bound(currow.begin(), currow.end(), j) - currow.begin();

			if (pos1 != currow.size() && currow[pos1] == i) {
				currow[pos1] = j;
			}
			if (pos2 != currow.size() && currow[pos2] == j) {
				currow[pos2] = i;
			}

			sort(currow.begin(), currow.end());
		}
	}
}


int main() {
	scanf("%d", &n);

	for (int i = 0; i < n - 1; ++i) {
		int x, y;
		scanf("%d %d", &x, &y);

		--x, --y;

		row[x].push_back(y);
	}

	for (int i = 0; i < n; ++i)
		sort(row[i].begin(), row[i].end());

	//Code order looks so big, but in fact it's not that big, the code order is O(n^2).

	int c = 0;
	for (int r = 0; r < n; ++r) {
		int onesneeded = r - c;
		for (int i = 0; i < n; ++i) {
			vector<int> &currow = row[i];
			int sz = currow.size();
			int oneshave = sz - (lower_bound(currow.begin(), currow.end(), c) - currow.begin());
			if (oneshave == onesneeded) {
				vector<int> colswaped(currow.begin() + sz - oneshave, currow.end());
				make_swap(ROW, r, i);
				for (int j = 0; j < oneshave; ++j, ++c) {
					make_swap(COL, c, colswaped[j]);
				}
				break;
			}
		}
	}

	printf("%d\n", (int)ans.size());
	for (int i = 0; i < ans.size(); ++i)
		printf("%d %d %d\n", ans[i].t, ans[i].i, ans[i].j);
	return 0;
}





