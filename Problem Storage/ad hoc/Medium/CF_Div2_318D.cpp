#include <bits/stdc++.h>
using namespace std;

const int MAXN = 130;

int dx[] = {1, 0, 0, -1};
int dy[] = {0, -1, 1, 0};

int cur[MAXN][MAXN];
int n;

int xy2m(int p) {
	return p + MAXN / 2;
}

int valid(int x, int y) {
	return xy2m(x) >= 0 && xy2m(x) < MAXN && xy2m(y) >= 0 && xy2m(y) < MAXN;
}

void preprocess() {
	cur[xy2m(0)][xy2m(0)] = n;

	bool change = true;
	while (change) {
		change = false;
		for (int i = 0; i < MAXN; ++i) {
			for (int j = 0; j < MAXN; ++j) {
				if (cur[i][j] >= 4) {
					change = true;
					for (int k = 0; k < 4; ++k) {
						cur[i + dx[k]][j + dy[k]] += cur[i][j] / 4;
					}
					cur[i][j] %= 4;
				}
			}
		}
	}

}

int main() {
	int t;
	scanf("%d %d", &n, &t);

	preprocess();

	for (int i = 0; i < t; ++i) {
		int x, y;
		scanf("%d %d", &x, &y);
		if (!valid(x, y)) {
			puts("0");
		} else {
			int nx = xy2m(x), ny = xy2m(y);
			printf("%d\n", cur[nx][ny]);
		}
	}
	return 0;
}






