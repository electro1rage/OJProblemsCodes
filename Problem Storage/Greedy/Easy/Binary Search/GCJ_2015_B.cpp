#include <bits/stdc++.h>
using namespace std;

int K = 1;

int a[1010];

void print_ans(int ans) {
	cout << "Case #" << K++ << ": " << ans << endl;
}

long long get_minute(int n, int b) {
	long long s = 1, e = 1000000000000000LL;
	long long res;
	while (s <= e) {
		long long mid = (s + e) / 2;
		long long num = 0;
		for (int i = 0; i < b; ++i) num += mid / a[i] + 1;
		if (num < n) {
			s = mid + 1;
			res = mid;
		} else {
			e = mid - 1;
		}
	}
	return res;
}

int main() {
	freopen("B-large.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T;
	cin >> T;
	while (T--) {
		int b, n;
		cin >> b >> n;
		for (int i = 0; i < b; ++i) cin >> a[i];

		if (n <= b) {
			print_ans(n);
			continue;
		}

		long long minute = get_minute(n, b);

		long long number = 1;
		for (int i = 0; i < b; ++i) number += minute / a[i] + 1;

		++minute;

		for (int i = 0; i < b; ++i) {
			if (minute % a[i] == 0) {
				if (number == n) {
					print_ans(i + 1);
					break;
				}
				++number;
			}
		}
	}
	return 0;
}




