#include <bits/stdc++.h>
using namespace std;

vector<int> Asuna, Kristina;
vector<pair<int, int> > ans;

int get(vector<int> &x, int val) {
	int res = -1;
	int start = 0, finish = x.size() - 1;

	while (start <= finish) {
		int mid = (start + finish) / 2;
		if (x[mid] <= val) {
			res = mid;
			start = mid + 1;
		} else {
			finish = mid - 1;
		}
	}
	return res;
}

void go(int t) {
	int sets[2] = {};

	int a, b;
	a = b = 0;
	int n = Asuna.size(), m = Kristina.size();

	while (1) {
		int nexta = a + t;
		int nextb = b + t;

		if (nexta >= n && nextb >= m) return;

		if (nextb >= m || (nexta < n && Asuna[nexta] < Kristina[nextb])) {
			++sets[0];
			a = nexta;
			b = get(Kristina, Asuna[a]);
			if (a == n - 1 && nextb >= m) break;
		} else if (nexta >= n || (nextb < m && Asuna[nexta] > Kristina[nextb])) {
			++sets[1];
			b = nextb;
			a = get(Asuna, Kristina[b]);
			if (b == m - 1 && nexta >= n) break;
		}

	}

	if (sets[0] > sets[1]) {
		ans.push_back(make_pair(sets[0], t));
	}
}

int main() {
	int n;
	scanf("%d", &n);
	int a[100005];

	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
		a[i] = a[i] - 1;
	}

	if (a[n - 1]) {
		for (int i = 0; i < n; ++i)
			a[i] = !a[i];
	}

	Asuna.push_back(-1);
	Kristina.push_back(-1);

	for (int i = 0; i < n; ++i) {
		if (!a[i]) Asuna.push_back(i);
		else Kristina.push_back(i);
	}

	int scores[2] = {};

	for (int i = n - 1; i >= 0; --i) {
		++scores[a[i]];
		if (scores[0] > scores[1] && !a[i]) {
			go(scores[0]);
		}
	}

	sort(ans.begin(), ans.end());

	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); ++i) {
		cout << ans[i].first << ' ' << ans[i].second << endl;
	}
	return 0;
}



