#include <bits/stdc++.h>
using namespace std;

const int MN = 202020;
const int MM = 505050;

int a[MN];
int f[MM];
bool id[MM];
bool have[MN];
vector<int> primes[MM];
bool notprime[MM];

void add(int x, int k) {
	int n = primes[x].size(), i, j;
	for (i = 1; i < (1 << n); ++i) {
		int m = 1;
		for (j = 0; j < n; ++j) {
			if ((i >> j) & 1) m *= primes[x][j];
		}
		f[m] += k;
	}
}

int get_count(int x) {
	int n = primes[x].size(), i, j;
	long long ret = 0;
	for (i = 1; i < (1 << n); ++i) {
		int m = 1, ctr = 0;
		for (j = 0; j < n; ++j) {
			if ((i >> j) & 1) {
				++ctr;
				m *= primes[x][j];
			}
		}
		if (ctr % 2) {
			ret += f[m];
		} else {
			ret -= f[m];
		}
	}
	return ret;
}

void get_primes() {
	int i, j;
	for (i = 2; i < MM; ++i) {
		if (!notprime[i]) {
			for (j = i; j < MM; j += i) {
				notprime[j] = true;
				if (id[j]) primes[j].push_back(i);
			}
		}
	}
}

int main() {
	int n, q, i;
	scanf("%d %d", &n, &q);

	for (i = 0; i < n; ++i) scanf("%d", a + i), id[a[i]] = true;

	get_primes();

	int ctr = 0;
	long long ans = 0;
	for (i = 0; i < q; ++i) {
		int x;
		scanf("%d", &x);
		--x;
		if (have[x]) {
			--ctr;
			add(a[x], -1);
			ans -= ctr - get_count(a[x]);
			have[x] = false;
		} else {
			ans += ctr - get_count(a[x]);
			++ctr;
			add(a[x], 1);
			have[x] = true;
		}
		cout << ans << endl;
	}
	return 0;
}
