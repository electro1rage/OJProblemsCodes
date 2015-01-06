#include<bits/stdc++.h>
using namespace std;

int n;

int place[305];
int a[305];


bool dp[305][305];


int main() {
	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		--a[i];

		place[a[i]] = i;
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			char x;
			cin >> x;
			if (x == '1') {
				dp[i][j] = 1;
			}
		}
	}


	for (int k = 0; k < n; ++k) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				dp[i][j] |= dp[i][k] & dp[k][j];
			}
		}
	}

	for (int i = 0; i < n; ++i)
		dp[i][i] = 1;

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < place[i]; ++j) {
			if (dp[place[i]][j] && a[j] > i) {
				int ind = place[i];
				swap(place[i], place[a[j]]);
				swap(a[j], a[ind]);
				break;
			}
		}

	for (int i = 0; i < n; ++i)
		cout << a[i] + 1 << ' ';cout << endl;
	return 0;
}
