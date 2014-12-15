#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	int p, n;

	cin >> n >> p >> s;

	for (int i = n - 1; i >= 0; --i) {
		for (int j = s[i] + 1; j < p + 'a'; ++j) {
			bool bad = 0;
			if (i && s[i - 1] == j) {
				bad = 1;
			}
			if (i > 1 && s[i - 2] == j) {
				bad = 1;
			}
			if (!bad) {
				s[i] = j;
				for (int l = i + 1; l < n; ++l) {
					for (int k = 'a'; k < p + 'a'; ++k) {
						bool good = 1;
						if (l && s[l - 1] == k) {
							good = 0;
						}
						if (l > 1 && s[l - 2] == k) {
							good = 0;
						}
						if (good) {
							s[l] = k;
							break;
						}
					}
				}
				cout << s << endl;
				return 0;
			}
		}
	}

	cout << "NO" << endl;
	return 0;
}
