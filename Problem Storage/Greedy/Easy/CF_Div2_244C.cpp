#include <bits/stdc++.h>
using namespace std;

int arr[100005];
bool used[1048578];
int zero[100005][20];

int main() {
	int n;
	cin >> n;

	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];
	}

	for (int i = n - 1; i > 0; --i) {
		for (int j = 0; j < 20; ++j) {
			if (!((arr[i] >> j) & 1)) zero[i][j] = zero[i + 1][j] + 1;
		}
	}

	for (int i = 1; i <= n; ++i) {
		int temp = arr[i];
		used[temp] = 1;
		vector<int> change;
		for (int j = 0; j < 20; ++j) {
			if (!((arr[i] >> j) & 1)) {
				int ind = i + zero[i][j];
				change.push_back(ind);
			}
		}
		sort(change.begin(), change.end());
		for (auto &x : change) {
			temp |= arr[x];
			used[temp] = 1;
		}
	}

	int res = 0;
	for (int i = 0; i < 1048578; ++i)
		res += used[i];

	cout << res << endl;
	return 0;
}
