#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

int main() {
	long long res = 0;

	int a, b;
	cin >> a >> b;

	cout << ((((long long)b * (b - 1) / 2) % MOD) * ((((long long)b * (((long long)a * (a + 1) / 2) % MOD) % MOD) + a) % MOD)) % MOD << endl;
	return 0;
}
