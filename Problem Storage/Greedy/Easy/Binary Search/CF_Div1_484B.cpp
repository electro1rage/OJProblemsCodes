#include <bits/stdc++.h>
using namespace std;

int a[200005];
int smallerThan[2000005];

int getBiggestSmallerThan(int start, int finish, int val) {
	int res = -1;
	while (start <= finish) {
		int mid = (start + finish) / 2;
		if (a[mid] >= val) {
			finish = mid - 1;
		} else {
			res = mid;
			start = mid + 1;
		}
	}
	return res;
}

int main() {
	int n, maxi = -1, res = 0;

	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
		maxi = max(maxi, a[i]);
	}

	sort(a, a + n);

	for (int i = 1; i <= 2 * 1000000; ++i) {
		int res = getBiggestSmallerThan(0, n - 1, i);
		if(res != -1)smallerThan[i] = a[res];
	}

	for (int i = 0; i < n; ++i) {
		if (i && a[i] == a[i - 1])continue;
		for (int j = a[i] * 2;; j += a[i]) {
			int pre = j - a[i];
			if (smallerThan[j] > pre) {
				res = max(res, smallerThan[j] - pre);
			}

			if (j > maxi)break;
		}
	}

	printf("%d\n", res);
	return 0;
}
