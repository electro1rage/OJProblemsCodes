#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)

const int MN = 300010;
const int MM = 1510;

struct line {
	int a, b, c;
	bool operator<(const line l) const {
		if (a != l.a) return a < l.a;
		if (b != l.b) return b < l.b;
		return c < l.c;
	}
};


int get_gcd(int a, int b) {
	a = abs(a), b = abs(b);
	return __gcd(a, b);
}

int get_dist(int x1, int y1, int x2, int y2) {
	return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

line normalize(int a, int b, int c) {
	int gcd = get_gcd(a, get_gcd(b, c));

	a /= gcd, b /= gcd, c /= gcd;

	int sign = 1;
	if (a < 0 || (a == 0 && b < 0)) sign = -1;

	return {a * sign, b * sign, c * sign};
}

int xc[MM], yc[MM], rc[MM];
int xf[MN], yf[MN], xs[MN], ys[MN];
int id[MN];
int n, m;
map<line, int> lineid;
vector<pair<int, int> > small[MN], big[MN];

int get_ans() {
	int curid = 0;
	for (int i = 0; i < n; ++i) {
		int x1 = xf[i], y1 = yf[i], x2 = xs[i], y2 = ys[i];
		int a = y2 - y1;
		int b = x1 - x2;
		int c = y1 * x2 - y2 * x1;

		line normal = normalize(a, b, c);
		if (!lineid.count(normal)) lineid[normal] = curid, ++curid;

		int tempid = lineid[normal];

		small[tempid].push_back({x1 * 2, y1 * 2});
		big[tempid].push_back({x2 * 2, y2 * 2});
	}

	for (int i = 0; i < curid; ++i) {
		sort(small[i].begin(), small[i].end());
		sort(big[i].begin(), big[i].end());
	}

	int ans = 0;
	for (int i = 0; i < m; ++i) {
		for (int j = i + 1; j < m; ++j) {
			if (rc[i] != rc[j]) continue;

			int r = rc[i];
			int x1 = xc[i], y1 = yc[i];
			int x2 = xc[j], y2 = yc[j];

			if (get_dist(x1, y1, x2, y2) <= 4 * r * r) continue;

			pair<int, int> midpoint{x1 + x2, y1 + y2};

			int a = x2 - x1;
			int b = y2 - y1;
			int c = -(b * (y1 + y2) + a * (x1 + x2));

			a *= 2, b *= 2;

			line normal = normalize(a, b, c);

			if (!lineid.count(normal)) continue;

			int tempid = lineid[normal];

			int total = small[tempid].size();

			int badsmall = small[tempid].end() - upper_bound(small[tempid].begin(), small[tempid].end(), midpoint);
			int badbig = lower_bound(big[tempid].begin(), big[tempid].end(), midpoint) - big[tempid].begin();

			ans += total - badsmall - badbig;
		}
	}
	return ans;
}

int main() {
	scanf("%d %d", &n, &m);

	int i;
	REP(i, n) {
		scanf("%d %d %d %d", xf + i, yf + i, xs + i, ys + i);
		if (make_pair(xf[i], yf[i]) > make_pair(xs[i], ys[i])) {
			swap(xf[i], xs[i]), swap(yf[i], ys[i]);
		}
	}

	REP(i, m) scanf("%d %d %d", xc + i, yc + i, rc + i);

	cout << get_ans() << endl;
	return 0;
}
