#include <bits/stdc++.h>
using namespace std;

#define eps 1e-9

pair<double, int> a[10101];

bool smaller(double x, double y) {
	return eps < y - x;
}

bool bigger(double x, double y) {
	return x - y > eps;
}

bool equal(double x, double y) {
	return abs(x - y) < eps;
}


int main() {
	int n, i;
	cin >> n;
	for (i = 0; i < n; ++i) {
		cin >> a[i].first, a[i].second = i + 1;
		if (equal(a[i].first, 0.0)) a[i].first = 0.0;
	}

	sort(a, a + n);
	vector<pair<double, int> > nv, pv;
	for (i = 0; i < n; ++i) {
		if (smaller(a[i].first, 0)) nv.push_back(a[i]);
		else pv.push_back(a[i]);
	}
	bool havenv = false, havepv = false;
	int nvsz = nv.size(), pvsz = pv.size();
	vector<int> nvbest, pvbest, rbest;
	rbest.push_back(a[n - 1].second);
	if (nvsz > 1) {
		havenv = true;
		for (i = 0; i < nvsz - (nvsz % 2); ++i) {
			if (bigger(nv[i].first, -1) || equal(nv[i].first, -1)) break;
			nvbest.push_back(nv[i].second);
		}
		if (i == 0) nvbest.push_back(nv[0].second), nvbest.push_back(nv[1].second);
		else if (i == 1) nvbest.push_back(nv[i].second);
		else if (i % 2) {
			if (smaller(nv[i - 1].first * nv[i].first, 1) || equal(nv[i - 1].first * nv[i].first, 1)) nvbest.pop_back();
			else nvbest.push_back(nv[i].second);
		}
	}

	if (pvsz) {
		havepv = true;
		for (i = pvsz - 1; i >= 0; --i) {
			if (smaller(pv[i].first, 1.0) || equal(pv[i].first, 1.0)) break;
			pvbest.push_back(pv[i].second);
		}
		if (i == pvsz - 1) pvbest.push_back(pv.back().second);
	}

	vector<int> ans;
	if (havepv && havenv) {
		double l = nv[0].first * nv[1].first, r = pv[pvsz - 1].first;
		if ((smaller(l, 1) || equal(l, 1))  && (smaller(r, 1) || equal(r, 1))) {
			if (bigger(r, l) || equal(r, l)) for (auto &x : pvbest) ans.push_back(x);
			else for (auto &x : nvbest) ans.push_back(x);
		} else if ((smaller(l, 1.0) || equal(l, 1.0)) && (bigger(r, 1))) {
			for (auto &x : pvbest) ans.push_back(x);
		} else if ((bigger(l, 1.0)) && (smaller(r, 1) || equal(r, 1))) {
			for (auto &x : nvbest) ans.push_back(x);
		} else if (bigger(l, 1.0) && bigger(r, 1.0)) {
			for (auto &x : nvbest) ans.push_back(x);
			for (auto &x : pvbest) ans.push_back(x);
		}
	} else if (havepv) {
		for (auto &x : pvbest) ans.push_back(x);
	} else {
		for (auto &x : nvbest) ans.push_back(x);
	}

	sort(ans.begin(), ans.end());
	int sz = ans.size();
	cout << sz << endl;
	for (i = 0; i < sz; ++i) {
		if (i) cout << ' ';
		cout << ans[i];
	}
	cout << endl;
	return 0;
}
