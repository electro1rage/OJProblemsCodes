#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n;

	vector<int> Asuna(n);
	vector<int> Akame(1);

	for (int i = 0; i < n; ++i) {
		cin >> Asuna[i];
		Akame.push_back(Asuna[i]);
	}

	cin >> m;
	vector<int> Kristina(m);
	for (int i = 0; i < m; ++i) {
		cin >> Kristina[i];
		Akame.push_back(Kristina[i]);
	}

	sort(Asuna.begin(), Asuna.end());
	sort(Kristina.begin(), Kristina.end());

	Asuna.push_back(2000000005);
	Kristina.push_back(2000000005);

	int first = 0, second = 2000000000;
	for (int i = 0; i < n + m + 1; ++i) {
		int val = Akame[i];
		int nf, ns;

		int indf = upper_bound(Asuna.begin(), Asuna.end(), val) - Asuna.begin();
		nf = 2 * indf + 3 * (n - indf);

		int inds = upper_bound(Kristina.begin(), Kristina.end(), val) - Kristina.begin();
		ns = 2 * inds + 3 * (m - inds);

		if (first - second < nf - ns || (first - second == nf - ns && nf > first)) {
			first = nf;
			second = ns;
		}
	}

	cout << first << ":" << second << endl;
	return 0;
}
