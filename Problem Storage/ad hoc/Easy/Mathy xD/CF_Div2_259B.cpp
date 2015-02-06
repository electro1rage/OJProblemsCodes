#include <bits/stdc++.h>
using namespace std;

int grid[3][3];

int main() {
	int n = 3;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			scanf("%d", &grid[i][j]);

	int sum = 0, x;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			sum += grid[i][j];

	x = sum / 2;
	for (int i = 0; i < n; ++i) {
		int temp = 0;
		for (int j = 0; j < n; ++j)
			temp += grid[i][j];
		grid[i][i] = x - temp;
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j)
			printf("%d ", grid[i][j]);
		puts("");
	}
	return 0;
}
