#include <bits/stdc++.h>
using namespace std;

int main() {
	char s[5][12];
	int n = 5, m = 9, i, j, k;

	for (i = 0; i < n; ++i) scanf("%s", s[i]);

	vector<int> x, y(12, -1);
	bool have[13] = {};
	for (i = 0, k = 0; i < n; ++i) for (j = 0; j < m; ++j) {
		if (s[i][j] != '.' && s[i][j] != 'x') have[s[i][j] - 'A' + 1] = true;
		if (s[i][j] == 'x') ++k;
		else if (s[i][j] != '.') y[k] = s[i][j] - 'A' + 1, ++k;
	}

	for (i = 1; i < 13; ++i) if (!have[i]) x.push_back(i);

	do {
		int b[6] = {}, i, j, k;
		vector<int> a = y;
		for (i = 0, j = 0; i < 12; ++i) if (a[i] == -1) a[i] = x[j], ++j;

		b[0] += a[0], b[1] += a[0];
		b[3] += a[1], b[4] += a[1];
		b[1] += a[2], b[4] += a[2];
		b[0] += a[3], b[4] += a[3];
		b[4] += a[4], b[5] += a[4];
		b[3] += a[5], b[1] += a[5];
		b[5] += a[6], b[0] += a[6];
		b[1] += a[7], b[2] += a[7];
		b[2] += a[8], b[3] += a[8];
		b[2] += a[9], b[5] += a[9];
		b[0] += a[10], b[2] += a[10];
		b[3] += a[11], b[5] += a[11];

		bool bad = false;
		for (i = 0; i < 6; ++i) if (b[i] != 26) bad = true;

		if (!bad) {
			for (i = 0, k = 0; i < n; ++i) {
				for (j = 0; j < m; ++j) {
					if (s[i][j] != '.') printf("%c", a[k] + 'A' - 1), ++k;
					else printf(".");
				}
				printf("\n");
			}
			break;
		}
	} while (next_permutation(x.begin(), x.end()));

	return 0;
}
