#include <bits/stdc++.h>
using namespace std;

multiset<int> st;

int main() {
	int n, x, i, j;
	vector<int> a;
	scanf("%d", &n);
	for (i = 0; i < n * n; ++i) scanf("%d", &x), st.insert(x);
	auto it = st.end();
	--it;
	a.push_back(*it);
	st.erase(it);
	for (i = 1; i < n; ++i) {
		it = st.end();
		--it;
		int num = *it, sz = a.size();
		st.erase(it);
		for (j = 0; j < sz; ++j) {
			int gcd = __gcd(num, a[j]);
			it = st.find(gcd);
			st.erase(it);
			it = st.find(gcd);
			st.erase(it);
		}
		a.push_back(num);
	}
	for (i = 0; i < n; ++i) {
		if (i) putchar(' ');
		printf("%d", a[i]);
	}
	puts("");
	return 0;
}
