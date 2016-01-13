/*
reality, be rent!
synapse, break!
Van!shment Th!s World !!
*/
#include <bits/stdc++.h>
using namespace std;

#define NO 0
#define BLOCK 1
#define EMPTY 2

const int MN = 50;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
string dir[] = {"NORTH", "EAST", "SOUTH", "WEST", "DONE"};

vector<int> path;
bool vst[2 * MN][2 * MN];
int done[2 * MN][2 * MN];

bool dfs(int x, int y) {
	vst[x][y] = true;
	if (done[x][y] == NO) return true;

	int nx, ny, i;
	for (i = 0; i < 4; ++i) {
		nx = x + dx[i], ny = y + dy[i];
		if (nx >= 0 && nx < 2 * MN && ny >= 0 && ny < 2 * MN && !vst[nx][ny] && done[nx][ny] != BLOCK) {
			if (dfs(nx, ny)) {
				path.push_back(i);
				return true;
			}
		}
	}

	return false;
}

int main() {
	int x = MN, y = MN;
	done[x][y] = EMPTY;
	string s;
	while (dfs(x, y)) {
		reverse(path.begin(), path.end());
		for (auto i : path) {
			cout << dir[i] << endl;
			cout.flush();
			cin >> s;
			int nx = x + dx[i], ny = y + dy[i];
			if (s == "BLOCKED") {
				done[nx][ny] = BLOCK;
				break;
			}
			done[nx][ny] = EMPTY;
			x = nx, y = ny;
		}
		path.clear();
		memset(vst, 0, sizeof vst);
	}
	cout << dir[4] << endl;
	cout.flush();
	return 0;
}
