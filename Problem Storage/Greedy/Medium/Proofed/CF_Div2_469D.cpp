#include <bits/stdc++.h>
using namespace std;

const int MN = 101010;

map<int, int> m;
int ans[MN], a[MN];
int num[2];

bool is_good(int x) {
	deque<int> q;
	q.push_back(x);
	bool cur1 = 0, cur2 = 1;
	while (true) {
		int nex = num[cur1] - q.back();
		if (!m.count(nex) || nex == q.front() || nex == q.back()) break;
		q.push_back(nex), cur1 = !cur1;
	}
	while (true) {
		int nex = num[cur2] - q.front();
		if (!m.count(nex) || nex == q.front() || nex == q.back()) break;
		q.push_front(nex), cur2 = !cur2;
	}
	int sz = q.size();
	if (sz % 2) {
		if (num[cur2] - q.front() == q.front()) cur2 = !cur2, ++sz;
		if (sz % 2) {
			if (num[cur1] - q.back() == q.back()) ++sz;
			if (sz % 2) return false;
		}
	}
	cur2 = !cur2;
	while (!q.empty()) {
		int nex = q.front(); q.pop_front();
		ans[m[nex]] = cur2, m[nex] = -1;
	}
	return true;
}

int main() {
	int n, i;
	scanf("%d %d %d", &n, &num[0], &num[1]);
	for (i = 0; i < n; ++i) scanf("%d", a + i), m[a[i]] = i;

	for (i = 0; i < n; ++i) {
		if (m[a[i]] == -1) continue;
		if (is_good(a[i])) continue;
		puts("NO");
		return 0;
	}
	puts("YES");
	for (i = 0; i < n; ++i) {
		if (i) putchar(' ');
		printf("%d", ans[i]);
	}
	puts("");
	return 0;
}
