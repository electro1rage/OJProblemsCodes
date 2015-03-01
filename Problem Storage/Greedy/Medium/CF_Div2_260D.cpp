#include <bits/stdc++.h>
using namespace std;

struct node {
	int u, s;
	node() {
		u = s = 0;
	}
	node(int u, int s) {
		this->u = u;
		this->s = s;
	}
	bool operator<(const node &temp) const {
		if (this->s < temp.s) return 1;
		return 0;
	}
};

node black[100005];
node white[100005];

int main() {
	int n;
	scanf("%d", &n);

	int w, b;
	w = b = 0;
	for (int i = 0; i < n; ++i) {
		int c, s;
		scanf("%d %d", &c, &s);
		if (c == 0) {
			white[w] = node(i, s);
			++w;
		} else {
			black[b] = node(i, s);
			++b;
		}
	}

	sort(black, black + b);
	sort(white, white + w);

	int indw = 0, indb = 0;
	while (indw < w && indb < b) {
		printf("%d %d %d\n", white[indw].u + 1, black[indb].u + 1, min(white[indw].s, black[indb].s));
		if (white[indw].s < black[indb].s) {
			black[indb].s -= white[indw].s;
			++indw;
		} else {
			white[indw].s -= black[indb].s;
			++indb;
		}
	}

	++indw;
	while (indw < w) {
		printf("%d %d %d\n", white[indw].u + 1, black[0].u + 1, white[indw].s);
		++indw;
	}
	return 0;
}


