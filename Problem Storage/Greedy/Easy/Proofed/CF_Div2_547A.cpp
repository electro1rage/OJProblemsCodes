#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for((i)=0;(i)<(int)(n);++(i))

const int MN = 1000010;

bool vst[MN];

vector<int> aa;
vector<int> bb;
vector<int> x;

long long get_lcm(long long a, long long b) {
	return a / __gcd(a, b) * b;
}

int main() {
	int M;
	scanf("%d", &M);

	int h1, a1;
	scanf("%d %d", &h1, &a1);

	int x1, y1;
	scanf("%d %d", &x1, &y1);

	int h2, a2;
	scanf("%d %d", &h2, &a2);

	int x2, y2;
	scanf("%d %d", &x2, &y2);


	int i;
	REP(i, M + 1) aa.push_back(h1), h1 = (1LL * x1 * h1 + y1) % M;
	REP(i, M + 1) bb.push_back(h2), h2 = (1LL * x2 * h2 + y2) % M;

	REP(i, M + 1) {
		if (aa[i] == a1 && bb[i] == a2) {
			cout << i << endl;
			return 0;
		}
	}

	int ca = 0, cb = 0, a, b;

	for (i = M; i >= 0; --i) {
		if (aa[i] == aa[M] && i != M) break;
		x.push_back(aa[i]);
	}

	reverse(x.begin(), x.end());

	ca = x.size(), a = find(x.begin(), x.end(), a1) - x.begin();

	x.clear();
	for (i = M; i >= 0; --i) {
		if (bb[i] == bb[M] && i != M) break;
		x.push_back(bb[i]);
	}

	reverse(x.begin(), x.end());

	cb = x.size(), b = find(x.begin(), x.end(), a2) - x.begin();

	if (a == ca || b == cb) {
		puts("-1");
		return 0;
	}

	long long lcm = get_lcm(ca, cb);
	long long ans = a;

	while (ans < lcm) {
		if (ans % cb == b) {
			cout << ans + M + 1 << endl;
			return 0;
		}

		ans += ca;
	}

	puts("-1");
	return 0;
}
