#include <bits/stdc++.h>
using namespace std;

vector<int> q;
vector<int> m;
int plen, forstep, revstep;
int n, k;

int lcm(int a, int b) {
	return a / __gcd(a, b) * b;
}

void go1() {
	vector<int> p(n + 1);
	vector<int> a(n + 1);

	for (int i = 1; i <= n; ++i) {
		p[i] = i;
		a[i] = i;
	}

	bool first = 1;
	int len = 0;
	while ((p != a || first) && len < k) {
		++len;
		first = 0;
		vector<int> temp(n + 1);
		for (int i = 1; i <= n; ++i) {
			temp[i] = p[q[i]];
		}
		p = temp;
		if (p == m) {
			forstep = len;
		}
	}
}

void go2() {
	vector<int> p(n + 1);
	vector<int> a(n + 1);

	for (int i = 1; i <= n; ++i) {
		p[i] = i;
		a[i] = i;
	}

	bool first = 1;
	int len = 0;
	while ((p != a || first) && len < k) {
		first = 0;
		++len;
		vector<int> temp(n + 1);
		for (int i = 1; i <= n; ++i) {
			temp[q[i]] = p[i];
		}
		p = temp;
		if (p == m) {
			revstep = len;
		}
	}
}

void go3() {
	bool vst[105] = { };
	plen = 1;
	for (int i = 1; i <= n; ++i) {
		if (vst[i]) continue;
		int ind = i;
		int ctr = 1;
		while (q[ind] != i) {
			ind = q[ind];
			++ctr;
			vst[ind] = 1;
		}
		plen = lcm(plen, ctr);
	}
}

int main() {
	scanf("%d %d", &n, &k);

	q.resize(n + 1);
	m.resize(n + 1);

	for (int i = 1; i <= n; ++i)
		scanf("%d", &q[i]);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &m[i]);

	bool bad = 1;
	for (int i = 1; i <= n; ++i) {
		if (m[i] != i) bad = 0;
	}

	if (bad) {
		puts("NO");
		return 0;
	}

	bad = 1;
	for (int i = 1; i <= n; ++i) {
		if (q[i] != i) bad = 0;
	}

	if (bad) {
		puts("NO");
		return 0;
	}

	go1();
	go2();
	go3();

	if (!forstep && !revstep) {
		puts("NO");
		return 0;
	}

	if (plen == 2) {
		if (k != 1) puts("NO");
		else puts("YES");
		return 0;
	}

	if ((forstep && k >= forstep && (k - forstep) % 2 == 0) || (revstep && k >= revstep && (k - revstep) % 2 == 0)) {
		puts("YES");
		return 0;
	}

	puts("NO");
	return 0;
}

