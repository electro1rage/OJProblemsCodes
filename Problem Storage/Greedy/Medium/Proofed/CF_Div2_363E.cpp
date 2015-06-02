#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for((i)=0;(i)<(int)(n);++(i))

const int MN = 505;
const int MVAL = 1010101010;

int grid[MN][MN];
int value[MN][MN];
pair<int, int> maxl[MN][MN];
pair<int, int> maxr[MN][MN];
pair<int, int> maxt[MN][MN];
pair<int, int> maxb[MN][MN];
vector<pair<int, int> > cl, cr;
vector<pair<int, int> > bl, br;

void get_range(vector<pair<int, int> > &a, vector<pair<int, int> > &c, vector<pair<int, int> > &b) {
	int n = a.size();
	for (int i = 1; i < n; ++i) b.push_back({-a[i].first, a[i].second});
	for (int i = 0; i < n; ++i) b.push_back(a[i]);
	sort(b.begin(), b.end());
	n = b.size();
	for (int i = 0; i < n; ++i) c.push_back({b[i].first, -b[i].second});
	a.clear();
}

pair<int, int> get_maxl(int i, int j, int n, int m) {
	if (j < 0 || i < 0 || i >= n || j >= m) return {-MVAL - 3, 0};
	return maxl[i][j];
}

void process_maxl(int n, int m) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			pair<int, int> pre = get_maxl(i, j - 1, n, m);
			if (pre.first > value[i][j]) maxl[i][j] = pre;
			else if (pre.first < value[i][j]) maxl[i][j] = {value[i][j], 1};
			else maxl[i][j] = {pre.first, pre.second + 1};
		}
	}
}

pair<int, int> get_maxr(int i, int j, int n, int m) {
	if (j >= m || i >= n || j < 0 || i < 0) return {-MVAL - 3, 0};
	return maxr[i][j];
}

void process_maxr(int n, int m) {
	for (int i = 0; i < n; ++i) {
		for (int j = m - 1; j >= 0; --j) {
			pair<int, int> pre = get_maxr(i, j + 1, n, m);
			if (pre.first > value[i][j]) maxr[i][j] = pre;
			else if (pre.first < value[i][j]) maxr[i][j] = {value[i][j], 1};
			else maxr[i][j] = {pre.first, pre.second + 1};
		}
	}
}

pair<int, int> get_maxt(int i, int j, int n, int m) {
	if (i < 0 || j < 0 || i >= n || j >= m) return {-MVAL - 3, 0};
	return maxt[i][j];
}

void process_maxt(int n, int m) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			pair<int, int> pre1 = get_maxt(i - 1, j, n, m), pre2 = get_maxt(i, j - 1, n, m), pre3 = get_maxt(i - 1, j - 1, n, m);
			int maxi = max(pre1.first, max(pre2.first, pre3.first));
			if (value[i][j] > maxi) {
				maxt[i][j] = {value[i][j], 1};
				continue;
			}
			bool good = maxi == value[i][j];
			if (pre1.first == pre2.first) {
				if (pre3.first == pre1.first) {
					maxt[i][j] = {maxi, pre1.second + pre2.second - pre3.second + good};
				} else {
					maxt[i][j] = {maxi, pre1.second + pre2.second + good};
				}
			} else {
				if (pre1 < pre2) swap(pre1, pre2);
				maxt[i][j] = {maxi, pre1.second + good};
			}
		}
	}
}

pair<int, int> get_maxb(int i, int j, int n, int m) {
	if (j < 0 || i >= n || j >= m || i < 0) return {-MVAL - 3, 0};
	return maxb[i][j];
}

void process_maxb(int n, int m) {
	for (int i = n - 1; i >= 0; --i) {
		for (int j = 0; j < m; ++j) {
			pair<int, int> pre1 = get_maxb(i + 1, j, n, m), pre2 = get_maxb(i, j - 1, n, m), pre3 = get_maxb(i + 1, j - 1, n, m);
			int maxi = max(pre1.first, max(pre2.first, pre3.first));
			if (value[i][j] > maxi) {
				maxb[i][j] = {value[i][j], 1};
				continue;
			}
			bool good = value[i][j] == maxi;
			if (pre1.first == pre2.first) {
				if (pre3.first == pre1.first) {
					maxb[i][j] = {maxi, pre1.second + pre2.second - pre3.second + good};
				} else {
					maxb[i][j] = {maxi, pre1.second + pre2.second + good};
				}
			} else {
				if (pre1 < pre2) swap(pre1, pre2);
				maxb[i][j] = {maxi, pre1.second + good};
			}
		}
	}
}

