#include <bits/stdc++.h>
using namespace std;

int main() {
	long long n;
	cin >> n;

	vector<long long> a;

	for (long long i = 1; ; i *= 3) {
		a.push_back(i);
		if (i > n) break;
	}

	for (int i = 0; i < a.size(); ++i) if (n % a[i]) {
		cout << (n + a[i] - 1) / a[i] << endl;
		break;
	}
	return 0;
}
