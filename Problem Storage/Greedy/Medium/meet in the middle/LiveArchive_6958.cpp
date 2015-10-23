/*
reality, be rent!
synapse, break!
Van!shment Th!s World !!
*/
#include <bits/stdc++.h>
using namespace std;

long long dist[14][14];

int main() {
	int n;
	long long L;
	while (~scanf("%d %lld", &n, &L)) {
		int i, j, k;
		for (i = 0; i < n; ++i) {
			for (j = 0; j < n; ++j) scanf("%lld", &dist[i][j]);
		}
		if (n < 4) {
			vector<int> a(n);
			for (i = 0; i < n; ++i) a[i] = i;
			do {
				long long sum = dist[a[0]][a[n - 1]];
				for (i = 0; i < n - 1; ++i) sum += dist[a[i]][a[i + 1]];
				if (sum == L) {
					puts("possible");
					goto END;
				}
			} while (next_permutation(a.begin(), a.end()));
			puts("impossible");
			END:;
			continue;
		}
		--n;
		vector<int> a(n);
		for (i = 0; i < n; ++i) a[i] = i;
		for (i = 0; i < n; ++i) {
			vector<int> b, l, r;
			for (j = 0; j < n; ++j) {
				if (i == j) continue;
				b.push_back(a[j]);
			}
			int half = (n - 1) / 2;
			for (j = 0; j < (1 << (n - 1)); ++j) {
				if (__builtin_popcount(j) != half) continue;
				l.clear(), r.clear();
				for (k = 0; k < n - 1; ++k) {
					if ((j >> k) & 1) l.push_back(b[k]);
					else r.push_back(b[k]);
				}
				unordered_set<long long> fst, snd;
				int sz1 = l.size(), sz2 = r.size();
				do {
					long long sum = 0;
					for (k = 0; k < sz1 - 1; ++k) sum += dist[l[k]][l[k + 1]];
					fst.insert(sum + dist[n][l[0]] + dist[l[sz1 - 1]][a[i]]);
					snd.insert(sum + dist[a[i]][l[0]] + dist[l[sz1 - 1]][n]);
				} while (next_permutation(l.begin(), l.end()));
				do {
					long long sum1 = 0, sum2;
					for (k = 0; k < sz2 - 1; ++k) sum1 += dist[r[k]][r[k + 1]];
					sum2 = sum1;
					sum1 += dist[a[i]][r[0]] + dist[r[sz2 - 1]][n];
					sum2 += dist[n][r[0]] + dist[r[sz2 - 1]][a[i]];
					if (fst.find(L - sum1) != fst.end() || snd.find(L - sum2) != snd.end()) {
						puts("possible");
						goto END2;
					}
				} while (next_permutation(r.begin(), r.end()));
			}
		}
		puts("impossible");
		END2:;
	}
	return 0;
}
