#include <bits/stdc++.h>
using namespace std;

bool is_better(int x, int y) {
	cout << 1 << ' ' << x << ' ' << y << endl;
	cout.flush();
	string s;
	cin >> s;
	return s == "YES";
}

int* merge(int *a, int asz, int *b, int bsz) {
	int *ret = new int[asz + bsz];
	int i = 0, j = 0;
	while (i < asz && j < bsz) {
		if (is_better(a[i], b[j])) ret[i + j] = a[i], ++i;
		else ret[i + j] = b[j], ++j;
	}

	while (i < asz) ret[i + j] = a[i], ++i;
	while (j < bsz) ret[i + j] = b[j], ++j;

	return ret;
}

int* merge_sort(int *a, int sz) {
	if (sz == 1) {
		int *ret = new int[1];
		ret[0] = a[0];
		return ret;
	}

	int sz1 = sz / 2, sz2 = sz - sz / 2;
	return merge(merge_sort(a, sz1), sz1, merge_sort(a + sz1, sz2), sz2);
}

int temp[1010];
int *ans;

int main() {
	int n, i;
	cin >> n;
	for (i = 0; i < n; ++i) temp[i] = i + 1;

	ans = merge_sort(temp, n);
	cout << 0;
	for (i = 0; i < n; ++i) {
		cout << ' ' << ans[i];
	}
	cout << endl;
	cout.flush();
	return 0;
}
