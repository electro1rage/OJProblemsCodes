#include <bits/stdc++.h>
using namespace std;

long long C, Hr, Hb, Wr, Wb;

long long get_ans() {
	long long ans = 0;
	for (int x = 0; x < 1000000; ++x) {
		long long y = (C - x * Wr) / Wb;
		if (y < 0) break;
		if (x * Wr + y * Wb <= C) ans = max(ans, x * Hr + y * Hb);
	}

	for (int y = 0; y < 1000000; ++y) {
		long long x = (C - y * Wb) / Wr;
		if (x < 0) break;
		if (x * Wr + y * Wb <= C) ans = max(ans, x * Hr + y * Hb);
	}

	return ans;
}

int main() {
	cin >> C >> Hr >> Hb >> Wr >> Wb;

	long long res = max(max(C / Wr * Hr, C / Wb * Hb), get_ans());

	cout << res << endl;
	return 0;
}




