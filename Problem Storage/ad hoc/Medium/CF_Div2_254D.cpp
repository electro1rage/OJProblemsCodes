#include <bits/stdc++.h>
using namespace std;

char grid[1005][1005];

int dx[] = {1, 0, 0, -1};
int dy[] = {0, 1, -1, 0};

struct pos{
	int x, y;
	pos() {
		x = y = 0;
	}
	pos(int x, int y){
		this->x = x;
		this->y = y;
	}
	bool operator<(const pos &temp) const {
		if (this->x < temp.x) return 1;
		if (this->x > temp.x) return 0;
		if (this->y < temp.y) return 1;
		return 0;
	}
};

bool operator==(const pos &temp1, const pos &temp2) {
	return (temp1.x == temp2.x && temp1.y == temp2.y);
}


int n, m;

bool valid(pos temp) {
	return (temp.x >= 0 && temp.x < n && temp.y >= 0 && temp.y < m && (grid[temp.x][temp.y] == '.' || grid[temp.x][temp.y] == 'R'));
}

int vst[1005][1005];
int clr;
vector<pos> get(int i, int j, int d) {
	++clr;
	queue<pos> Q;
	Q.push(pos(i, j));

	vst[i][j] = clr;
	vector<pos> ret;

	if (grid[i][j] == 'R') ret.push_back(pos(i, j));

	while (d > 0) {
		--d;
		int sz = Q.size();
		for (int i = 0; i < sz; ++i) {
			pos temp = Q.front();
			Q.pop();
			for (int j = 0; j < 4; ++j) {
				pos ntemp = pos(temp.x + dx[j], temp.y + dy[j]);
				if (valid(ntemp) && vst[ntemp.x][ntemp.y] != clr) {
					if (grid[ntemp.x][ntemp.y] == 'R') ret.push_back(ntemp);
					vst[ntemp.x][ntemp.y] = clr;
					Q.push(ntemp);
				}
			}
		}
	}

	return ret;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int d;

	scanf("%d %d %d", &n, &m, &d);

	vector<pos> rat;

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) {
			cin >> grid[i][j];
			if (grid[i][j] == 'R') rat.push_back(pos(i, j));
		}

	if (rat.size() >= 300) {
		puts("-1");
		return 0;
	}

	for (int i = rat[0].x - 8; i <= rat[0].x + 8; ++i) {
		for (int j = rat[0].y - 8; j <= rat[0].y + 8; ++j) {
			if (!valid(pos(i, j))) continue;
			vector<pos> bomb1 = get(i, j, d);
			vector<pos> rem;

			sort(bomb1.begin(), bomb1.end());

			if (!binary_search(bomb1.begin(), bomb1.end(), rat[0])) continue;

			pos nrat(-1, -1);
			for (int k = 0; k < rat.size(); ++k) {
				if (!binary_search(bomb1.begin(), bomb1.end(), rat[k])) {
					nrat = rat[k];
					rem.push_back(rat[k]);
				}
			}

			if (nrat.x == -1) {
				for (int k = 0; k < n; ++k)
					for (int l = 0; l < m; ++l) {
						if (valid(pos(k, l)) && (k != i || l != j)) {
							printf("%d %d %d %d\n", i + 1, j + 1, k + 1, l + 1);
							return 0;
						}
					}
			}

			for (int k = nrat.x - 8; k <= nrat.x + 8; ++k) {
				for (int l = nrat.y - 8; l <= nrat.y + 8; ++l) {
					if (!valid(pos(k, l))) continue;
					vector<pos> bomb2 = get(k, l, d);
					sort(bomb2.begin(), bomb2.end());

					if (!binary_search(bomb2.begin(), bomb2.end(), nrat)) continue;

					bool bad = 0;
					for (int ind = 0; ind < rem.size(); ++ind) {
						if (!binary_search(bomb2.begin(), bomb2.end(), rem[ind])) {
							bad = 1;
						}
					}

					if (bad) continue;

					printf("%d %d %d %d\n", i + 1, j + 1, k + 1, l + 1);
					return 0;
				}
			}
		}
	}

	cout << -1 << endl;
	return 0;
}




