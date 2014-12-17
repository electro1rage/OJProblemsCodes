#include <bits/stdc++.h>
using namespace std;


int n, m;
string a[105];
bool endOfGroup[105];

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	int res = 0;

	for (int i = 0; i < m; ++i) {
		bool bad = 0;
		for (int j = 1; j < n; ++j) {
			if (endOfGroup[j - 1]) continue;
			if (a[j][i] < a[j - 1][i]) bad = 1;
		}

		if (bad) {
			++res;
			continue;
		} else {
			for (int j = 1; j < n; ++j)
				if (a[j][i] != a[j - 1][i]) endOfGroup[j - 1] = 1;
		}
	}

	cout << res << endl;
	return 0;
}
