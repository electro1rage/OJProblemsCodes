#include <bits/stdc++.h>
using namespace std;

const int MN = 2020, MVAL = 2020202;

vector<vector<pair<int, int> > > b, r;

vector<vector<pair<int, int> > > normalize(vector<pair<int, int> > &a, int sign) {
	bool vst[MN] = {};
	int n = a.size(), i, j;
	vector<vector<pair<int, int> > > ret;
	for (i = 0; i < n; ++i) {
		if (!vst[i]) {
			ret.push_back(vector<pair<int, int> > ());
			ret.back().push_back(a[i]);
			for (j = i + 1; j < n; ++j) {
				if (vst[j]) continue;
				if (abs(a[i].first - a[j].first) != abs(a[i].second - a[j].second)) continue;
				if ((a[i].first - a[j].first) / (a[i].second - a[j].second) != sign) continue;
				vst[j] = true;
				ret.back().push_back(a[j]);
			}
		}
	}
	n = ret.size();
	for (i = 0; i < n; ++i) sort(ret[i].begin(), ret[i].end());
	return ret;
}

vector<pair<pair<int, int>, pair<int, int> > > get_segments(vector<vector<pair<pair<int, int>, pair<int, int> > > > &a) {
	int n = a.size(), i, j;
	vector<pair<pair<int, int>, pair<int, int> > > ret;
	for (i = 0; i < n; ++i) {
		int sz = a[i].size();
		pair<int, int> s = a[i][0].first, e = a[i][0].second;
		for (j = 0; j < sz; ++j) {
			if (e < a[i][j].first) ret.push_back({s, e}), s = a[i][j].first, e = a[i][j].second;
			else e = max(e, a[i][j].second);
		}
		ret.push_back({s, e});
	}
	return ret;
}

vector<vector<pair<pair<int, int>, pair<int, int> > > > get_aftert(vector<vector<pair<int, int> > > &b, int t, int sign) {
	int n = b.size(), i, j;
	vector<vector<pair<pair<int, int>, pair<int, int> > > > ret(n);

	for (i = 0; i < n; ++i) {
		int sz = b[i].size();
		for (j = 0; j < sz; ++j) {
			int x = b[i][j].first, y = b[i][j].second;
			ret[i].push_back({{x - t, y + sign * t}, {x + t, y - sign * t}});
		}
	}
	return ret;
}

bool is_in(int x1, int x2, int x) {
	if (x1 > x2) swap(x1, x2);
	return x >= x1 && x <= x2;
}

bool intersects(pair<pair<int, int>, pair<int, int> > &b, pair<pair<int, int>, pair<int, int> > &r) {
	int xin, yin;
	int x11 = b.first.first, y11 = b.first.second, x21 = b.second.first, y21 = b.second.second;
	int x12 = r.first.first, y12 = r.first.second, x22 = r.second.first, y22 = r.second.second;
	x11 *= 2, y11 *= 2, x21 *= 2, y21 *= 2, x12 *= 2, y12 *= 2, x22 *= 2, y22 *= 2;
	xin = (x11 + x12 + y11 - y12) / 2;
	yin = y11 + x11 - xin;
	if (is_in(x11, x21, xin) && is_in(x12, x22, xin) && is_in(y11, y21, yin) && is_in(y12, y22, yin)) return true;
	return false;
}

bool is_rectangle(vector<int> &a, vector<int> &b) {
	if (a.empty() || b.empty()) return false;
	int ret = 0;
	auto it1 = a.begin(), it2 = b.begin();
	while (it1 != a.end() && it2 != b.end()) {
		if (*it1 == *it2) ++ret, ++it1;
		else if (*it1 < *it2) it1 = lower_bound(a.begin(), a.end(), *it2);
		else it2 = lower_bound(b.begin(), b.end(), *it1);

		if (ret == 2) return true;
	}

	return false;
}

bool is_good(int t) {
	vector<vector<pair<pair<int, int>, pair<int, int> > > > nr, nb;
	nr = get_aftert(r, t, -1), nb = get_aftert(b, t, 1);
	vector<pair<pair<int, int>, pair<int, int> > > bseg, rseg;
	bseg = get_segments(nb), rseg = get_segments(nr);

	int bsz = bseg.size(), rsz = rseg.size(), i, j;
	vector<vector<int> > bin(bsz);
	for (i = 0; i < bsz; ++i) {
		for (j = 0; j < rsz; ++j) {
			if (intersects(bseg[i], rseg[j])) bin[i].push_back(j);
		}
	}

	for (i = 0; i < bsz; ++i) {
		for (j = i + 1; j < bsz; ++j) if (is_rectangle(bin[i], bin[j])) return true;
	}

	return false;
}

int main() {
	int n, m, i;
	scanf("%d %d", &n, &m);
	vector<pair<int, int> > B, R;
	for (i = 0; i < n; ++i) {
		int x, y;
		scanf("%d %d", &x, &y);
		B.push_back({x, y});
	}

	for (i = 0; i < m; ++i) {
		int x, y;
		scanf("%d %d", &x, &y);
		R.push_back({x, y});
	}

	b = normalize(B, -1), r = normalize(R, 1);

	if (b.size() < 2 || r.size() < 2) {
		puts("Poor Sereja!");
		return 0;
	}

	int s = 1, e = MVAL - 1, ans = 1;
	while (s <= e) {
		int mid = (s + e) / 2;
		if (is_good(mid)) e = mid - 1, ans = mid;
		else s = mid + 1;
	}

	printf("%d\n", ans);
	return 0;
}
