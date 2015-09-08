#include <bits/stdc++.h>
using namespace std;

long long get_dist(long long x1, long long y1, long long z1, long long x2, long long y2, long long z2) {
	long long xd = abs(x1 - x2), yd = abs(y1 - y2), zd = abs(z1 - z2);
	return xd * xd + yd * yd + zd * zd;
}

vector<int> v[8];

bool is_good() {
	vector<long long> dist;
	int i, j;
	for (i = 1; i < 8; ++i) dist.push_back(get_dist(v[0][0], v[0][1], v[0][2], v[i][0], v[i][1], v[i][2]));
	sort(dist.begin(), dist.end());
	dist.erase(unique(dist.begin(), dist.end()), dist.end());
	if (dist.size() != 3) return false;
	if (dist[0] == 0 || dist[1] == 0 || dist[2] == 0) return false;
	long long a = dist[0];
	long long b = a * 2;
	long long c = a * 3;

	if (dist[1] != b) return false;
	if (dist[2] != c) return false;

	vector<int> point[3];
	for (i = 1; i < 8; ++i) {
		long long dist = get_dist(v[0][0], v[0][1], v[0][2], v[i][0], v[i][1], v[i][2]);
		if (dist == a) point[0].push_back(i);
		if (dist == b) point[1].push_back(i);
		if (dist == c) point[2].push_back(i);
	}

	if (point[0].size() != 3) return false;
	if (point[1].size() != 3) return false;
	if (point[2].size() != 1) return false;

	int x1 = v[point[2][0]][0], y1 = v[point[2][0]][1], z1 = v[point[2][0]][2];
	for (i = 0; i < 3; ++i) {
		int x2 = v[point[0][i]][0], y2 = v[point[0][i]][1], z2 = v[point[0][i]][2];
		long long dist = get_dist(x1, y1, z1, x2, y2, z2);
		if (dist != b) return false;
	}

	for (i = 0; i < 3; ++i) {
		int x2 = v[point[1][i]][0], y2 = v[point[1][i]][1], z2 = v[point[1][i]][2];
		long long dist = get_dist(x1, y1, z1, x2, y2, z2);
		if (dist != a) return false;
	}

	for (i = 0; i < 3; ++i) {
		for (j = 0; j < 3; ++j) {
			int x2 = v[point[1][i]][0], y2 = v[point[1][i]][1], z2 = v[point[1][i]][2];
			int x3 = v[point[0][j]][0], y3 = v[point[0][j]][1], z3 = v[point[0][j]][2];
			long long dist = get_dist(x2, y2, z2, x3, y3, z3);
			if (dist != c && dist != b && dist != a) return false;
		}
	}

	for (i = 0; i < 3; ++i) {
		for (j = i + 1; j < 3; ++j) {
			int x2 = v[point[0][i]][0], y2 = v[point[0][i]][1], z2 = v[point[0][i]][2];
			int x3 = v[point[0][j]][0], y3 = v[point[0][j]][1], z3 = v[point[0][j]][2];
			long long dist = get_dist(x2, y2, z2, x3, y3, z3);
			if (dist != b) return false;
		}
	}

	for (i = 0; i < 3; ++i) {
		for (j = i + 1; j < 3; ++j) {
			int x2 = v[point[1][i]][0], y2 = v[point[1][i]][1], z2 = v[point[1][i]][2];
			int x3 = v[point[1][j]][0], y3 = v[point[1][j]][1], z3 = v[point[1][j]][2];
			long long dist = get_dist(x2, y2, z2, x3, y3, z3);
			if (dist != b) return false;
		}
	}

	return true;
}

int main() {
	int i, j;
	for (i = 0; i < 8; ++i) {
		v[i].resize(3);
		for (j = 0; j < 3; ++j) scanf("%d", &v[i][j]);
	}

	for (i = 0; i < 8; ++i) sort(v[i].begin(), v[i].end());

	do {
		do {
			do {
				do {
					do {
						do {
							do {
								do {
									if (is_good()) {
										puts("YES");
										for (i = 0; i < 8; ++i) {
											for (j = 0; j < 3; ++j) {
												if (j) putchar(' ');
												printf("%d", v[i][j]);
											}
											puts("");
										}
										return 0;
									}
								} while (next_permutation(v[7].begin(), v[7].end()));
							} while (next_permutation(v[6].begin(), v[6].end()));
						} while (next_permutation(v[5].begin(), v[5].end()));
					} while (next_permutation(v[4].begin(), v[4].end()));
				} while (next_permutation(v[3].begin(), v[3].end()));
			} while (next_permutation(v[2].begin(), v[2].end()));
		} while (next_permutation(v[1].begin(), v[1].end()));
	} while (next_permutation(v[0].begin(), v[0].end()));

	puts("NO");
	return 0;
}
