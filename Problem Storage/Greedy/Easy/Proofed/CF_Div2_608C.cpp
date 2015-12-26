/*
reality, be rent!
synapse, break!
Van!shment Th!s World !!
*/
#include <bits/stdc++.h>
using namespace std;

const int MM = 1010101, MN = 101010;

bool good[MM];
int mini[MM];
int dist[MM];

int main() {
	int n, x, y, i;
	scanf("%d", &n);

	for (i = 0; i < n; ++i) {
		scanf("%d %d", &x, &y);
		good[x] = true;
		mini[x] = 1;
		dist[x] = y;
	}

	for (i = 0; i < MM; ++i) {
		if (!good[x]) {
			if (i) mini[i] = mini[i - 1];
		} else {
			if (i - dist[i] - 1 >= 0) mini[i] += mini[i - dist[i] - 1];
		}
	}

	int ans = MN;
	for (i = 0; i < MM; ++i) ans = min(ans, n - mini[i]);

	printf("%d\n", ans);
	return 0;
}
