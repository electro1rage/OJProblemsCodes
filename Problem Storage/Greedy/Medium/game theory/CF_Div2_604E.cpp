/*
reality, be rent!
synapse, break!
Van!shment Th!s World !!
*/
#include <bits/stdc++.h>
using namespace std;

int g(int n, bool k) {
	if (k == 0) {
		if (n < 3) return n;
		return (n - 3) % 2;
	}
	if (n > 3 && n % 2 == 1) return 0;
	if (n <= 3) {
		return n == 3 || n == 1;
	}

	int i;
	bool have[3] = {};
	have[g(n - 1, k)] = true;
	have[g(n / 2, k)] = true;
	for (i = 0; i < 3; ++i) if (!have[i]) return i;
}

int main() {
	int n, k, i;
	scanf("%d %d", &n, &k);

	vector<int> a(n);
	for (i = 0; i < n; ++i) scanf("%d", &a[i]);

	string ans[] = {"Nicky", "Kevin"};
	int x = 0;
	for (i = 0; i < n; ++i) x ^= g(a[i], k % 2);
	puts(ans[!!x].c_str());
	return 0;
}
