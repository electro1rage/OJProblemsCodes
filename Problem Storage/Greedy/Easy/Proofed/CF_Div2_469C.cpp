#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, i;
	scanf("%d", &n);

	if (n < 4) {
		puts("NO");
		return 0;
	}

	if (n == 4) {
		puts("YES");
		puts("1 * 2 = 2");
		puts("2 * 3 = 6");
		puts("6 * 4 = 24");
		return 0;
	}

	if (n == 5) {
		puts("YES");
		puts("5 - 3 = 2");
		puts("1 + 2 = 3");
		puts("2 * 3 = 6");
		puts("6 * 4 = 24");
		return 0;
	}

	puts("YES");

	cout << n << " - " << n - 1 << " = 1" << endl;
	cout << 1 << " - " << 1 << " = 0" << endl;
	for (i = 5; i <= n - 2; ++i) {
		cout << "0 * " << i << " = 0" << endl;
	}
	cout << "0 + 2 = 2" << endl;
	cout << "2 * 3 = 6" << endl;
	cout << "6 * 4 = 24" << endl;
	return 0;
}
