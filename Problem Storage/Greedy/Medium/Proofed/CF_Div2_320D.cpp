#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;

int a[MAXN];
int id[MAXN];
int ans[MAXN];

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; ++i) scanf("%d", a + i), id[a[i]] = i;

	stack<int> s;
	for (int i = 0; i < n; ++i) {
		ans[i] = 1;
		while (!s.empty() && a[i] > s.top()) {
			ans[i] = max(ans[i], ans[id[s.top()]] + 1);
			s.pop();
		}
		if (s.empty()) ans[i] = 0;
		s.push(a[i]);
	}

	printf("%d\n", *max_element(ans, ans + n));
	return 0;
}




