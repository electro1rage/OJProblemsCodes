#include <bits/stdc++.h>
using namespace std;

const int MN = 101010;

pair<int, int> a[MN], b[MN];
int c[MN], n, m, s;
vector<int> ans;
int pos[MN];

bool is_good(int d) {
	int i, j;
	vector<int> temp(m, -1);
	long long sum = 0;
	priority_queue<pair<int, int> > q;
	for (i = m - 1, j = n - 1; i >= 0; i -= d) {
		while (j >= 0 && b[j].first >= a[i].first) q.push({-c[b[j].second], b[j].second}), --j;
		if (q.empty()) return false;
		temp[i] = q.top().second, sum += -q.top().first, q.pop();
	}
	if (sum > s) return false;
	ans = temp;
	return true;
}

int main() {
	scanf("%d %d %d", &n, &m, &s);
	int i;
	for (i = 0; i < m; ++i) scanf("%d", &a[i].first), a[i].second = i;
	for (i = 0; i < n; ++i) scanf("%d", &b[i].first), b[i].second = i;
	for (i = 0; i < n; ++i) scanf("%d", c + i);

	sort(a, a + m), sort(b, b + n);
	int s = 0, e = MN;
	while (s <= e) {
		int mid = (s + e) / 2;
		if (is_good(mid)) e = mid - 1;
		else s = mid + 1;
	}

	if (ans.empty()) {
		puts("NO");
		return 0;
	}

	int last;
	for (i = m - 1; i >= 0; --i) {
		if (ans[i] != -1) last = ans[i];
		pos[a[i].second] = last + 1;
	}

	puts("YES");
	for (i = 0; i < m; ++i) {
		if (i) putchar(' ');
		printf("%d", pos[i]);
	}
	puts("");
	return 0;
}
