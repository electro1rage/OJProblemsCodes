#include <bits/stdc++.h>
using namespace std;

char ans[1000005];

int main() {
	int n;
	scanf("%d", &n);

	queue<pair<int, int> > q;

	int a = 0, g = 0;
	for (int i = 0; i < n; ++i) {
		int x, y;
		scanf("%d %d", &x, &y);

		q.push({x, y});

		g += y;

		ans[i] = 'G';
	}

	int ind = 0;
	while (abs(g - a) > 500 && !q.empty()) {
		g -= q.front().second;
		a += q.front().first;
		q.pop();
		ans[ind] = 'A'; ++ind;
	}

	if (abs(g - a) > 500) {
		puts("-1");
		return 0;
	}
	printf("%s\n", ans);
	return 0;
}








