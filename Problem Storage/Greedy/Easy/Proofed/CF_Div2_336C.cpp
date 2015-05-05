#include <bits/stdc++.h>
using namespace std;

const int MN = 100005;

int a[MN];

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; ++i) scanf("%d", a + i);


	vector<int> ans;

	for (int i = 29; i >= 0; --i) {
		int mask = (1 << (i + 1)) - 1, tempmask = mask;
		for (int j = 0; j < n; ++j) {
			if ((a[j] >> i) & 1) tempmask &= a[j];
		}
		if ((mask & tempmask) == (1 << i)) {
			for (int j = 0; j < n; ++j) {
				if ((a[j] >> i) & 1) ans.push_back(a[j]);
			}
			break;
		}
	}

	printf("%d\n", (int)ans.size());
	for (int i = 0; i < ans.size(); ++i) {
		if (i) printf(" ");
		printf("%d", ans[i]);
	}
	puts("");
	return 0;
}
