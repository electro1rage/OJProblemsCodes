#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);

	if (n < 3) {
		printf("%d\n", -1);
		return 0;
	}

	if (n == 3) {
		printf("210\n");
		return 0;
	}

	int mod = 1;
	for (int i = 0; i < n - 2; ++i) {
		mod = (mod * 10) % 21;
	}

	mod = 21 - mod;
	string s(n, '0');
	s[0] = '1';

	s[n - 2] = mod % 10 + '0';
	s[n - 3] = mod / 10 + '0';

	cout << s << endl;
	return 0;
}
