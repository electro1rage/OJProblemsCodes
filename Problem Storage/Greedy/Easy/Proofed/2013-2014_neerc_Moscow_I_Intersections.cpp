/*
reality, be rent!
synapse, break!
Van!shment Th!s World !!
*/
#include <bits/stdc++.h>
using namespace std;

const int MN = 202;
bitset<10101> a[MN];

int main() {
	int n, x, y, z, i, j, k;

	scanf("%d", &n);
	vector<vector<int> > v(n * (n - 1) / 2);
	for (i = 0; i < n * (n - 1) / 2; ++i) {
		scanf("%d %d %d", &x, &y, &k);
		--x, --y;
		v[i].push_back(x), v[i].push_back(y), v[i].push_back(k);
		bitset<10101> temp;
		for (j = 0; j < k; ++j) {
			scanf("%d", &z);
			v[i].push_back(z);
			temp[z] = true;
		}
		a[x] |= temp, a[y] |= temp;
	}

	for (i = 0; i < n * (n - 1) / 2; ++i) {
		x = v[i][0], y = v[i][1], k = v[i][2];
		bitset<10101> temp;
		for (j = 0; j < k; ++j) {
			z = v[i][j + 3];
			temp[z] = true;
		}
		bitset<10101> t;
		t = a[x], t &= a[y];
		if (t != temp) {
			puts("No");
			return 0;
		}
	}

	puts("Yes");
	for (i = 0; i < n; ++i) {
		vector<int> temp;
		for (j = 0; j < 10101; ++j) if (a[i][j] == true) temp.push_back(j);
		x = temp.size();
		printf("%d", x);
		for (j = 0; j < x; ++j) printf(" %d", temp[j]);puts("");
	}
	return 0;
}