void get_cvalues(int n, int m, int R) {
	int sz = cl.size();
	for (int i = R; i < n - R; ++i) {
		int sum = 0;
		int x = i, y = R;
		vector<pair<int, int> > l = cl, r = cr;
		for (int j = 0; j < sz; ++j) l[j].first += x, l[j].second += y, r[j].first += x, r[j].second += y;
		for (int j = 0; j < sz; ++j) {
			for (int k = l[j].second; k <= r[j].second; ++k) {
				sum += grid[l[j].first][k];
			}
		}
		value[x][y] = sum;
		for (int j = y + 1; j < m - R; ++j) {
			for (int k = 0; k < sz; ++k) sum -= grid[l[k].first][l[k].second], ++l[k].second;
			for (int k = 0; k < sz; ++k) ++r[k].second, sum += grid[r[k].first][r[k].second];
			value[x][j] = sum;
		}
	}
}

pair<int, long long> get_ans(int n, int m, int R) {
	int sz = bl.size();
	pair<int, long long> ret = {-MVAL, 0};
	for (int i = R; i < n - R; ++i) {
		int x = i, y = R;
		vector<pair<int, int> > l = bl, r = br;
		for (int j = 0; j < sz; ++j) l[j].first += x, l[j].second += y, r[j].first += x, r[j].second += y;
		for (int j = y; j < m - R; ++j) {
			int maxi = get_maxt(l[0].first - 1, m - 1, n, m).first;
			maxi = max(maxi, get_maxb(l[sz - 1].first + 1, m - 1, n, m).first);
			for (int k = 0; k < sz; ++k) {
				maxi = max(maxi, get_maxl(l[k].first, l[k].second - 1, n, m).first);
				maxi = max(maxi, get_maxr(r[k].first, r[k].second + 1, n, m).first);
			}

			int ctr = 0;
			pair<int, int> cur = get_maxt(l[0].first - 1, m - 1, n, m);
			if (cur.first == maxi) ctr += cur.second;
			cur = get_maxb(l[sz - 1].first + 1, m - 1, n, m);
			if (cur.first == maxi) ctr += cur.second;
			for (int k = 0; k < sz; ++k) {
				cur = get_maxl(l[k].first, l[k].second - 1, n, m);
				if (cur.first == maxi) ctr += cur.second;
				cur = get_maxr(r[k].first, r[k].second + 1, n, m);
				if (cur.first == maxi) ctr += cur.second;
				++l[k].second, ++r[k].second;
			}

			if (maxi + value[i][j] < ret.first) continue;

			if (maxi + value[i][j] > ret.first) {
				ret = {maxi + value[i][j], ctr};
			} else {
				ret.second += ctr;
			}
		}

	}
	return ret;
}

int main() {
	int n, m, r, i, j, k, l;
	scanf("%d %d %d", &n, &m, &r);

	if (2 * r + 1 + r > max(n, m)) {
		printf("0 0");
		return 0;
	}

	REP(i, r + 1) REP(j, r + 1) {
		if (i * i + j * j <= r * r) grid[i][j] = 1;
	}

	vector<pair<int, int> > a;
	for (int i = 0; i < r + 1; ++i) {
		for (int j = r; j >= 0; --j) {
			if (grid[i][j]) {
				a.push_back({i, j});
				break;
			}
		}
	}

	get_range(a, cl, cr);

	REP(i, r + 1) REP(j, r + 1) {
		if (grid[i][j] != 1) continue;
		REP(k, r + 1) REP(l, r + 1) {
			int x = i + k, y = j + l;
			if (k * k + l * l <= r * r && grid[x][y] != 1) grid[x][y] = 2;
		}
	}

	for (int i = 0; i < 2 * r + 3; ++i) {
		for (int j = 2 * r + 2; j >= 0; --j) {
			if (grid[i][j]) {
				a.push_back({i, j});
				break;
			}
		}
	}

	get_range(a, bl, br);

	REP(i, n) REP(j, m) scanf("%d", &grid[i][j]), value[i][j] = -MVAL;

	get_cvalues(n, m, r);

	process_maxl(n, m);
	process_maxr(n, m);
	process_maxt(n, m);
	process_maxb(n, m);

	pair<int, long long> ans = get_ans(n, m, r);
	if (ans.first < 0) {
		printf("0 0\n");
		return 0;
	}
	cout << ans.first << ' ' << ans.second / 2 << endl;
	return 0;
}
