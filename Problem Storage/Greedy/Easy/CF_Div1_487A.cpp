#include <bits/stdc++.h>
using namespace std;

bool isGood(int hy, int ay, int dy, int hm, int am, int dm) {
	int dmgy = max(ay - dm, 0), dmgm = max(am - dy, 0);
	if (!dmgy) return 0;
	if (!dmgm) return 1;

	int needy = (hm + dmgy - 1) / dmgy, needm = (hy + dmgm - 1) / dmgm;
	if (needy >= needm) return 0;

	return 1;
}


int main() {
	int h, a, d, mh, ma, md;
	long long ch, ca, cd;

	cin >> h >> a >> d >> mh >> ma >> md >> ch >> ca >> cd;

	long long res = 10000000000000000LL;

	for (int i = h; i <= 9901; ++i) {
		for (int j = a; j <= 200; ++j) {
			for (int k = d; k <= 100; ++k) {
				if(isGood(i, j, k, mh, ma, md)) {
					res = min(res, (i - h) * ch + (j - a) * ca + (k - d) * cd);
					break;
				}
			}
		}
	}

	cout << res << endl;
	return 0;
}
