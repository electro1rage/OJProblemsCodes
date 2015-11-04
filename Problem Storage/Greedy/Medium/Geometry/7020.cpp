/*
reality, be rent!
synapse, break!
Van!shment Th!s World !!
*/
#include <bits/stdc++.h>
using namespace std;

struct line {
	long long a, b, c;
	line& operator=(const line& x) {
		a = x.a, b = x.b, c = x.c;
		return *this;
	}
};

const int MN = 10001;

int X[MN], Y[MN];

line get_perp(int x1, int y1, int x2, int y2) {
	long long a = x2 - x1, b = y2 - y1, c = -1LL * y2 * y2 + 1LL * y2 * y1 - 1LL * x2 * x2 + 1LL * x2 * x1;
	return {a, b, c};
}

bool is_bad(line l, int x1, int y1, int x2, int y2) {
	long long fst = l.a * x1 + l.b * y1 + l.c;
	long long snd = l.a * x2 + l.b * y2 + l.c;
	if (snd == 0) return false;
	fst /= abs(fst);
	snd /= abs(snd);
	return fst == snd;
}

bool side(double x1, double y1, double x2, double y2, double x3, double y3) {
	double ret = x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2);
	return ret < 0;
}

bool bad(line l, int x1, int y1, int x2, int y2, int x, int y) {
	if (l.a * x2 + l.b * y2 + l.c == 0) return false;
	double px1 = x, py1 = y, px2, py2;
	if (l.b == 0) {
		px2 = x, py2 = y + 1;
	} else {
		px2 = x + 1, py2 = (-l.c - l.a * px2) / (double)l.b;
	}

	return side(px1, py1, px2, py2, x1, y1) == side(px1, py1, px2, py2, x2, y2);
}

int main() {
	int n;
	while (true) {
		scanf("%d", &n);
		if (!n) break;
		int i, j;
		for (i = 0; i < n; ++i) scanf("%d %d", X + i, Y + i);

		for (i = 0; i < n - 2; ++i) {
			for (j = i + 2; j < n; ++j) {
				if (bad(get_perp(X[i], Y[i], X[i + 1], Y[i + 1]), X[i], Y[i], X[j], Y[j], X[i + 1], Y[i + 1])) {
					puts("Unfair");
					goto END;
				}
			}
		}

		puts("Fair");
		END:;
	}
	return 0;
}

