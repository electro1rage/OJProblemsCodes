/*
reality, be rent!
synapse, break!
Van!shment Th!s World !!
*/
#include <bits/stdc++.h>
using namespace std;

struct node {
	int x, y;
	node& operator=(const node& n) {
		this->x = n.x, this->y = n.y;
		return *this;
	}
};

node parent[55][55];
bool vst[55][55];
vector<vector<int> > ans;
int n, m, k;
int dx[] = {1, 0, 0, -1};
int dy[] = {0, 1, -1, 0};

void add_path(int x, int y, int &ret) {
	vector<int> v;
	node cur = {x, y};
	v.push_back(cur.x + 1), v.push_back(cur.y + 1);
	while (parent[cur.x][cur.y].x != -1) cur = parent[cur.x][cur.y], v.push_back(cur.x + 1), v.push_back(cur.y + 1);
	reverse(v.begin(), v.end());
	ans.push_back(v);
	ret += v.size();
}

int bfs(int xs = 0, int ys = 0) {
	int ret = 0;
	int sz, x, y, i;
	vst[xs][ys] = true;
	parent[xs][ys] = {-1, -1};
	add_path(0, 0, ret);
	--k;
	queue<node> q;
	q.push({xs, ys});
	if (k == 0) return ret;

	while (!q.empty()) {
		sz = q.size();
		while (sz--) {
			x = q.front().x, y = q.front().y, q.pop();
			for (i = 0; i < 4; ++i) {
				int nx = x + dx[i], ny = y + dy[i];
				if (nx >= 0 && nx < n && ny >= 0 && ny < m && !vst[nx][ny]) {
					parent[nx][ny] = {x, y};
					vst[nx][ny] = true;
					add_path(nx, ny, ret);
					--k;
					q.push({nx, ny});
					if (k == 0) return ret;
				}
			}
		}
	}
	puts("kawaii");
	return 0.0;
}

int main() {
	scanf("%d %d %d", &n, &m, &k);

	printf("%d\n", bfs() / 2);
	reverse(ans.begin(), ans.end());
	int sz = ans.size(), sz2, i, j;
	for (i = 0; i < sz; ++i) {
		sz2 = ans[i].size();
		for (j = 0; j < sz2; j += 2) {
			if (j) putchar (' ');
			printf("(%d,%d)", ans[i][j + 1], ans[i][j]);
		}
		puts("");
	}
	return 0;
}
