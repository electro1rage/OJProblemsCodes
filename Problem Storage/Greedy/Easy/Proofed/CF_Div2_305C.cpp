#include <bits/stdc++.h>
using namespace std;

map<int, int> m;

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; ++i) {
		int x;
		scanf("%d", &x);
		++m[x];
	}

	int sz = 0, last;
	for (auto it = m.begin(); it != m.end(); ++it) {
		if (it->second != 1) {
			m[it->first + 1] += it->second / 2;
		}
		if (it->second % 2) {
			++sz;
			last = it->first;
		}
	}

	printf("%d\n", last - sz + 1);
	return 0;
}






