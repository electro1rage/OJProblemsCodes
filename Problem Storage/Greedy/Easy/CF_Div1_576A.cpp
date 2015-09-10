#include <bits/stdc++.h>
using namespace std;

bool notprime[1010];

int main() {
	int n, i, j;
	scanf("%d", &n);

	vector<int> ans;
	for (i = 2; i * i <= n; ++i) {
		if (!notprime[i]) {
			for (j = i * i; j <= n; j += i) notprime[j] = true;
		}
	}

	for (i = 2; i <= n; ++i) {
		if (!notprime[i]) {
			for (j = i; j <= n; j *= i) ans.push_back(j);
		}
	}

	int sz = ans.size();
	cout << sz << endl;
	for (i = 0; i < sz; ++i) {
		if (i) putchar(' ');
		printf("%d", ans[i]);
	}
	puts("");
	return 0;
}
